#ifndef GWENTSIMRESULTS_H
#define GWENTSIMRESULTS_H

//A class to hold the results we want to return from the simulator.

class GwentSimResults
{
public:
    GwentSimResults();

    void merge(const GwentSimResults &i);   //Merge the simulation results of i and *this.
    int n;
};

#endif // GWENTSIMRESULTS_H
