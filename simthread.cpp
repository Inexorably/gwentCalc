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

bool SimThread::isSubset(const std::vector<GwentCard> &sub, const std::vector<GwentCard> &super){
    if (sub.size() > super.size()){
        return false;
    }

    //Check each member of the subset.
    for (size_t i = 0; i < sub.size(); ++i){
        //For each member of the subset, check if it exists in the superset.  If it does not exist in the super set, return false.
        for (size_t j = 0; j < super.size(); ++j){
            //Once we that sub[i] exists in super, we continue to the next ++i.
            if (sub[i].name == super[j].name){
                break;
            }
            if (j + 1 == super.size()){
                return false;
            }
        }
    }

    return true;

}

void SimThread::removeCard(const GwentCard &c, std::vector<GwentCard> &v){
    for (size_t i = 0; i < v.size(); ++i){
        if (v[i].name == c.name){
            v.erase(v.begin()+static_cast<int>(i));
            return;
        }
    }
}

//Note: Garauntee that combos are sorted in order from greatest to least.
void SimThread::mulligan(GwentGame &game, const int initialMulligans){
    //Sort the combos.  TODO: Combo sort inefficient?
    std::sort(game.combos.begin(), game.combos.end());
    std::reverse(game.combos.begin(), game.combos.end());

    //Can't mulligan with an empty deck or hand.
    if (game.deck.empty() || game.hand.empty()){
        return;
    }
    //I am retarded.  Just check all combos that are valid subsets (combos are ordered from greatest to least).  Remove from game.hand until no more valid subsets exist.
    //If game.hand.empty(), exist mulligan phase.
    //If at least one element left in game.hand, mulligan the first card in hand (ordered from least to most unconditionalPoints), increment usedMulligans.  Re-enter loop if mulligans remain.
    std::vector<GwentCard> comboPiecesInHand;   //The combo pieces we don't want to mulligan.
    for (int usedMulligans = 0; usedMulligans < initialMulligans; ++usedMulligans){
        //Ensure hand is least to greatest.
        std::sort(game.hand.begin(), game.hand.end());

        //Remove all combo subsets from the game.hand superset.
        for (size_t i = 0; i < game.combos.size(); ++i){
            if (isSubset(game.combos[i].cards, game.hand)){
                //If the combo is a subset, remove all components from the hand, and store them temporarily in the comboPiecesInHand vector.
                for (size_t j = 0; j < game.combos[i].cards.size(); ++j){
                    comboPiecesInHand.push_back(game.combos[i].cards[j]);
                    removeCard(game.combos[i].cards[j], game.hand);
                }
            }
        }
        //All valid combo subsets have been removed from the superset game.hand.  Make sure that game.hand is not empty.
        if (game.hand.empty()){
            std::sort(game.hand.begin(), game.hand.end());
            return;
        }
        //Mulligan the first card in hand, and increment usedMulligans (in loop condition now).
        //Take the card out of hand, draw a card, put the card back in deck and shuffle.  Add the comboPiecesInHand back into game.hand, and clear().
        GwentCard temp = game.hand.front();
        game.hand.erase(game.hand.begin());
        game.draw(1);
        game.deck.push_back(temp);
        shuffle(game.deck);
        for (size_t i = 0; i < comboPiecesInHand.size(); ++i){
            game.hand.push_back(comboPiecesInHand[i]);
        }
        comboPiecesInHand.clear();
    }
    std::sort(game.hand.begin(), game.hand.end());
    return;
}

void SimThread::printCards(const std::vector<GwentCard> &v){
    QString temp;
    for (size_t i = 0; i < v.size(); ++i){
        temp += v[i].name + ", ";
    }
    qDebug() << temp;
}

GwentSimResults SimThread::simulate(GwentGame game){
    //Initialise the struct holding our results for this simulation.
    GwentSimResults results;

    //**************************************************************************************************************************************
    //************************************************Round 1*******************************************************************************
    //**************************************************************************************************************************************

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

    //Conduct mulligans.
    mulligan(game, initialMulligans);

    //We have now mulliganned.  Play out the cards according to turn length.
    //Figure out how long this round will be.
    int r1Turns = game.r1BaseTurns;
    if (game.turnVariationBool){
        r1Turns += game.turnVariationInt;
    }




    return results;

}
