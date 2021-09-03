//
// Created by martin on 3/9/21.
//

#include "Mapa.h"

Mapa::Mapa(string archivo) {
    ifstream archivoMapa;
    string imagen, dummy;
    int tileSizeX, tileSizeY;
    int tileColumns, tileRow;

    int val;
    int posX, posY;
    int corteX, corteY;

    archivoMapa.open(archivo);
    if (archivoMapa.is_open()) {
        archivoMapa >> dummy;
        archivoMapa >> imagen;

        archivoMapa >> dummy;
        archivoMapa >> mapSizeX;
        archivoMapa >> mapSizeY;

        archivoMapa >> dummy;
        archivoMapa >> tileColumns;
        archivoMapa >> tileRow;

        archivoMapa >> dummy;
        archivoMapa >> tileSizeX;
        archivoMapa >> tileSizeY;

        textura.loadFromFile(imagen);

        for (int i = 0; i < (mapSizeX * mapSizeY); i++) {
            map[i].setTexture(textura);
            archivoMapa >> val;
            posX = i % mapSizeX * tileSizeX;
            posY = (i / mapSizeX) * tileSizeY;
            map[i].setPosition(posX, posY);
            corteX = val % tileColumns * tileSizeX;
            corteY = (val / tileColumns) * tileSizeY;
            map[i].setTextureRect({corteX, corteY, tileSizeX, tileSizeY});
        }
    }
    archivoMapa.close();
}

void Mapa::dibujar(sf::RenderWindow &w) {
    for (int i = 0; i < (mapSizeX * mapSizeY); ++i) {
        w.draw(map[i]);
    }
}
