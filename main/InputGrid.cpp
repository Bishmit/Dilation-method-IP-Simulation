#include "InputGrid.h"
#include <iostream>

InputGrid::InputGrid(int rows, int cols, int cellSize)
    : cellSize(cellSize),
    rows(rows),
    cols(cols),
    check(false),
    gridColors(rows, std::vector<sf::Color>(cols, sf::Color::White)) {}

void InputGrid::handleClick(const sf::Vector2i& mousePos) {
    // Adjusting for the grid's position offset
    int offsetX = 333;
    int offsetY = 66;

    int cellX = (mousePos.x - offsetX) / cellSize;
    int cellY = (mousePos.y - offsetY) / cellSize;

    std::cout << cellX << " " << cellY << std::endl;

    if (cellX >= 0 && cellX < cols && cellY >= 0 && cellY < rows) {
        if (gridColors[cellY][cellX] == sf::Color::White) {
            std::cout << "chalexa" << "\n";
            gridColors[cellY][cellX] = sf::Color::Green;
        }
        else {
            gridColors[cellY][cellX] = sf::Color::White;
        }
    }
}

void InputGrid::render(sf::RenderWindow& window) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
            cell.setPosition(333 + j * cellSize, 66 + i * cellSize);
            cell.setFillColor(gridColors[i][j]);
            cell.setOutlineThickness(2);
            cell.setOutlineColor(sf::Color::Black);
            window.draw(cell);
        }
    }
}

std::vector<std::vector<int>> InputGrid::findGreenBoxIndices() {
    std::vector<std::vector<int>> greenIndices(rows, std::vector<int>(cols, 0)); 

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (gridColors[i][j] == sf::Color::Green) {
                greenIndices[i][j] = 1; 
            }
        }
    }
    return greenIndices;
}




