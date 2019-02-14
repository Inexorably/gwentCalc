#ifndef GWENTCARD_H
#define GWENTCARD_H

#include <QString>

class GwentCard
{
public:
    GwentCard();

    GwentCard(QString tempName, int tempProvisions, double tempUnconditionalPoints);

    //Comparison operator compares unconditionalPoints for overloading.  Returns true if this is less than c.
    bool operator<(const GwentCard &c);

    QString name;
    int provisions;
    double unconditionalPoints; //Points that are not conditional (ie dependant on things, like bloodlust).
};

#endif // GWENTCARD_H
