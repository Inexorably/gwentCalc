#include "progressdialog.h"
#include "ui_progressdialog.h"

ProgressDialog::ProgressDialog(const QString &f, const std::vector<GwentCard> &deckTemp, const std::vector<GwentCardCombo> &combosTemp, QWidget *parent) :
    QDialog(parent), filename(f),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);

    //*************************************Testing***********************************************
    ui->setupUi(this);

    QLineSeries *series = new QLineSeries();
    for (int i = 1; i < 10; i++)
        series->append(i,i);
    QLineSeries *seriesB = new QLineSeries();
    for (int i = 1; i < 10; i++)
        seriesB->append(i, 3);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(seriesB);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Data point");
    axisX->setLabelFormat("%i");
    axisX->setTickCount(series->count());
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QLogValueAxis *axisY = new QLogValueAxis();
    axisY->setTitleText("Values");
    axisY->setLabelFormat("%g");
    axisY->setBase(8.0);
    axisY->setMinorTickCount(-1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Same formatting
    chart->setBackgroundVisible(false);
    chart->setMargins(QMargins(0,0,0,0));
    chart->layout()->setContentsMargins(0,0,0,0);
    //chart->legend()->hide();
    chart->setPlotAreaBackgroundBrush(QBrush(Qt::white));
    chart->setPlotAreaBackgroundVisible(true);
    QChartView *chartView = new QChartView(chart);
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
