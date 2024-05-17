#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>

class Grid {
public:
    bool check; 
    Grid(int rows, int cols, int cellSize);
    void handleClick(const sf::Vector2i& mousePos);
    void render(sf::RenderWindow& window);

private:
    int cellSize;
    int rows;
    int cols;
    std::vector<std::vector<sf::Color>> gridColors;
};

#endif // GRID_H
