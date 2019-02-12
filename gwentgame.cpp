#include "gwentgame.h"

GwentGame::GwentGame(const GwentScenario &pkg){
    deck = pkg.deck;
    combos = pkg.combos;

    //Initalize the settings based on settings file.
    //Should be fine to do an fstream here as copy constructor will be used in loop iteration, this constructor is just once per simulation.

    QString data;
    QFile infile(SETTINGSFILENAME);
    QStringList settingsList;

    if (infile.open(QFile::ReadOnly)){
        data = infile.readAll();
        settingsList = data.split("\n");
        infile.close();
    }

    r1BaseTurns = (settingsList[5].toInt());
    r2BaseTurns = (settingsList[6].toInt());
    turnVariationBool = (static_cast<bool>(settingsList[7].toInt()));
    turnVariationInt = (settingsList[8].toInt());
}

void GwentGame::draw(const int &n){
    for (int i = 0; i < n; ++i){
        if (deck.empty()){
            return;
        }
        if (hand.size() < 10){
            hand.push_back(deck.back());
        }
        deck.pop_back();
    }
}
