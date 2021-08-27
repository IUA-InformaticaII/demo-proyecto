#include "auto.h"

Auto::Auto(int x, int y, const sf::Texture &tx) : x(x), y(y) {
    velx = 0;
    vely = 0;
    sp.setTexture(tx);
    sp.setPosition(x, y);
}

void Auto::dibujar(sf::RenderWindow &w) {
    w.draw(sp);
}

void Auto::moverArriba() {
    sp.move(0,-3);
}

void Auto::moverAbajo() {
    sp.move(0,3);
}
