#include "auto.h"
#include <cmath>
#include <iostream>

Auto::Auto(int x, int y, const sf::Texture &tx) {
    acc = 0;
    ang = 0;
    vel = 0;
    anim.setTexture(tx);
    anim.setFila(2);
    anim.setColumna(3);
    anim.setFps(5);
    anim.setPosition(x, y);
    anim.setOrigin(tx.getSize().x / 2, tx.getSize().y / 2);
    anim.setScale(0.2, 0.2);
}

void Auto::dibujar(sf::RenderWindow &w) {
    anim.animate();
    w.draw(anim);
}

void Auto::acelerar() {
    acc = 2;
}

void Auto::doblar(int direc) {
    // ang += (direc == 1) ? 1 : -1;
    if (direc == 1)
        ang += M_PI / 360.0 * 40;
    else
        ang += -M_PI / 360.0 * 40;
}

void Auto::simulate(sf::Sprite &enemigo) {
    sf::Vector2f newPos, oldPos = anim.getPosition();
    float newRot, oldRot = anim.getRotation() * M_PI / 180.0;
    float wheelBase = 18;

    // Calculo pos de las ruedas
    sf::Vector2f frontWheel = oldPos + wheelBase / 2 * (sf::Vector2f) {cosf(oldRot), sinf(oldRot)};
    sf::Vector2f backWheel = oldPos - wheelBase / 2 * (sf::Vector2f) {cosf(oldRot), sinf(oldRot)};


    acc = acc - acc / 5;
    vel = vel + acc;

    backWheel += vel * (sf::Vector2f) {cosf(oldRot), sinf(oldRot)};
    frontWheel += vel * (sf::Vector2f) {cosf(oldRot + ang), sinf(oldRot + ang)};
    ang = 0;

    vel = vel - vel / 5;
    if (vel < 0.1){
        anim.setAnimation(0);
        vel = 0;
    }else{
        anim.setAnimation(1);
    }

    newPos = (frontWheel + backWheel);
    newPos.x /= 2;
    newPos.y /= 2;
    newRot = atan2f(frontWheel.y - backWheel.y, frontWheel.x - backWheel.x);
    anim.setPosition(newPos);
    anim.setRotation(newRot * 180.0 / M_PI);


    if (anim.getGlobalBounds().intersects(enemigo.getGlobalBounds())) {
        anim.setPosition(oldPos);
        anim.setRotation(oldRot);
        std::cout << "Choqué" << std::endl;
    }
}

float Auto::getAng() const {
    return anim.getRotation();
}

sf::Vector2f Auto::getPos() const {
    return anim.getPosition();
}
