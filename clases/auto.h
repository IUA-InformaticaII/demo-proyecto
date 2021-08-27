#ifndef TESTSFML_AUTO_H
#define TESTSFML_AUTO_H

#include <SFML/Graphics.hpp>

class Auto {
    int x, y;
    int velx, vely;
    sf::Sprite sp;
public:
    Auto(int x, int y, const sf::Texture &tx);
    void dibujar(sf::RenderWindow &w);

    void moverArriba();

    void moverAbajo();
};


#endif //TESTSFML_AUTO_H
