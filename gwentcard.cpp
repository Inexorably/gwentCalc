#include "gwentcard.h"

bool GwentCard::operator<(const GwentCard &c){
    return this->unconditionalPoints<c.unconditionalPoints;
}

GwentCard::GwentCard(QString s, int tempProvisions, double tempUnconditionalPoints){
    name = s;
    provisions = tempProvisions;
    unconditionalPoints = tempUnconditionalPoints;
}
