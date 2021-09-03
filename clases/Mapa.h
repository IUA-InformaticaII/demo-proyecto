//
// Created by martin on 3/9/21.
//

#ifndef TESTSFML_MAPA_H
#define TESTSFML_MAPA_H

#include <string>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
class Mapa {
    sf::Texture textura;
    sf::Sprite map[100];
    int mapSizeX, mapSizeY;

public:
    Mapa(string archivo);
    void dibujar(sf::RenderWindow &w);
};


#endif //TESTSFML_MAPA_H
