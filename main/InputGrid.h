#ifndef INPUTGRID_H
#define INPUTGRID_H

#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>

class InputGrid
{
public:
    bool check;
    InputGrid(int rows, int cols, int cellSize);
    void handleClick(const sf::Vector2i& mousePos);
    void render(sf::RenderWindow& window);
    std::vector<std::vector<int>> findGreenBoxIndices();
    void process(); 

    int getrows(); 
    int getcols(); 

private:
    int cellSize;
    int rows;
    int cols;
    std::vector<std::vector<sf::Color>> gridColors;
};

#endif 

