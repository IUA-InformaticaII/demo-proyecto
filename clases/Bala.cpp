#include <cmath>
#include "Bala.h"

Bala::Bala(sf::Vector2f pos, float ang, const sf::Texture &tx, sf::Texture &tx_exp) : ang(ang), tx_exp(tx_exp) {
    sp.setPosition(pos);
    sp.rotate(ang);
    sp.setTexture(tx);
    timeout = 200;
}

void Bala::dibujar(sf::RenderWindow &w) {
    w.draw(sp);
}

void Bala::simulate() {
    sf::Vector2f newPos;

    if (timeout > 50) {
        newPos.x = sp.getPosition().x + VEL_BALA * cos(sp.getRotation() / 360.0 * M_PI * 2);
        newPos.y = sp.getPosition().y + VEL_BALA * sin(sp.getRotation() / 360.0 * M_PI * 2);

        sp.setPosition(newPos);
    } else if (timeout == 50) {
        sp.setTexture(tx_exp);
        sp.setTextureRect({0, 0, 19, 19});
    }
    timeout--;
}

int Bala::getTimeout() const {
    return timeout;
}

