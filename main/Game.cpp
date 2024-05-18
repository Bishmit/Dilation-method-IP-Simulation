#include "Game.h"

Game::Game()
    : grid(8, 8, 37), // Initialize grid before dilatedGrid
    window(sf::VideoMode(520, 300), "Dilation"),
    check(false),
    dilatedGrid(8, std::vector<int>(8, 0)),
    igrid(3, 3, 40) {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    if (!font2.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    text.setFont(font);
    text.setString(" To select Grid = Mouse Leftclick");
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::Black);
    text.setPosition(300.f, 5.f);

    text2.setFont(font2);
    text2.setString(" To do Dilation = Enter");
    text2.setCharacterSize(14);
    text2.setFillColor(sf::Color::Black);
    text2.setPosition(300.f, 35.f);
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
            if (event.key.code == sf::Keyboard::Enter) {
                check = true;
                performDilation();
                // Call performDilation when Enter is pressed
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
            dilatedGrid[i][j] = gd[i][j];
            std::cout << dilatedGrid[i][j] << " ";
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
                                dilatedGrid[pi][pj] = 1;
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
            std::cout << dilatedGrid[i][j] << " ";
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
    if (check==true) {
        grid.finalrender(window, dilatedGrid); 
    }

    window.draw(text);
    window.draw(text2);

    window.display();
}
