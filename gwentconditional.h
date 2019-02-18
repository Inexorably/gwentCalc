#ifndef GWENTCONDITIONAL_H
#define GWENTCONDITIONAL_H

//A class to hold the conditional information needed to calculate some scores (such as turns remaining, bloodthirst).
class GwentConditional
{
public:
    GwentConditional();

    //Probability distributions (in PERCENT) for number of damaged enemies.
    //Example: damagedEnemies[0] is probability for 0 enemies, and 3 is for 3 enemies.
    double damagedEnemies[4];
};

#endif // GWENTCONDITIONAL_H
