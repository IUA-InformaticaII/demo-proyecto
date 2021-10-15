#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "iostream"

#include "clases/auto.h"
#include "clases/Mapa.h"
#include "clases/Bala.h"
#include "clases/MapaTMX.h"

int look_empty(Bala *balas[]);

int main() {


    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "TITULO");
    window.setFramerateLimit(30);
    // Load a sprite to display
    sf::Texture tx_car;
    if (!tx_car.loadFromFile("car.png"))
        return EXIT_FAILURE;
    sf::Texture tx_bala;
    if (!tx_bala.loadFromFile("bala.png"))
        return EXIT_FAILURE;
    sf::Texture tx_exp;
    if (!tx_exp.loadFromFile("explode.png"))
        return EXIT_FAILURE;

    Auto player(100, 100, tx_car);
    sf::Sprite contrincante;
    contrincante.setTexture(tx_car);
    contrincante.setPosition(400, 400);
    contrincante.setColor(sf::Color::Red);

    Bala **bala = new Bala *[100];
    for (int i = 0; i < 100; ++i) {
        bala[i] = nullptr;
    }
    int mat[5];
    int *ptr;
    ptr = mat + 3;

    //Mapa miMapa("mapa.txt");
    MapaTMX miMapa("assets/maps/mapa1.tmx");

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player.acelerar();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            // player.moverAbajo();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.doblar(0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.doblar(1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            int idx = look_empty(bala);
            cout << idx << endl;
            if (idx >= 0)
                bala[idx] = new Bala(player.getPos(), player.getAng(), tx_bala, tx_exp);
        }
//////////////////////////////////////////////////////////
        player.simulate(contrincante);

        for (int i = 0; i < 100; ++i) {
            if (bala[i] != nullptr) {
                bala[i]->simulate();
                if (bala[i]->getTimeout() < 0) {
                    delete bala[i];
                    bala[i] = nullptr;
                }
            }
        }


//////////////////////////////////////////////////////////
        window.clear();
        miMapa.dibujar(window);
        player.dibujar(window);
        window.draw(contrincante);
        for (int i = 0; i < 100; ++i) {
            if (bala[i] != nullptr)
                bala[i]->dibujar(window);
        }

        window.display();
    }
    return EXIT_SUCCESS;
}

int look_empty(Bala *balas[]) {
    for (int i = 0; i < 100; ++i) {
        if (balas[i] == nullptr)
            return i;
    }
    return -1;
}