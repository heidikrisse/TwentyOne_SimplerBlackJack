#include "../include/game.h"
#include "../include/ui.h"

#include <iostream>

Game::Game() : deck(), player(), dealer() {}

void Game::play()
{
    // Shuffle the deck before starting the game
    deck.shuffle();

    // Deal initial cards to the player and the dealer
    player.draw_card(deck.draw());
    dealer.draw_card(deck.draw());

    UI ui;

    std::cout << "\nYour turn to draw cards and start the game:\n\n";

    std::cout << "Your card: " << player.hand.back().value_as_string() << '\n';

    // Player's turn:
    while (true)
    {
        char choice{};
        choice = ui.ask_draw_or_pass();
        if (choice == 'd')
        {
            Card drawn_card = deck.draw();
            player.draw_card(drawn_card);
            std::cout << "You draw card: " << drawn_card.value_as_string() << '\n';
            std::cout << "Your score: " << player.total_score() << '\n';

            if (player.total_score() > 21)
            {
                std::cout << "Your score exceeds 21. Dealer won the game - you lost!\n";

                return;
            }
        }
        else if (choice == 'p')
        {
            std::cout << "You pass.\n\n";
            break;
        }
        else
        {
            std::cout << "Invalid choice. Please try again.\n\n";
        }
    }

    // Dealer's turn
    std::cout << "Dealers turn to draw cards:\n\n";
    while (dealer.total_score() < 17)
    {
        Card drawn_card = deck.draw();
        dealer.draw_card(drawn_card);
        std::cout << "Dealer draws a card.\n";
    }

    std::cout << "\nGame ended:\n";
    std::cout << "Your score: " << player.total_score() << '\n';
    std::cout << "Dealer's score: " << dealer.total_score() << '\n';

    // Determine the winner of the game
    if (player.total_score() > 21 || (dealer.total_score() <= 21 && dealer.total_score() > player.total_score()))
    {
        std::cout << "Dealer won the game - you lost!\n";
    }
    else if (player.total_score() == dealer.total_score())
    {
        std::cout << "It's a tie! Dealer wins the game - you lost!\n";
    }
    else
    {
        std::cout << "Congratulations, you won the game!\n";
    }
}
