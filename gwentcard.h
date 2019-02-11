#ifndef GWENTCARD_H
#define GWENTCARD_H

#include <QString>

class gwentCard
{
public:
    gwentCard(QString tempName, int tempProvisions, double tempUnconditionalPoints);

    QString name;
    int provisions;
    double unconditionalPoints; //Points that are not conditional (ie dependant on things, like bloodlust).
};

#endif // GWENTCARD_H
