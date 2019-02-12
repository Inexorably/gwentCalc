#include "simthread.h"
#include "globals.h"
#include <QtCore>
#include "QProgressBar"
#include "globals.h"

#include <QDebug>

//Plagurising my code that I wrote the last time I remember using QThreads (2016, it's been a while).
//https://github.com/Inexorably/Hearthstone-Conquest-Sim/blob/master/simthread.cpp

SimThread::SimThread(const GwentScenario &gs) : pkg(gs){
    stopBool = false;

    //Initalise based on the settings in gwentCalc.set.
    QString data;
    QFile infile(SETTINGSFILENAME);
    QStringList settingsList;

    if (infile.open(QFile::ReadOnly)){
        data = infile.readAll();
        settingsList = data.split("\n");
        infile.close();
    }

    multithread = static_cast<bool>(settingsList[0].toInt());
    nChecked = static_cast<bool>(settingsList[1].toInt());
    n = settingsList[2].toInt();
    pChecked = static_cast<bool>(settingsList[3].toInt());
    p = settingsList[4].toDouble();

}
/*
void SimThread::percentChanged(int num){
    return;
}*/

void SimThread::stop(){
    stopBool = true;
}

void SimThread::shuffle(std::vector<GwentCard> &v){
    static auto rng = std::default_random_engine {};
    std::shuffle(std::begin(v), std::end(v), rng);
}

bool SimThread::trueWithProbability(const double &prob){
    static std::mt19937 rand_engine;
    static std::bernoulli_distribution d(prob);
    return d(rand_engine);

}

int SimThread::randomInt(const double &min, const double &max){
    static std::random_device randDev;
    static std::mt19937 twister(randDev());
    static std::uniform_int_distribution<int> dist;

    dist.param(std::uniform_int_distribution<int>::param_type(static_cast<int>(min), static_cast<int>(max)));
    return dist(twister);
}

void SimThread::run(){
    //Implementing iteration based run first.

    //The current progress, varies [0 100].
    //int prog = 0;
    //Update the progress bar every 1%.
    int onePercent = n/100;

    //Create the base GwentGame to reload every loop / simulation iteration, and sort the combos vector for efficiency reasons in the simul function.
    GwentGame baseGame = GwentGame(pkg);
    std::sort(pkg.combos.begin(), pkg.combos.end());
    std::reverse(pkg.combos.begin(), pkg.combos.end());    //Order from greatest to least.

    //Store the simulation results.  Have a member int n which tracks number of simulations, so we can merge the iteration
    //simulation result (n = 1) with the overall storage result (which could be quite large).
    GwentSimResults results;

    for (int g = 0; g < n; g++){
        //I have no idea what this is for, this is a remnant of old code (see above github link).
        //Avoid crashing.
        QMutex mutex;
        mutex.lock();
        if (stopBool)
            break;
        mutex.unlock();

        //Run the simulation and track the results.
        results.merge(simulate(baseGame));



        if (true || g % onePercent == 0){
            emit percentChanged(static_cast<double>(g)/n*100);
        }
    }

    //Done.
    emit percentChanged(100);

    //We will update the results to the table now.
    emit runComplete(1);

}

GwentSimResults SimThread::simulate(GwentGame game){
    GwentSimResults results;

    //Shuffle the deck before drawing first 10 cards.  Preferable to have rng based functions in simthread class so we can
    //use static random objects and avoid expensive rng object construction on each creation and destruction by the copy constructor in simul loop.
    shuffle(game.deck);
    game.draw(10);

    //Loop two or three times (based on first or second, 50% chance).
    //Find the lowest unconditionalPoints card.  If it is part of a completed combo in hand, find the next lowest.
    //I.e find the lowest conditionalPoints card in hand that is not part of a completed combo.
        //Draw another card and then mulligan the selected card back into the deck.
    int initialMulligans = 2;
    if (trueWithProbability(0.5)){
        initialMulligans = 3;
    }
    //We would like to sort from lowest to highest by unconditionalPoints for this approach.
    //<operator is overloaded in GwentCard to compare unconditionalPoints.
    std::sort(game.hand.begin(), game.hand.end());
    for (int i = 0; i < initialMulligans; ++i){
        //Hand is sorted from lowest to highest.  If card is part of completed combo continue, else break.
        for (size_t j = 0; j < game.hand.size(); ++j){
            bool mulliganSelectedCard = true;
            //Loop through combos and check if game.hand[j] is not part of a completed combo.  If it is not, break.
            //Combos are sorted from highest to lowest point values.
            for (size_t k = 0; k < game.combos.size(); ++k){
                //We are now iterating through each combo.  Loop through and see if game.hand[j] is in the combo.  If so, check for all other combo pieces.
                //If all other combo pieces are in hand, set mulliganSelectedCard to false.
                for (size_t x = 0; x < game.combos[k].cards.size(); ++x){
                    bool deadCombo = false;
                    if (game.combos[k].cards[x].name == game.hand[j].name){
                        for (size_t y = 0; y < game.combos[k].cards.size() && !deadCombo; ++y){
                            //Check the hand to see if the yth combo card is in hand.  If it is not, break.
                            for (size_t z = 0; z < game.hand.size(); ++z){
                                if (game.hand[z].name == game.combos[k].cards[y].name){
                                    break;
                                }
                                if (z + 1 == game.hand.size()){
                                    deadCombo = true;
                                }
                            }
                        }
                    }
                    //If the deadCombo is false (meaning that this is a live combo using game.hand[j]) then remove all the pieces of this combo from hand.
                    //store them in a temp std::vector<GwentCard> variable so we can add them back to hand next time.
                    if (!deadCombo){
                        for (size_t y = 0; y < game.combos[k].cards.size(); ++y){
                            //Remove cards from hand that are in the combo and store them on the temp vector.
                        }
                    }
                }
            }
        }
    }





    return results;

}
