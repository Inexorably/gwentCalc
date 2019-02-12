#include "chartwindow.h"
#include "ui_chartwindow.h"

ChartWindow::ChartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartWindow)
{
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
}

ChartWindow::~ChartWindow()
{
    delete ui;
}
