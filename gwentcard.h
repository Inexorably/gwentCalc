#ifndef GWENTCARD_H
#define GWENTCARD_H

#include <QString>

class GwentCard
{
public:
    GwentCard();

    GwentCard(const QString &tempName, const int &tempProvisions, const double &tempUnconditionalPoints);

    //Creating a new constructor to load the damagedValues array.
    GwentCard(const QString &tempName, const int &tempProvisions, const double &tempUnconditionalPoints, const double &damaged1, const double &damaged2, const double &damaged3);

    //Comparison operator compares unconditionalPoints for overloading.  Returns true if this is less than c.
    bool operator<(const GwentCard &c);

    QString name;
    int provisions;
    double unconditionalPoints; //Points that are not conditional (ie dependant on things, like bloodlust).

    //Probability distributions (in decimal, NOT PERCENT) for number of damaged enemies.
    //Example: damagedValues[0] is value for 0 enemies, and 3 is for 3 enemies.
    double damagedValues[4];
};

#endif // GWENTCARD_H
