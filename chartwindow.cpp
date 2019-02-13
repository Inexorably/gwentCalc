#include "chartwindow.h"
#include "ui_chartwindow.h"

ChartWindow::ChartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartWindow)
{
    ui->setupUi(this);

    series = new QLineSeries();
    for (int i = 1; i < 10; i++)
        series->append(i,i);

    chart = new QChart();
    chart->addSeries(series);

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
    chartView = new QChartView(chart);
    ui->gridLayout->addWidget(chartView);
}

ChartWindow::~ChartWindow()
{
    delete ui;
}

void ChartWindow::on_pushButton_clicked(){
    series->append(11,11);
    qDebug() << series->count();
    //chart->axisX()->setMax(12);
    chart->axes(Qt::Horizontal).back()->setMax(12);
    //chart->axisY()->setMax(12);
    chart->axes(Qt::Vertical).back()->setMax(12);

    //chartView->repaint();

}
