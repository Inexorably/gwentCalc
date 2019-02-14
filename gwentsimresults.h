#ifndef GWENTSIMRESULTS_H
#define GWENTSIMRESULTS_H

#include<QMetaType>
#include <QtCharts>

#include <vector>

//A class to hold the results we want to return from the simulator.

class GwentSimResults
{
public:
    GwentSimResults();

    void merge(const GwentSimResults &i);   //Merge the simulation results of i and *this.
    double score() const;

    int n;
    int scoreSum;   //Division is expensive, so we don't want to do (n*scoreSum+i.n*i.scoreSum)/(n+i.n) every loop iteration.  We can just make the division a function to be called whenever we need it.

    //Base implementation complete.  Now spam metrics.
    //Scores based on round, x is cards played and y is score.
    QList<QPointF> roundOneScores;
    QList<QPointF> roundTwoScores;
    QList<QPointF> roundThreeScores;
};

Q_DECLARE_METATYPE(GwentSimResults)

#endif // GWENTSIMRESULTS_H
