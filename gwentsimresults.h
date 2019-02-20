#ifndef GWENTSIMRESULTS_H
#define GWENTSIMRESULTS_H

#include<QMetaType>
#include <QtCharts>

#include "gwentcardcombo.h"

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

    //Track factors on a card not combo level -- such as card.timesPlayed and card.timesMulliganed.
    std::vector<GwentCard> individualTracker;

    //Store a copy of the combo vector which has been updated on the .occurences level.  Don't process the QBarCharts in SimThread because requires deep copy because of pointers.
    std::vector<GwentCardCombo> combos;

    //Base implementation complete.  Now spam metrics.
    //Scores based on round, x is cards played and y is score.
    QList<QPointF> roundOneScores;
    QList<QPointF> roundTwoScores;
    QList<QPointF> roundThreeScores;

    //roundScore/roundTurns vs turn series for each round.
    QList<QPointF> roundOneRatios;
    QList<QPointF> roundTwoRatios;
    QList<QPointF> roundThreeRatios;

    //We also want to have small lists of [turns, averaged scores] for each round.
    QList<QPointF> roundOneScoresVsTurns;
    QList<QPointF> roundTwoScoresVsTurns;
    QList<QPointF> roundThreeScoresVsTurns;

    //The derivative of roundOneScoresVsTurns wrt turns is the average value of each card vs turn length.
    QList<QPointF> roundOneScoresPerCardVsTurns;
    QList<QPointF> roundTwoScoresPerCardVsTurns;
    QList<QPointF> roundThreeScoresPerCardVsTurns;

};

Q_DECLARE_METATYPE(GwentSimResults)

#endif // GWENTSIMRESULTS_H
