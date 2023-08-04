// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"

#include <vector>

class Player
{
public:
    // Function to draw (add) a card to the player's hand
    void draw_card(const Card &card);
    int total_score() const;

    std::vector<Card> hand;
};

#endif
