#include "simthread.h"
#include "globals.h"
#include <QtCore>
#include "QProgressBar"
#include "globals.h"

#include <QDebug>

//Plagurising my code that I wrote the last time I remember using QThreads (2016, it's been a while).
//https://github.com/Inexorably/Hearthstone-Conquest-Sim/blob/master/simthread.cpp

SimThread::SimThread(const GwentScenario &gs) : pkg(gs){
    //qDebug() <<"Creating SimThread";
    stopBool = false;
    combos = gs.combos;
    //qDebug() << combos.size();

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
    //qDebug() <<"SimThread constructor returning";
}
/*
void SimThread::percentChanged(int num){
    return;
}*/

void SimThread::stop(){
    stopBool = true;
}

void SimThread::shuffle(std::vector<GwentCard> &v){
    static auto rng = std::mt19937(std::random_device{}());
    std::shuffle(std::begin(v), std::end(v), rng);
}

bool SimThread::trueWithProbability(const double &prob){
    static std::mt19937 rand_engine(std::random_device{}());
    static std::bernoulli_distribution d(prob);
    //qDebug() << "trueWithProbability: " << d(rand_engine);
    return d(rand_engine);

}

int SimThread::randomInt(const double &min, const double &max){
    static std::random_device randDev;
    static std::mt19937 twister(randDev());
    static std::uniform_int_distribution<int> dist;

    dist.param(std::uniform_int_distribution<int>::param_type(static_cast<int>(min), static_cast<int>(max)));
    //qDebug() << "randomInt: " << dist(twister) << ", between: " << min << ", " << max;
    return dist(twister);
}

void SimThread::run(){
    //Let user know we started.
    emit setMessageLabel("Running Simulations.");

    //Create the base GwentGame to reload every loop / simulation iteration, and sort the combos vector for efficiency reasons in the simul function.
    GwentGame baseGame = GwentGame(pkg);

    //Apply the conditional settings to the game (such as bloodthirst / number of damaged enemies).


    std::sort(pkg.combos.begin(), pkg.combos.end());
    std::reverse(pkg.combos.begin(), pkg.combos.end());    //Order from greatest to least.

    //Store the simulation results.  Have a member int n which tracks number of simulations, so we can merge the iteration
    //simulation result (n = 1) with the overall storage result (which could be quite large).
    GwentSimResults results;
    //qDebug() << "Entering run()";

    //Can either run based on iterations or based on relative error.
    if (nChecked){
        //Update the progress bar every 1%.
        int ticker = n/100;
        //qDebug() << ticker;
        for (int g = 0; g < n; g++){
            //qDebug() << g << " of " << n;
            //I have no idea what this is for, this is a remnant of old code (see above github link).
            //Avoid crashing.
            QMutex mutex;
            mutex.lock();
            if (stopBool)
                break;
            mutex.unlock();

            //Run the simulation and track the results.  On initial run, make results equal to avoid initial 0 score.
            results.merge(simulate(baseGame));


            if (g == ticker || results.n < 100 /*We want to plot the initial data point.*/){
                if (g == ticker){
                    ticker += n/100;
                }
                //qDebug() << results.n << ": " << results.score();
                emit plotPoint(results.n, results.score());
                emit percentChanged(static_cast<int>((static_cast<double>(g))/n*100));
            }
        }
    }
    else if (pChecked){
        //Disable the progressBar because we don't know n and swap to display iterations.
        emit hideProgressBar();
        emit showLabel();

         //Update dialog every tick.
        int ticker = 100;


        //Keep a temp variable so we can track the result every tick and check if within error percent.
        double previousScore = 0;

        for (;;){
            //I have no idea what this is for, this is a remnant of old code (see above github link).
            //Avoid crashing.
            //Update: This does indeed prevent crashing.
            QMutex mutex;
            mutex.lock();
            if (stopBool)
                break;
            mutex.unlock();

            //Run the simulation and track the results.  On initial run, make results equal to avoid initial 0 score.
            results.merge(simulate(baseGame));



            if (results.n == ticker || results.n < 100 /*We want to plot the initial data points*/){
                ticker += 100;
                //qDebug() << results.n << ": " << results.score();
                emit pIterationsChanged("Iteration: " + QString::number(results.n));

                emit plotPoint(results.n, results.score());

                //Check if we are in acceptable error.  Prevent edge cases by requiring 100 runs.
                if (results.n > 100 && qFabs((results.score()-previousScore)/results.score()*100) < p){
                    //qDebug() << qFabs((results.score()-previousScore)/results.score()*100);
                    break;
                }
                else{
                    previousScore = results.score();
                }
            }
        }
    }
    else{
        Dialog *dialog = new Dialog("void SimThread::run(): neither nChecked nor pChecked true");
        dialog->setModal(true);
        dialog->exec();
        return;
    }

    //Return if we've broken out of a loop with stopBool, just return before post processing or emitting signals.
    QMutex mutex;
    mutex.lock();
    if (stopBool)
        return;
    mutex.unlock();

    //Done.
    emit percentChanged(100);


    //***************************Simulation Thread Post Processing**************************************
    //Let the user know we need to post process.
    emit setMessageLabel("Simulation complete.  Post Processing: ");
    emit hideLabel();


    //Compile needed data into results to submit to the progressDialog class in the main thread.

    emit setMessageLabel("Simulation complete.  Post Processing: Compiling round score / turns.");
    emit percentChanged(0);

    results.roundOneScores = roundOneScores.points();
    emit percentChanged(33);
    results.roundTwoScores = roundTwoScores.points();
    emit percentChanged(66);
    results.roundThreeScores = roundThreeScores.points();
    emit percentChanged(100);
    //qDebug() << "A";

    //We also post process a bit.  We want to show roundScore/roundTurns vs roundTurns for rounds one, two, and three.
    //Store as a QList<QPointF> for each round.  This will take a little longer because of the division and iteration requirements.
    //All of the QLineSeries are the same length.
    processRoundRatios(results);

    //We save the combos with occurence data (on the GwentCardCombo class level) so we can process in the analysis window.
    results.combos = combos;

    //***************************Post Processing Done**************************************************

    //We will update the results to the table now.
    emit setMessageLabel("Post Processing Complete.");
    //qDebug() << "Nani";
    emit simulationComplete(results);

}

void SimThread::processRoundRatios(GwentSimResults &r){
    //Store as a QList<QPointF> for each round.  This will take a little longer because of the division and iteration requirements.
    //All of the QLineSeries are the same length.
    emit setMessageLabel("Simulation complete.  Post Processing: Calculating round ratios.");
    int ticker = r.roundOneScores.count()/100;
    //For averaged score vs num turns.  See comments in loop.
    //TODO: Optimise by checking if we are row first / column first in memory.  Probably doesn't matter if random enough.
    //Probably should have encapsulated such round related stuff in a vector to iterate over.  Would have looked nicer, though this will be nicer to read when using QCharts.
    double tempRoundOneScore[20][2] = {};
    double tempRoundTwoScore[20][2] = {};
    double tempRoundThreeScore[20][2] = {};
    for (int i = 0; i < r.roundOneScores.count() && !stopBool; ++i){
        //Calculate simple ratios of points/card for each round.
        r.roundOneRatios.append(QPointF(r.roundOneScores[i].x(), r.roundOneScores[i].y()/r.roundOneScores[i].x()));
        r.roundTwoRatios.append(QPointF(r.roundTwoScores[i].x(), r.roundTwoScores[i].y()/r.roundTwoScores[i].x()));
        r.roundThreeRatios.append(QPointF(r.roundThreeScores[i].x(), r.roundThreeScores[i].y()/r.roundThreeScores[i].x()));

        //We now have QList<QPointF> objects of [x, y] [turns, ratio].
        //We also want to have small lists of [turns, averaged scores].  This would let us plot numTurns vs averageScore for each round.
        //We will accomplish this by looping through each r.roundXScores vector.  Create an array double temp[20] = {0} (may as well over allocate turns).
        //For each iteration, temp[static_cast<int>(r.roundOneScores[i].x())] += r.roundOneScores[i].y();
        //Have another similar array noting how many items we add into the previous array.
        //++temp2[....same as above...]; or just use a 2d array.
        //Note that all the roundXScore vectors are the same length, because one is created each simulate loop iteration.
        tempRoundOneScore[static_cast<int>(r.roundOneScores[i].x())][1] += r.roundOneScores[i].y();
        ++tempRoundOneScore[static_cast<int>(r.roundOneScores[i].x())][0];
        tempRoundTwoScore[static_cast<int>(r.roundTwoScores[i].x())][1] += r.roundTwoScores[i].y();
        ++tempRoundTwoScore[static_cast<int>(r.roundTwoScores[i].x())][0];
        tempRoundThreeScore[static_cast<int>(r.roundThreeScores[i].x())][1] += r.roundThreeScores[i].y();
        ++tempRoundThreeScore[static_cast<int>(r.roundThreeScores[i].x())][0];

        //Update the progress bar.
        if (i == ticker){
            ticker += r.roundOneScores.count()/100;
            emit percentChanged(static_cast<int>(static_cast<qreal>(i)/r.roundOneScores.count()*100));
        }
    }
    //We now have QList<QPointF> objects of [x, y] [turns, ratio].
    //We also have our 2d temp arrays with [round length in turns][1] == score sum and [round length...][0] == number of occurences that we had this number of turns in the respective round.
    //So, we now convert this to a QLineSeries for each round with elements [turns, average score].
    //To accomplish this, we loop through the arrays:
    for (int i = 0; i < 20 && !stopBool; ++i){
        //If we have no data points, skip it.
        if (tempRoundOneScore[i][0] >=1)
            r.roundOneScoresVsTurns.append(QPointF(i, tempRoundOneScore[i][1]/tempRoundOneScore[i][0]));
        if (tempRoundTwoScore[i][0] >=1)
            r.roundTwoScoresVsTurns.append(QPointF(i, tempRoundTwoScore[i][1]/tempRoundTwoScore[i][0]));
        if (tempRoundThreeScore[i][0] >=1)
            r.roundThreeScoresVsTurns.append(QPointF(i, tempRoundThreeScore[i][1]/tempRoundThreeScore[i][0]));
    }

    //Process the average score per card vs turns (derivative of roundXScoreVsTurns).
    //Note that the different rounds QLineSeries may be different sizes, so we need to loop through them seperately (can do maxLength(), then same loop, but meh).
    //TODO: Is casting float as int to compare to int safe in bool?  Should < error be used instead?
    for (int i = 0; i < r.roundOneScoresVsTurns.count(); ++i){
        if (static_cast<int>((r.roundOneScoresVsTurns[i].x())) != 0)
            r.roundOneScoresPerCardVsTurns.append(QPointF(r.roundOneScoresVsTurns[i].x(), r.roundOneScoresVsTurns[i].y()/r.roundOneScoresVsTurns[i].x()));
    }
    for (int i = 0; i < r.roundTwoScoresVsTurns.count(); ++i){
        if (static_cast<int>(r.roundTwoScoresVsTurns[i].x()) != 0)
            r.roundTwoScoresPerCardVsTurns.append(QPointF(r.roundTwoScoresVsTurns[i].x(), r.roundTwoScoresVsTurns[i].y()/r.roundTwoScoresVsTurns[i].x()));
    }
    for (int i = 0; i < r.roundThreeScoresVsTurns.count(); ++i){
        if (static_cast<int>(r.roundThreeScoresVsTurns[i].x()) != 0)
            r.roundThreeScoresPerCardVsTurns.append(QPointF(r.roundThreeScoresVsTurns[i].x(), r.roundThreeScoresVsTurns[i].y()/r.roundThreeScoresVsTurns[i].x()));
    }



    emit percentChanged(100);
}

bool SimThread::isSubset(const std::vector<GwentCard> &sub, const std::vector<GwentCard> &super){
    if (sub.size() > super.size()){
        return false;
    }

    //Check each member of the subset.
    for (size_t i = 0; i < sub.size(); ++i){
        //For each member of the subset, check if it exists in the superset.  If it does not exist in the super set, return false.
        for (size_t j = 0; j < super.size(); ++j){
            //Once we know that sub[i] exists in super, we continue to the next ++i.
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
void SimThread::mulligan(GwentGame &game, const int &initialMulligans){
    //Track how many turns are left so that we can find the value of value per turn cards.
    int turnsLeft = static_cast<int>(game.hand.size());
    //Set the turn left on all combos.
    for (size_t t = 0; t < game.combos.size(); ++t){
        game.combos[t].turnsLeft = turnsLeft;
    }
    for (size_t tt = 0; tt < game.hand.size(); ++tt){
        game.hand[tt].turnsLeft = turnsLeft;
    }


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
            if (game.combos[i].cards.size() > 1 && isSubset(game.combos[i].cards, game.hand)){
                //If the combo is a subset, remove all components from the hand, and store them temporarily in the comboPiecesInHand vector.
                for (size_t j = 0; j < game.combos[i].cards.size(); ++j){
                    comboPiecesInHand.push_back(game.combos[i].cards[j]);
                    removeCard(game.combos[i].cards[j], game.hand);
                }
                //Lower the remaining turns so that value per turn cards become less valuable, then re-sort the hand in case of combo order value changes.
                --turnsLeft;
                //Update turns left before resorting because sorting is ordered by value which is turn dependant.
                for (size_t t = 0; t < game.combos.size(); ++t){
                    game.combos[t].turnsLeft = turnsLeft;
                }
                for (size_t tt = 0; tt < game.hand.size(); ++tt){
                    game.hand[tt].turnsLeft = turnsLeft;
                }
                //Ensure hand is least to greatest, and that combos are too.
                std::sort(game.hand.begin(), game.hand.end());
                std::sort(game.combos.begin(), game.combos.end());
                std::reverse(game.combos.begin(), game.combos.end());

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
}

int SimThread::playRound(GwentGame &game, const int &r1Turns){
    //Track how many turns are left so that we can find the value of value per turn cards.
    int turnsLeft = r1Turns;
    //Set the turn left on all combos.
    for (size_t t = 0; t < game.combos.size(); ++t){
        game.combos[t].turnsLeft = turnsLeft;
    }
    for (size_t tt = 0; tt < game.hand.size(); ++tt){
        game.hand[tt].turnsLeft = turnsLeft;
    }

    bool showqDebug = false;
    if (showqDebug)
        qDebug() << "Entering playRound(), hand: ";
    QString temp;
    for (size_t i = 0; i < game.hand.size(); ++i){
        temp += game.hand[i].name + " ";
        temp+= QString::number(game.hand[i].unconditionalPoints);
        temp+= ", ";
    }
    if (showqDebug){
        qDebug() << temp;
        qDebug() << "turns: " << r1Turns;
    }
    //This follows the same trend of mulligans function, where we play out the highest valid subset combos in order.
    //Only adjustment is that if combo.size() > remainingTurns, then we choose the next highest valid subset combo.
    //If not valid combos remain, play out the highest conditional cards in order.
    int score = 0;

    //Sort the combos.  TODO: Combo sort inefficient?
    std::sort(game.combos.begin(), game.combos.end());
    std::reverse(game.combos.begin(), game.combos.end());

    //Can't play with an empty hand.
    if (game.hand.empty()){
        if (showqDebug)
            qDebug() << "A Turns: " << r1Turns << ", " << "Score: " << score;
        return score;
    }
    //I am retarded.  Just check all combos that are valid subsets (combos are ordered from greatest to least).  Remove from game.hand until no more valid subsets exist.
    //If game.hand.empty(), exist mulligan phase.
    //If at least one element left in game.hand, mulligan the first card in hand (ordered from least to most unconditionalPoints), increment usedMulligans.  Re-enter loop if mulligans remain.
    for (int cardsPlayed = 0; cardsPlayed < r1Turns; /*++cardsPlayed*/){
        if (showqDebug){
            qDebug() << "cards played: " << cardsPlayed << ", turns: " << r1Turns;
        }

        //If hand is empty, break.
        if (game.hand.empty()){
            break;
        }

        //Ensure hand is least to greatest.
        std::sort(game.hand.begin(), game.hand.end());

        //Play all valid subset combos (which have combo.cards.size() <= r1Turns) in order from highest to greatest.
        //This loop will continue until no valid combo subsets are left, so if it is not the first cardsPlayed loop iteration then
        //we have already attempted all combos and we can skip this loop.
        for (size_t i = 0; /*cardsPlayed != 0 && */i < game.combos.size(); ++i){
            //If the combo is a valid subset and we have enough turns to play the combo.
            if (game.combos[i].cards.size() <= static_cast<size_t>(r1Turns) && isSubset(game.combos[i].cards, game.hand)){
                if (showqDebug)
                    qDebug() << "Valid combo found :" << game.combos[i].cards.size() << ", cih: " << game.hand.size() << ", value: " << game.combos[i].calculateValue();
                //If the combo is a subset, remove all components from the hand, place them in the graveyard,
                //qDebug () << r1Turns << ": " << game.combos[i].cards.size() << " cards, points: " << game.combos[i].unconditionalPoints;
                for (size_t j = 0; j < game.combos[i].cards.size(); ++j){
                    game.graveyard.push_back(game.combos[i].cards[j]);
                    removeCard(game.combos[i].cards[j], game.hand);
                }
                score += game.combos[i].calculateValue();
                cardsPlayed += game.combos[i].cards.size();
                ++combos[i].occurences;
                //Update the turnsLeft in the hand and combos.  Then sort.
                //Set the turn left on all combos.
                --turnsLeft;
                for (size_t t = 0; t < game.combos.size(); ++t){
                    game.combos[t].turnsLeft = turnsLeft;
                }
                for (size_t tt = 0; tt < game.hand.size(); ++tt){
                    game.hand[tt].turnsLeft = turnsLeft;
                }
                std::sort(game.hand.begin(), game.hand.end());
                std::sort(game.combos.begin(), game.combos.end());
                std::reverse(game.combos.begin(), game.combos.end());
                break;
            }
        }
        //Don't need to sort if hand is empty.
        if (game.hand.empty()){
            if (showqDebug){
                qDebug() << "B Turns: " << r1Turns << ", " << "Score: " << score;
                qDebug() << "Hand size: " << game.hand.size();
            }
            return score;
        }
        //We have ran out of valid combo subsets, and now we play single cards in order of unconditionalProvision.
        //game.hand is still sorted from least to greatest.  Note that cardsPlayed is incremented in the loop condition, not here.
    }
    std::sort(game.hand.begin(), game.hand.end());
    if (showqDebug)
        qDebug() << "C Turns: " << r1Turns << ", " << "Score: " << score;
    return score;
}

GwentSimResults SimThread::simulate(GwentGame game){
    bool showqDebug = false;
    //Initialise the struct holding our results for this simulation.
    if (showqDebug)
        qDebug() << "***************Entered simulate*******************";
    GwentSimResults results;
    int scoreR1 = 0;
    int scoreR2 = 0;
    int scoreR3 = 0;

    //**************************************************************************************************************************************
    //************************************************Round 1*******************************************************************************
    //**************************************************************************************************************************************
    if (showqDebug)
        qDebug() << "1 simulate: Entering round 1";
    //Shuffle the deck before drawing first 10 cards.  Preferable to have rng based functions in simthread class so we can
    //use static random objects and avoid expensive rng object construction on each creation and destruction by the copy constructor in simul loop.
    shuffle(game.deck);
    game.draw(10);


    //Loop two or three times (based on first or second, 50% chance).
    //Find the lowest unconditionalPoints card.  If it is part of a completed combo in hand, find the next lowest.
    //I.e find the lowest conditionalPoints card in hand that is not part of a completed combo.
        //Draw another card and then mulligan the selected card back into the deck.
    int mulliganInt = 2;
    if (trueWithProbability(0.5)){
        mulliganInt = 3;
    }

    //Conduct mulligans.
    if (showqDebug)
        qDebug () << "1 r1 mulligan hand size: " << game.hand.size();
    mulligan(game, mulliganInt);
    if (showqDebug)
        qDebug() << "1 post mulligan hand size: " << game.hand.size();

    //We have now mulliganned.  Play out the cards according to turn length.
    //Figure out how long this round will be.
    int r1Turns = game.r1BaseTurns;
    if (game.turnVariationBool){
        r1Turns += randomInt(-1*game.turnVariationInt, game.turnVariationInt);
        if (showqDebug)
            qDebug() << "1 Setting turns as: " << r1Turns;
    }
    if (r1Turns < 3){
        r1Turns = 3;
    }
    else if (r1Turns > 10){
        r1Turns = 10;
    }
    //qDebug() << "r1 play";
    if (showqDebug)
        qDebug() << "1 pre play hand size: " << game.hand.size();
    scoreR1 += playRound(game, r1Turns);
    if (showqDebug)
        qDebug() << "1 post play hand size: " << game.hand.size();

    //**************************************************************************************************************************************
    //************************************************Round 2*******************************************************************************
    //**************************************************************************************************************************************
    if (showqDebug)
        qDebug() << "2 simulate: Entering round 2";
    //Shuffle the deck before drawing first 10 cards.  Preferable to have rng based functions in simthread class so we can
    //use static random objects and avoid expensive rng object construction on each creation and destruction by the copy constructor in simul loop.
    shuffle(game.deck);
    game.draw(3);


    //Loop two or three times (based on first or second, 50% chance).
    //Find the lowest unconditionalPoints card.  If it is part of a completed combo in hand, find the next lowest.
    //I.e find the lowest conditionalPoints card in hand that is not part of a completed combo.
        //Draw another card and then mulligan the selected card back into the deck.
    mulliganInt = 2;

    //Conduct mulligans.
    //qDebug() << "r2 mulligan";
    if (showqDebug)
        qDebug () << "2 r2 mulligan hand size: " << game.hand.size();
    mulligan(game, mulliganInt);
    if (showqDebug)
        qDebug() << "2 post mulligan hand size: " << game.hand.size();

    //We have now mulliganned.  Play out the cards according to turn length.
    //Figure out how long this round will be.
    int r2Turns = game.r2BaseTurns;
    if (game.turnVariationBool){
        r2Turns += randomInt(-1*game.turnVariationInt, game.turnVariationInt);
        if (showqDebug)
            qDebug() << "2 Setting turns as: " << r2Turns;
    }
    if (r2Turns < 1){
        r2Turns = 1;
    }
    //TODO: Update this for round extension style cards like ciri.
    else if (r2Turns > static_cast<int>(game.hand.size())){
        r2Turns = static_cast<int>(game.hand.size());
    }
    //qDebug() << "r2 score";
    if (showqDebug)
        qDebug() << "2 pre play hand size: " << game.hand.size();
    scoreR2 += playRound(game, r2Turns);
    if (showqDebug)
        qDebug() << "2 post play hand size: " << game.hand.size();

    //**************************************************************************************************************************************
    //************************************************Round 3*******************************************************************************
    //**************************************************************************************************************************************
    if (showqDebug)
        qDebug() << "3 simulate: Entering round 3";
    //Shuffle the deck before drawing first 10 cards.  Preferable to have rng based functions in simthread class so we can
    //use static random objects and avoid expensive rng object construction on each creation and destruction by the copy constructor in simul loop.
    shuffle(game.deck);
    game.draw(3);


    //Loop two or three times (based on first or second, 50% chance).
    //Find the lowest unconditionalPoints card.  If it is part of a completed combo in hand, find the next lowest.
    //I.e find the lowest conditionalPoints card in hand that is not part of a completed combo.
        //Draw another card and then mulligan the selected card back into the deck.
    mulliganInt = 2;

    //Conduct mulligans.
    //qDebug() << "r3 mulligan";
    if (showqDebug)
        qDebug () << "3 r3 mulligan hand size: " << game.hand.size();
    mulligan(game, mulliganInt);
    if (showqDebug)
        qDebug() << "3 post mulligan hand size: " << game.hand.size();

    //We have now mulliganned.  Play out the cards according to turn length.
    //Figure out how long this round will be.
    //TODO: Update for round extension cards like Ciri.
    int r3Turns = static_cast<int>(game.hand.size());
    if (showqDebug)
        qDebug() << "3 Setting turns as: " << r3Turns;
    //qDebug() << "r3 score";
    if (showqDebug)
        qDebug() << "3 pre play hand size: " << game.hand.size();
    scoreR3 += playRound(game, r3Turns);
    if (showqDebug)
        qDebug() << "3 post play hand size: " << game.hand.size();
    //qDebug() << "Failure point?";

    //**************************************************************************************************************************************
    //************************************************All Rounds Completed.  Compile information and return*********************************
    //**************************************************************************************************************************************

    //Store individual round score information by appending the the QLineSeries member variables.
    //We don't store this in a GwentSimResults
    if (showqDebug)
        qDebug() << "A turns: " << r1Turns << ", score: " << scoreR1;
    if (showqDebug)
        qDebug() << "B turns: " << r2Turns << ", score: " << scoreR2;
    if (showqDebug)
        qDebug() << "C turns: " << r3Turns << ", score: " << scoreR3;
    roundOneScores.append(static_cast<qreal>(r1Turns), static_cast<qreal>(scoreR1));
    roundTwoScores.append(static_cast<qreal>(r2Turns), static_cast<qreal>(scoreR2));
    roundThreeScores.append(static_cast<qreal>(r3Turns), static_cast<qreal>(scoreR3));

    results.scoreSum = scoreR1 + scoreR2 + scoreR3;
    return results;
}
