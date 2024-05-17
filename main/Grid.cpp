#include "Grid.h"

Grid::Grid(int rows, int cols, int cellSize)
    : cellSize(37),
    rows(8),
    cols(8),
    check(false),
    gridColors(rows, std::vector<sf::Color>(cols, sf::Color::White)) {}

void Grid::handleClick(const sf::Vector2i& mousePos) {
    int cellX = mousePos.x / cellSize;
    int cellY = mousePos.y / cellSize;
   
    if (cellX >= 0 && cellX < cols && cellY >= 0 && cellY < rows) {
        if (gridColors[cellY][cellX] == sf::Color::White) {
            gridColors[cellY][cellX] = sf::Color::Green;
        }
        else {
            gridColors[cellY][cellX] = sf::Color::White;
        }
    }
}

void Grid::render(sf::RenderWindow& window) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
            cell.setPosition(j * cellSize, i * cellSize);
            cell.setFillColor(gridColors[i][j]);
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::Black);
            window.draw(cell);
        }
    }
}
