// game.h
#ifndef GAME_H
#define GAME_H

#include "../include/deck.h"
#include "../include/player.h"

class Game
{
public:
    Game();
    void play();

private:
    Deck deck;
    Player player;
    Player dealer;
};

#endif
