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

    //Create the base GwentGame to reload every loop / simulation iteration.
    GwentGame baseGame = GwentGame(pkg);

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
    qDebug() << randomInt(0,100);
    GwentSimResults results;
    return results;

}
