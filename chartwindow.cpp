#include "chartwindow.h"
#include "ui_chartwindow.h"

ChartWindow::ChartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartWindow)
{
    ui->setupUi(this);

    series1 = new QLineSeries();
    series2 = new QLineSeries();
    for (int i = 1; i < 10; i++){
        series1->append(i,i);
        series2->append(i+1,i+1);
    }

    chart = new QChart();
    chart->addSeries(series1);
    chart->addSeries(series2);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Data point");
    axisX->setLabelFormat("%i");
    axisX->setTickCount(series1->count());
    chart->addAxis(axisX, Qt::AlignBottom);
    series1->attachAxis(axisX);
    series2->attachAxis(axisX);

    QLogValueAxis *axisY = new QLogValueAxis();
    axisY->setTitleText("Values");
    axisY->setLabelFormat("%g");
    axisY->setBase(8.0);
    axisY->setMinorTickCount(-1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series1->attachAxis(axisY);
    series2->attachAxis(axisY);

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
    series1->append(11,11);
    qDebug() << series1->count();
    //chart->axisX()->setMax(12);
    chart->axes(Qt::Horizontal).back()->setMax(12);
    //chart->axisY()->setMax(12);
    chart->axes(Qt::Vertical).back()->setMax(12);

    //chartView->repaint();

}
