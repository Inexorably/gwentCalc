#include "gwentsimresults.h"

GwentSimResults::GwentSimResults(){
    n = 1;
}

void GwentSimResults::merge(const GwentSimResults &r){
    n += r.n;
}
