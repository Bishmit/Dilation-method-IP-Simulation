#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "InputGrid.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void performDilation();
    void performErosion();
    void update();
    void render();
    bool checkDilation, checkErosion; 
    Grid grid;
    InputGrid igrid;

    sf::RenderWindow window;
    std::vector<std::vector<int>> tempGrid;

    sf::Text text, text2; 
    sf::Font font, font2; 
    
};

#endif // GAME_H
