#ifndef ANALYSISWINDOW_H
#define ANALYSISWINDOW_H

#include "gwentsimresults.h"
#include "gwentcard.h"

#include <algorithm>

#include <QMainWindow>
#include <QDebug>
#include <QPointF>

namespace Ui {
class AnalysisWindow;
}

class AnalysisWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnalysisWindow(QWidget *parent = nullptr);
    AnalysisWindow(const QString &f, GwentSimResults &r, QWidget *parent = nullptr); //&r non const so we can modify individualTracker.
    ~AnalysisWindow();

private slots:
    void on_actionScore_vs_Round_Length_changed();

    void on_actionScore_per_Card_vs_Round_Length_changed();

    void on_combosTimesPlayed_changed();

    void on_actionAverage_Combo_Value_changed();

    void on_actionTimes_Card_Mulliganed_changed();

    void on_actionTimes_Card_Played_changed();

private:
    Ui::AnalysisWindow *ui;
    QString filename;

    //Chart members.
    QChartView *chartViewScoresVsTurns;
    QChartView *chartViewScoresPerCardVsTurns;
    QChartView *chartViewCombosTimesPlayed;
    QChartView *chartViewCombosAverageValue;
    QChartView *chartViewIndividualTimesMulliganed;
    QChartView *chartViewIndividualTimesPlayed;

    //Sorting functions for results.individualTracker.
    //https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects.  Used this because I already overloaded <.
    struct compareTimesMulliganed{
        inline bool operator() (GwentCard &a, GwentCard &b){
            return a.timesMulliganed < b.timesMulliganed;
        }
    };
    struct compareTimesPlayed{
        inline bool operator() (GwentCard &a, GwentCard &b){
            return a.timesPlayed < b.timesPlayed;
        }
    };

    //Temp bubble sort.  TODO: Remove?  Obselete.
    void sortByIndividualTimesPlayed(std::vector<GwentCard> &v);

};

#endif // ANALYSISWINDOW_H
