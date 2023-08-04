// ui.cpp
#include "../include/ui.h"

#include <iostream>

// Function to display the main game menu and return the player's choice
int UI::display_main_menu()
{
    std::cout << "***** GAME OF TWENTY_ONE (SIMPLER BLACKJACK) *****\n\n";
    std::cout << "1. Start new game\n";
    std::cout << "2. Quit\n\n";
    std::cout << "Enter your choice: ";
    int choice{};
    std::cin >> choice;
    std::cout << '\n';

    return choice;
}

// Function to display a message to the player
void UI::display_message(const char *msg)
{
    std::cout << msg << '\n';
}

// Function to ask the player if the player wants to draw a card or pass
char UI::ask_draw_or_pass()
{
    char choice{};
    std::cout << "Draw a card or pass? (d/p): ";
    std::cin >> choice;
    std::cout << '\n';

    return choice;
}
