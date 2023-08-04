/* main.cpp
 *
 * - Game logic is found in game.h/game.cpp
 * - UI is found in ui.h/ui.cpp
 * */
#include "include/game.h"
#include "include/ui.h"

#include <iostream>

int main()
{
    UI user_interface;
    Game game;

    bool playing{true};
    while (playing)
    {
        int choice{user_interface.display_main_menu()};

        switch (choice)
        {
        // Play
        case 1:
            game.play();
            break;
        // Quit
        case 2:
            user_interface.display_message("Bye bye!");
            playing = false;
            break;
        // Invalid choice
        default:
            user_interface.display_message("Invalid choice. Please try again.");
            break;
        }
    }

    return 0;
}
