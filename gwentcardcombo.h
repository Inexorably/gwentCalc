#ifndef GWENTCARDCOMBO_H
#define GWENTCARDCOMBO_H

#include "gwentcard.h"
#include "gwentconditional.h"

#include <QDebug>

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
    //We actually need to store these values in the GwentCardCombo object so that the comparison operator can accurately compare the objects (we can't pass arguments to <).
    double calculateValue() const;
    GwentConditional conditions;
    int turnsLeft;

    //Comparison operator to sort by unconditionalPoints value.
    bool operator<(const GwentCardCombo &c) const;

    //Can add more types of points such as bloodlust / assumed turns in future.
    double unconditionalPoints;

    //An int to track the occurences of a specific combo so that we can show the results in the results window.
    int occurences;

    //The additional points of value that a combo gets for each damaged enemy (0, 1, 2, 3).  Note: damagedValues[0] = 0.
    double damagedValues[4];

    //Value per turn
    double valuePerTurn;
};

#endif // GWENTCARDCOMBO_H
