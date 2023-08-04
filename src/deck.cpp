// deck.cpp
#include "../include/deck.h"

#include <algorithm>
#include <random>
#include <chrono>

// Deck constructor: initializes a deck with 52 cards
Deck::Deck()
{
    // Loop through each suit
    for (int i{0}; i < 4; ++i)
    {
        // Loop through each card value (2-14, where 14 is Ace)
        for (int j{2}; j <= 14; ++j)
        {
            // Push each card into the deck
            cards.push_back({static_cast<Suit>(i), j});
        }
    }
}

void Deck::shuffle()
{
    // Random device used to generate random number
    std::random_device rd{};
    // Mersenne Twister random number generator
    std::mt19937 gen(rd());
    // Shuffle the deck using the random number generator above
    std::shuffle(cards.begin(), cards.end(), gen);
}

// Function to draw the top card from the deck
Card Deck::draw()
{
    // Get the top card
    Card top_card = top();
    // Remove the card
    cards.pop_back();

    // Return the drawn card
    return top_card;
}

// Return the top card without removing it
const Card &Deck::top() const
{
    return cards.back();
}

// Return the bottom card without removing it
const Card &Deck::bottom() const
{
    return cards.front();
}

// Function to convert int value to string
std::string Card::value_as_string() const
{
    switch (value)
    {
    case 2:
        return "Two";
    case 3:
        return "Three";
    case 4:
        return "Four";
    case 5:
        return "Five";
    case 6:
        return "Six";
    case 7:
        return "Seven";
    case 8:
        return "Eight";
    case 9:
        return "Nine";
    case 10:
        return "Ten";
    case 11:
        return "Jack";
    case 12:
        return "Queen";
    case 13:
        return "King";
    case 14:
        return "Ace";
    default:
        return "Unknown";
    }
}
