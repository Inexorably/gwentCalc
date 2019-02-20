#include "gwentcard.h"

bool GwentCard::operator<(const GwentCard &c){
    return this->unconditionalPoints+turnsLeft*valuePerTurn<c.unconditionalPoints+turnsLeft*valuePerTurn;
}

GwentCard::GwentCard(){
    name = "";
    provisions = -1;
    unconditionalPoints = -1;
    timesPlayed = 0;
    timesMulliganed = 0;
}

GwentCard::GwentCard(const QString &s, const int &tempProvisions, const double &tempUnconditionalPoints){
    name = s;
    provisions = tempProvisions;
    unconditionalPoints = tempUnconditionalPoints;
    for (int i = 0; i < 4; ++i)
        damagedValues[i] = 0;
    valuePerTurn = 0;
    timesPlayed = 0;
    timesMulliganed = 0;
}

GwentCard::GwentCard(const QString &s, const int &tempProvisions, const double &tempUnconditionalPoints, const double &damaged1, const double &damaged2, const double &damaged3){
    name = s;
    provisions = tempProvisions;
    unconditionalPoints = tempUnconditionalPoints;
    damagedValues[0] = 0;
    damagedValues[1] = damaged1;
    damagedValues[2] = damaged2;
    damagedValues[3] = damaged3;
    valuePerTurn = 0;
    timesPlayed = 0;
    timesMulliganed = 0;
}

GwentCard::GwentCard(const QString &tempName, const int &tempProvisions, const double &tempUnconditionalPoints, const double &damaged1, const double &damaged2, const double &damaged3, const double &vpt){
    name = tempName;
    provisions = tempProvisions;
    unconditionalPoints = tempUnconditionalPoints;
    damagedValues[0] = 0;
    damagedValues[1] = damaged1;
    damagedValues[2] = damaged2;
    damagedValues[3] = damaged3;
    valuePerTurn = vpt;
    timesPlayed = 0;
    timesMulliganed = 0;

}
