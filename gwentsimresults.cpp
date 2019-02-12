#include "gwentsimresults.h"

GwentSimResults::GwentSimResults(){
    n = 1;
    scoreSum = 0;
}

double GwentSimResults::score() const{
    return static_cast<double>(scoreSum)/static_cast<double>(n);
}

void GwentSimResults::merge(const GwentSimResults &r){
    n += r.n;
    scoreSum +=r.scoreSum;
}
