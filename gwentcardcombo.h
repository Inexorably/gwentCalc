#ifndef GWENTCARDCOMBO_H
#define GWENTCARDCOMBO_H

#include "gwentcard.h"
#include "gwentconditional.h"


#include <vector>

//For storing combinations of gwentCards and the combined points power.

class GwentCardCombo
{
public:
    GwentCardCombo();

    std::vector<GwentCard> cards;

    //Calculate the current value of the combo.  Factors to consider are field (such as bloodthirst) and turns left (such as dot like weather / other points over time).
    //The bloodthirst (and other similar) settings will be stored in the GwentConditional object.
    //We also need to take the turns in a round in order to figure out how to value dot effects.
    double calculateValue(const GwentConditional &c, const int &turns) const;

    //Comparison operator to sort by unconditionalPoints value.
    bool operator<(const GwentCardCombo &c) const;

    //Can add more types of points such as bloodlust / assumed turns in future.
    double unconditionalPoints;

    //An int to track the occurences of a specific combo so that we can show the results in the results window.
    int occurences;
};

#endif // GWENTCARDCOMBO_H
