#include "Game.h"
#include <iostream>
#include <cstdlib>  


int main() {
    int maingrid_row, maingrid_col, inputgrid_row, inputgrid_col;
    bool running = true;

    while (running) {
        system("cls");  // Clear the console screen
        std::cout << "\n--- Main Grid Configuration ---\n";
        std::cout << "Enter number of Rows and Cols: ";
        std::cin >> maingrid_row >> maingrid_col;

        std::cout << "\n--- Input Grid Configuration ---\n";
        std::cout << "Enter number of Rows and Cols: ";
        std::cin >> inputgrid_row >> inputgrid_col;

        Game game(maingrid_row, maingrid_col, inputgrid_row, inputgrid_col);
        game.run();

        char choice;
        std::cout << "\nWould you like to configure another grid? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            running = false;
        }
    }

    return 0;
}
