#include "Game.h"

Game::Game() : window(sf::VideoMode(520, 300), "SFML Grid"), grid(8, 8, 37), igrid(3,3,40) {}
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
    }
}

void Game::update() {
    // Update game logic 


}

void Game::render() {
    window.clear(sf::Color::White);
    grid.render(window);
    igrid.render(window); 
    window.display();
}
