#include "auto.h"
#include <cmath>
#include <iostream>

Auto::Auto(int x, int y, const sf::Texture &tx) {
    acc = 0;
    ang = 0;
    vel = 0;
    sp.setTexture(tx);
    sp.setPosition(x, y);
    sp.setOrigin(tx.getSize().x / 2, tx.getSize().y / 2);
}

void Auto::dibujar(sf::RenderWindow &w) {
    w.draw(sp);
}

void Auto::acelerar() {
    acc = 5;
}

void Auto::doblar(int direc) {
    // ang += (direc == 1) ? 1 : -1;
    if (direc == 1)
        ang += 2;
    else
        ang += -2;
}

void Auto::simulate(sf::Sprite &enemigo) {
    float oldRot = sp.getRotation();

    sp.rotate(ang);
    ang = 0;

    sf::Vector2f newPos, oldPos = sp.getPosition();
    // vf = v0 + a
    acc = acc - vel / 5;
    vel = vel + acc;
    vel = vel - vel / 5;
    if (vel < 0.1)
        vel = 0;
    // xf = x0 + vf
    newPos.x = sp.getPosition().x + vel * cos(sp.getRotation() / 360.0 * M_PI * 2);
    newPos.y = sp.getPosition().y + vel * sin(sp.getRotation() / 360.0 * M_PI * 2);

    sp.setPosition(newPos);


    if (sp.getGlobalBounds().intersects(enemigo.getGlobalBounds())) {
        sp.setPosition(oldPos);
        sp.setRotation(oldRot);
        std::cout << "Choqué" << std::endl;
    }
}

float Auto::getAng() const {
    return sp.getRotation();
}

sf::Vector2f Auto::getPos() const {
    return sp.getPosition();
}
