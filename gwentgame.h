#ifndef GWENTGAME_H
#define GWENTGAME_H

#include "QDebug"
#include "QFile"

#include "globals.h"
#include "gwentcard.h"
#include "gwentscenario.h"

#include <vector>

//A class for storing the basic items needed for running gwent simulations.
//Initalized with the deck.
//Has deck, hand, graveyard vectors.

class GwentGame
{
public:
    GwentGame(const GwentScenario &pkg);

    std::vector<GwentCardCombo> combos;
    std::vector<GwentCard> deck;
    std::vector<GwentCard> hand;
    std::vector<GwentCard> graveyard;

    //Draw cards from deck.
    void draw(const int &n);

    int r1BaseTurns;
    int r2BaseTurns;
    bool turnVariationBool;
    int turnVariationInt;
};

#endif // GWENTGAME_H
