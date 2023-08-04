// deck.h
#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>

enum class Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

struct Card
{
    Suit suit;
    int value;

    // Function to convert int value of the card to string
    std::string value_as_string() const;
};

class Deck
{
public:
    // Constructor: initializes a deck with 52 cards
    Deck();

    // Member function to shuffle the elements contained in the Deck container
    void shuffle();
    // Member function to return the top card (and remove it from the Deck)
    Card draw();
    // Member function to get a reference to top of the deck
    const Card &top() const;
    // Member function to get a reference to bottom of the deck
    const Card &bottom() const;

private:
    std::vector<Card> cards;
};

#endif
