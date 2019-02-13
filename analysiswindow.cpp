#include "analysiswindow.h"
#include "ui_analysiswindow.h"

AnalysisWindow::AnalysisWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalysisWindow)
{
    ui->setupUi(this);
    qDebug() << "AnalysisWindow::AnalysisWindow(QWidget *parent): Constructor called without GwentSimResults argument.";

}

AnalysisWindow::AnalysisWindow(const GwentSimResults &r, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnalysisWindow)
{
    ui->setupUi(this);

    //***********************************************************************************
    //**************Post Processing / Plotting Section***********************************
    //***********************************************************************************

    //**************Score vs Turns for each round****************************************
    QLineSeries *series = new QLineSeries();

    QChart *chart = new QChart();
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
    QChartView *chartView = new QChartView(chart);
    ui->gridLayout->addWidget(chartView);
}

AnalysisWindow::~AnalysisWindow()
{
    delete ui;
}
