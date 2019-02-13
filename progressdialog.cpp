#include "progressdialog.h"
#include "ui_progressdialog.h"

void ProgressDialog::appendPoint(const qreal &x, const qreal &y){
    series->append(x,y);
    //If points are out of bounds, add them to plot.
    if (x + 10 > xMax){
        xMax = x + 10;
        chart->axisX()->setMax(xMax);
    }

    if (y + 10 > yMax){
        yMax = y + 10;
        chart->axisY()->setMax(yMax);
    }

    if (y - 10 < yMin){
        yMin = y - 10;
        chart->axisY()->setMin(yMin);
    }
}

ProgressDialog::ProgressDialog(const QString &f, const std::vector<GwentCard> &deckTemp, const std::vector<GwentCardCombo> &combosTemp, QWidget *parent) :
    QDialog(parent), filename(f),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);

    //*************************************Testing***********************************************
    xMax = -1;
    yMax = -1;
    //xMin = -1;
    yMin = 999999;  //Initialise to some high value so we can compare with < to setMin and scale in r-t.

    series = new QLineSeries();

    chart = new QChart();
    chart->addSeries(series);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Average Score");
    axisY->setLabelFormat("%i");
    axisY->setTickCount(10);
    axisY->setMinorTickCount(-1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QLogValueAxis *axisX = new QLogValueAxis();
    axisX->setTitleText("Iterations");
    axisX->setLabelFormat("%g");
    axisX->setBase(10.0);
    axisX->setMinorTickCount(-1);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Same formatting
    chart->setBackgroundVisible(false);
    chart->setMargins(QMargins(0,0,0,0));
    chart->layout()->setContentsMargins(0,0,0,0);
    chart->legend()->hide();
    chart->setPlotAreaBackgroundBrush(QBrush(Qt::white));
    chart->setPlotAreaBackgroundVisible(true);
    chartView = new QChartView(chart);
    ui->gridLayout->addWidget(chartView);

    //*************************************Testing***********************************************

    this->setWindowTitle("Running simulation: " + filename);
    ui->label->hide();
    ui->label->setAlignment(Qt::AlignCenter);

    deck = deckTemp;
    combos = combosTemp;

    GwentScenario pkg(deck, combos);

    //Begin worker thread for simulations.  Initalize, and then call start which calls run().
    sim = new SimThread(pkg);

    //Connect the signal for updating the progress bar to the signals emited by the thread.
    connect(sim, SIGNAL(percentChanged(int)), ui->progressBar, SLOT(setValue(int)));
    connect(sim, SIGNAL(pIterationsChanged(QString)), ui->label, SLOT(setText(QString)));

    //Connect other relevant signals.
    connect(sim, SIGNAL(hideProgressBar()), ui->progressBar, SLOT(hide()));
    connect(sim, SIGNAL(showLabel()), ui->label, SLOT(show()));

    //***********************************Testing***********************************
    //Plotting

    //Update the series whenever we emit a signal.
    qDebug() << "Attempting connection";
    connect(sim, SIGNAL(plotPoint(qreal,qreal)), this, SLOT(appendPoint(qreal,qreal)));
    //connect(sim, &SimThread::plotPoint, series, &QLineSeries::append);
    qDebug() << "Connected";
    //***********************************Testing***********************************



    //Call start() which calls run().
    sim->start();

    //Close on completion of sim.
    connect(sim, SIGNAL(simulationComplete()), this, SLOT(close()));
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}

void ProgressDialog::on_pushButton_clicked(){
    sim->stop();
    close();
}
