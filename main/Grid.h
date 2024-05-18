#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>
//#include"Game.h"

class Grid {
public:
    bool check; 
    Grid(int rows, int cols, int cellSize);
    void handleClick(const sf::Vector2i& mousePos);
    void render(sf::RenderWindow& window);

    void finalrender(sf::RenderWindow& window, std::vector<std::vector<int>>& dilatedGrid);

    std::vector<std::vector<int>> findGreenBoxIndices();
    bool isCellGreen(int row, int col) const;
    int getrows();
    int getcols();

private:
    int cellSize;
    int rows;
    int cols;
    std::vector<std::vector<sf::Color>> gridColors;
    std::vector<std::vector<int>> originalGrid;

};

#endif // GRID_H
