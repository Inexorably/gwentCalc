#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QMainWindow>
#include <QtCharts>

namespace Ui {
class ChartWindow;
}

class ChartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChartWindow(QWidget *parent = nullptr);
    ~ChartWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChartWindow *ui;

    QLineSeries *series1;
    QLineSeries *series2;
    QChart *chart;
    QChartView *chartView;
};

#endif // CHARTWINDOW_H
