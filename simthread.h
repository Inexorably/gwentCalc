#ifndef SIMTHREAD_H
#define SIMTHREAD_H

#include "gwentscenario.h"
#include "gwentgame.h"
#include "gwentsimresults.h"
#include "dialog.h"

#include <QtCore>
#include <QtMath>
#include <QtCharts>

#include <algorithm>
#include <random>
#include <vector>

//Stealing this from my Hearthstone Conquest Sim as apparently I figured out how to use QThread at the time.
//Source with reference code in other files:
//https://github.com/Inexorably/Hearthstone-Conquest-Sim/blob/master/simthread.h

class SimThread :public QThread{
    Q_OBJECT

    public:

        SimThread(const GwentScenario &gs);
        void run();
        void stop();
        bool stopBool;
        GwentSimResults simulate(GwentGame game);  //Run one iteration of the simulation.  We pass a copy not by reference so we can modify it.

    private:
        //**************************Variables**************************************************
        //Run for n iterations or until relative error is acceptable.  Error is in percent (p).
        int n;
        double p;
        bool nChecked;
        bool pChecked;
        bool multithread;
        GwentScenario pkg;  //Bundled deck and combo information.
        std::vector<GwentCardCombo> combos; //So we can track the occurences of each combo over the lifetime of the SimThread object (over entire simulation).
        std::vector<GwentCard> individualTracker;   //Track variables such as card.timesPlayed or timesMulliganed that should be stored on a card level rather than a combo level.
        //*************************Helper Variables for storing GwentSimResults related info***
        QLineSeries roundOneScores; //x == number of rounds, y == score.  Updated in the playRound function.
        QLineSeries roundTwoScores; //Not copied in the merge function, because that would mean we copy full length series every merge call (every sim loop iteration).
        QLineSeries roundThreeScores;

        //TODO: Most mulliganed cards.

        //***********************Utility functions*********************************************
        int randomInt(const double &min, const double &max);
        bool isSubset(const std::vector<GwentCard> &sub, const std::vector<GwentCard> &super);
        bool trueWithProbability(const double &prob);


        //***********************Top level game relevant functions****************************
        void shuffle(std::vector<GwentCard> &v);
        void removeCard(const GwentCard &c, std::vector<GwentCard> &v);
        void mulligan(GwentGame &game, const int &initialMulligans);
        int playRound(GwentGame &game, const int &r1Turns);

        //***********************Debug related functions**************************************
        void printCards(const std::vector<GwentCard> &v);   //Print all cards to qDebug().

        //***********************Post processing related functions****************************
        void processRoundRatios(GwentSimResults &r);  //Processes the individual roundScore/roundLength series for each round and modifies the passed r.





    signals:
        void percentChanged(int);
        void simulationComplete(GwentSimResults);
        void pIterationsChanged(QString);
        void hideProgressBar();
        void showLabel();
        void hideLabel();
        void setMessageLabel(QString);
        void showProgressBar();

        void plotPoint(qreal, qreal);    //Gives an x, y point (iteration, score) to the series object.
        void refreshChart();
};

#endif // SIMTHREAD_H
