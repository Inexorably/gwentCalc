#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QMainWindow>
#include <QtCharts>

//A real-time chart window class to allow us to show the convergence of multiple simulations at once.

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

    QLineSeries *series;
    QChart *chart;
    QChartView *chartView;
};

#endif // CHARTWINDOW_H
