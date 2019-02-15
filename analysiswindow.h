#ifndef ANALYSISWINDOW_H
#define ANALYSISWINDOW_H

#include "gwentsimresults.h"

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class AnalysisWindow;
}

class AnalysisWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnalysisWindow(QWidget *parent = nullptr);
    AnalysisWindow(const QString &f, const GwentSimResults &r, QWidget *parent = nullptr);
    ~AnalysisWindow();

private slots:
    void on_actionScore_vs_Round_Length_changed();

private:
    Ui::AnalysisWindow *ui;
    QString filename;

    //Chart members.
    QChartView *chartViewScoresVsTurns;
    QChartView *chartViewScoresPerCardVsTurns;
};

#endif // ANALYSISWINDOW_H
