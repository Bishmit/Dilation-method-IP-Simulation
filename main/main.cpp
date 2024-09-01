#include "Game.h"
#include<iostream>

// global variable that is going to cause some issues haha 

int main() {
    int maingrid_row, maingrid_col, inputgrid_row, inputgrid_col; 
    std::cout << "Input maingrid row: "; 
    std::cin >> maingrid_row; 
    std::cout << "Input maingrid col: ";
    std::cin >> maingrid_col;
    std::cout << "Input inputgrid row: ";
    std::cin >> inputgrid_row;
    std::cout << "Input inputgrid row: ";
    std::cin >> inputgrid_col;
    Game game(maingrid_row, maingrid_col, inputgrid_row, inputgrid_col);
    game.run();
    return 0;
}