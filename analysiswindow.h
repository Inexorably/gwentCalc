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
    AnalysisWindow(const GwentSimResults &g, QWidget *parent = nullptr);
    ~AnalysisWindow();

private:
    Ui::AnalysisWindow *ui;
};

#endif // ANALYSISWINDOW_H
