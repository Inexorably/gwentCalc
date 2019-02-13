#include "gwentsimresults.h"

GwentSimResults::GwentSimResults(){
    n = 1;
    scoreSum = 0;
}

double GwentSimResults::score() const{
    return static_cast<double>(scoreSum)/static_cast<double>(n);
}

void GwentSimResults::merge(const GwentSimResults &r){
    //This is initialised with a score of 0, so we do not increment n if score is 0.
    if (scoreSum != 0){
        n += r.n;
    }

    scoreSum +=r.scoreSum;
    roundOneScores = r.roundOneScores;
    roundTwoScores = r.roundTwoScores;
    roundThreeScores = r.roundThreeScores;

}
