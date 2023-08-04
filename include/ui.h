// ui.h
#ifndef UI_H
#define UI_H

class UI
{
public:
    // Function to display the main game menu and returns the player's choice
    int display_main_menu();

    // Function to display a message to the player
    void display_message(const char *msg);

    // Function to ask user for draw a card or pass
    char ask_draw_or_pass();
};

#endif
