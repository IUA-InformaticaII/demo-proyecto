#ifndef TESTSFML_BALA_H
#define TESTSFML_BALA_H
#include <SFML/Graphics.hpp>

#define VEL_BALA 4.0
class Bala {
    float ang;
    sf::Sprite sp;
    sf::Texture &tx_exp;
    int timeout;
public:
    Bala(sf::Vector2f pos,float ang, const sf::Texture &tx, sf::Texture &tx_exp);

    void dibujar(sf::RenderWindow &w);
    void simulate();

    int getTimeout() const;
};


#endif //TESTSFML_BALA_H
