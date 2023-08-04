// player.cpp
#include "../include/player.h"

// Function to draw (add) a card to the player's hand
void Player::draw_card(const Card &card)
{
    hand.push_back(card);
}

// Function to calculate total score of player's hand
int Player::total_score() const
{
    int score{0};
    // Track number of Aces because they can be either 1 or 14
    int ace_count{0};
    for (const auto &card : hand)
    {
        // If card is an Ace
        if (card.value == 14)
        {
            ++ace_count;
            score += 11;
        }
        // If card is a face card (Jack, Queen, King)
        else if (card.value > 10)
        {
            score += 10;
        }
        // For cards 2 - 10
        else
        {
            score += card.value;
        }
    }

    // Score for Aces when total score exceeds 21
    while (score > 21 && ace_count)
    {
        score -= 10;
        --ace_count;
    }

    return score;
}
