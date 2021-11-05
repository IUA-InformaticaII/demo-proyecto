#ifndef TESTSFML_AUTO_H
#define TESTSFML_AUTO_H

#include <SFML/Graphics.hpp>
#include "Animator.h"

class Auto {
    float acc;
    float vel;
    float ang;
    Animator anim;
public:
    Auto(int x, int y, const sf::Texture &tx);
    void dibujar(sf::RenderWindow &w);

    void acelerar();

    void doblar(int direc);

    void simulate(sf::Sprite &enemigo);

    float getAng() const;

    sf::Vector2f getPos() const;
};


#endif //TESTSFML_AUTO_H
