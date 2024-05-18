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
    void update();
    void render();
    bool check; 
    Grid grid;
    InputGrid igrid;

    sf::RenderWindow window;
    std::vector<std::vector<int>> dilatedGrid;
    
};

#endif // GAME_H
