#include "gwentcardcombo.h"

bool GwentCardCombo::operator<(const GwentCardCombo &c){
    return unconditionalPoints<c.unconditionalPoints;
}

GwentCardCombo::GwentCardCombo(){
    occurences = 0;
    unconditionalPoints = 0;
}
