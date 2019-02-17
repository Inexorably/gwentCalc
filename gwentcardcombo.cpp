#include "gwentcardcombo.h"

bool GwentCardCombo::operator<(const GwentCardCombo &c) const{
    return calculateValue()<c.calculateValue();
}

GwentCardCombo::GwentCardCombo(){
    occurences = 0;
    unconditionalPoints = 0;
}

//For now, we start with just returning unconditionalPoints, so that we can swap out all the unconditionalPoints calls for calculateValue calls while holding the results constant.
double GwentCardCombo::calculateValue() const{
    return unconditionalPoints;

}
