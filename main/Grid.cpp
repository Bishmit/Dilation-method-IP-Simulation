#include "Grid.h"

Grid::Grid(int rows, int cols, int cellSize)
    : cellSize(37),
    rows(rows),
    cols(cols),
    check(false),
    gridColors(rows, std::vector<sf::Color>(cols, sf::Color::White)),
    originalGrid(rows, std::vector<int>(cols, 0)) {}
    

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
            sf::RectangleShape cell1(sf::Vector2f(cellSize - 1, cellSize - 1));
            cell1.setPosition(j * cellSize, i * cellSize);
            cell1.setFillColor(gridColors[i][j]);
            cell1.setOutlineThickness(1);
            cell1.setOutlineColor(sf::Color::Black);
            window.draw(cell1);
        }
    }
}

void Grid::finalDilationrender(sf::RenderWindow& window, std::vector<std::vector<int>>& dilatedGrid) {
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
    cell.setOutlineThickness(1);
    cell.setOutlineColor(sf::Color::Black);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cell.setPosition(j * cellSize, i * cellSize);
            if (dilatedGrid[i][j] == 1) {
                cell.setFillColor(sf::Color::Yellow); 
                auto temp = findGreenBoxIndices();
                if (temp[i][j] == 1) {
                    cell.setFillColor(sf::Color::Green);
                }
                window.draw(cell);
            }  
           
        }
       
    }
}

void Grid::finalErosionrender(sf::RenderWindow& window, std::vector<std::vector<int>>& dilatedGrid) {
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
    cell.setOutlineThickness(1);
    cell.setOutlineColor(sf::Color::Black);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cell.setPosition(j * cellSize, i * cellSize);
            if (dilatedGrid[i][j] == 1) {
                cell.setFillColor(sf::Color::Green);
                auto temp = findGreenBoxIndices();
                if (temp[i][j] == 1) {
                    cell.setFillColor(sf::Color::Yellow);
                }
                window.draw(cell);
            }
        }

    }
}


std::vector<std::vector<int>> Grid::findGreenBoxIndices() {
    std::vector<std::vector<int>> greenIndices(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (gridColors[i][j] == sf::Color::Green) {
                greenIndices[i][j] = 1;
            }
            else greenIndices[i][j] = 0;
        }
    }
    return greenIndices;
}

int Grid::getrows()
{
    return rows;
}

int Grid::getcols()
{
    return cols;
}

bool Grid::isCellGreen(int row, int col) const {
    return originalGrid[row][col] == 1;
}