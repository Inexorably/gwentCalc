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

        //Set the conditions member.
        //Blood thirst / damaged enemies condition settings.
        conditions.damagedEnemies[1] = settingsList[10].toDouble();
        conditions.damagedEnemies[2] = settingsList[11].toDouble();
        conditions.damagedEnemies[3] = settingsList[12].toDouble();
        conditions.damagedEnemies[0] = 1.0-conditions.damagedEnemies[1]-conditions.damagedEnemies[2]-conditions.damagedEnemies[3];
    }

    //Set combo conditions member equal to this->conditions.  We set the conditions on each combo member so that we can use the information
    //in combo's < operator (which can only access combo member variables).
    for (size_t i = 0; i < this->combos.size(); ++i){
        combos[i].conditions = this->conditions;
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
