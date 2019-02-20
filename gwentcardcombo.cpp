#include "gwentcardcombo.h"

bool GwentCardCombo::operator<(const GwentCardCombo &c) const{
    return calculateValue()<c.calculateValue();
}

GwentCardCombo::GwentCardCombo(){
    occurences = 0;
    unconditionalPoints = 0;
    for (int i = 0; i < 4; ++i)
        damagedValues[i] = 0;
    turnsLeft = 7;
}

//For now, we start with just returning unconditionalPoints, so that we can swap out all the unconditionalPoints calls for calculateValue calls while holding the results constant.
double GwentCardCombo::calculateValue() const{
    double temp = unconditionalPoints;
    //Bloodthirst
    for (int i = 1; i < 4; ++i){
        temp += damagedValues[i]*conditions.damagedEnemies[i]/100;
    }
    //Value per turn
    temp += turnsLeft*valuePerTurn;
    if (temp > 100){
        qDebug() << temp << ", " << turnsLeft << ", " << valuePerTurn;
        qDebug() << cards.size();
    }
    return temp;
}
