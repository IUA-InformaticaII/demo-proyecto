#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "iostream"

#include "clases/auto.h"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(400, 200), "TITULO");
    window.setFramerateLimit(30);
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("car.png"))
        return EXIT_FAILURE;
    Auto player(100, 100, texture);

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            player.moverArriba();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            player.moverAbajo();
        }

        window.clear();
        player.dibujar(window);
        window.display();
    }
    return EXIT_SUCCESS;
}