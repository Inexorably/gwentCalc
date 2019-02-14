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

private:
    Ui::AnalysisWindow *ui;
    QString filename;
};

#endif // ANALYSISWINDOW_H
