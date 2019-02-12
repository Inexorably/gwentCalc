#include "gwentcardcombo.h"

bool GwentCardCombo::operator<(const GwentCardCombo &c){
    return unconditionalPoints<c.unconditionalPoints;
}

GwentCardCombo::GwentCardCombo()
{

}
