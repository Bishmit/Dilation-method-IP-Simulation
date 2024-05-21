#include "Game.h"

Game::Game()
    : grid(8, 8, 37), // Initialize grid before tempGrid
    window(sf::VideoMode(520, 300), "Dilation"),
    checkDilation(false), checkErosion(false),
    tempGrid(8, std::vector<int>(8, 0)),
    igrid(3, 3, 40) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    if (!font2.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    text.setFont(font);
    text.setString(" To select Grid: Mouse Leftclick");
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::Black);
    text.setPosition(300.f, 5.f);

    text2.setFont(font2);
    text2.setString(" To do Dilation: D\n To do Errosion:E");
    text2.setCharacterSize(14);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(300.f, 22.f);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                // Get the mouse position
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                grid.handleClick(mousePos);
                igrid.handleClick(mousePos);
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::D) {
                checkDilation = true;
                performDilation();
                // Call performDilation when Enter is pressed
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E) {
                checkErosion = true;
                performErosion();
                // Call performErosion when E is pressed
            }
        }
    }
}

void Game::update() {
    // Update logic if needed
}

void Game::performDilation() {
    auto igd = igrid.findGreenBoxIndices();
    auto gd = grid.findGreenBoxIndices();

    std::cout << "\n";

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tempGrid[i][j] = gd[i][j];
            std::cout << tempGrid[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (gd[i][j] == 1) {
                for (int ki = 0; ki < 3; ki++) {
                    for (int kj = 0; kj < 3; kj++) {
                        int pi = i + ki - 1;
                        int pj = j + kj - 1;

                        // Check if pi and pj are within bounds
                        if (pi >= 0 && pj >= 0 && pi < 8 && pj < 8) {
                            // Only apply dilation if igd[ki][kj] is 1
                            if (igd[ki][kj] == 1) {
                                tempGrid[pi][pj] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << tempGrid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Game::performErosion() {
    auto igd = igrid.findGreenBoxIndices(); // Structuring element
    auto gd = grid.findGreenBoxIndices();   // Original grid

    std::cout << "\n";

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tempGrid[i][j] = gd[i][j]; // Initialize tempGrid with the original grid
            std::cout << tempGrid[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (gd[i][j] == 1) {
                bool shouldErode = true;

                for (int ki = 0; ki < 3 && shouldErode; ki++) {
                    for (int kj = 0; kj < 3; kj++) {
                        int pi = i + ki - 1;
                        int pj = j + kj - 1;

                        // Check if pi and pj are within bounds
                        if (pi >= 0 && pj >= 0 && pi < 8 && pj < 8) {
                            if (igd[ki][kj] == 1 && gd[pi][pj] == 0) {
                                shouldErode = false;
                                break;
                            }
                        }
                        else if (igd[ki][kj] == 1) {
                            shouldErode = false;
                            break;
                        }
                    }
                }

                if (!shouldErode) {
                    tempGrid[i][j] = 0;
                }
            }
        }
    }

    std::cout << std::endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << tempGrid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Game::render() {
    window.clear(sf::Color::White);

    // Render the original grid and input grid
    grid.render(window);
    igrid.render(window);

    // Render the dilated grid if check is true
    if (checkDilation) {
        grid.finalDilationrender(window, tempGrid);
    }

    if (checkErosion) {
        grid.finalErosionrender(window, tempGrid); 
    }

    window.draw(text);
    window.draw(text2);

    window.display();
}
