//
// Created by martin on 15/10/21.
//

#ifndef TESTSFML_MAPATMX_H
#define TESTSFML_MAPATMX_H

#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/TileLayer.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "LinkedList.h"

using namespace std;

class MapaTMX {
private:
    tmx::Map map;
    sf::Texture textura;
    sf::Sprite *capa;

public:

    MapaTMX(string archivo) {
        map.load(archivo);
        capa = new sf::Sprite[map.getTileCount().x * map.getTileCount().y];
        const auto &tileSet = map.getTilesets();
        cout << map.getTileCount().x << endl;
        textura.loadFromFile(tileSet[0].getImagePath());

        const auto &layers = map.getLayers();
        for (int i = 0; i < layers.size(); ++i) {

            // Capa de mosaicos
            if (layers[i]->getType() == tmx::Layer::Type::Tile && i == 0) {
                const auto &tileLayer = layers[i]->getLayerAs<tmx::TileLayer>();
                const auto &tiles = tileLayer.getTiles();


                cout << tileLayer.getName() << endl;
                for (int j = 0; j < tiles.size(); ++j) {
                    //cout << tiles[j].ID << endl;
                    capa[i].setTexture(textura);
                    int val = tiles[j].ID - 1;
                    int posX, posY;
                    int corteX, corteY;

                    posX = j % map.getTileCount().x * map.getTileSize().x;
                    posY = (j / map.getTileCount().x) * map.getTileSize().y;
                    capa[j].setPosition(posX, posY);
                    corteX = val % map.getTileCount().x * map.getTileSize().x;
                    corteY = (val / map.getTileCount().x) * map.getTileSize().y;
                    capa[j].setTextureRect({corteX, corteY, static_cast<int>(map.getTileSize().x),
                                            static_cast<int>(map.getTileSize().y)});
                }

                //capa de Objetos
            } else if (layers[i]->getType() == tmx::Layer::Type::Object) {
                const auto &objectLayer = layers[i]->getLayerAs<tmx::ObjectGroup>();
                const auto &objects = objectLayer.getObjects();
                for (int j = 0; j < objects.size(); ++j) {
                    cout << objects[j].getName() << " ";
                    cout << objects[j].getPosition().x << " " << objects[j].getPosition().y << endl;
                    if (objects[j].getName() == "player") {
                        // Auto pl(objects[j].getPosition().x,objects[j].getPosition().y);
                    }
                }
            }
        }

        /*
        const auto& layers = map.getLayers();
        if (map.getOrientation() == tmx::Orientation::Orthogonal &&
            idx < layers.size() && layers[idx]->getType() == tmx::Layer::Type::Tile)
        {
            //round the chunk size to the nearest tile
            const auto tileSize = map.getTileSize();
            m_chunkSize.x = std::floor(m_chunkSize.x / tileSize.x) * tileSize.x;
            m_chunkSize.y = std::floor(m_chunkSize.y / tileSize.y) * tileSize.y;
            m_MapTileSize.x = map.getTileSize().x;
            m_MapTileSize.y = map.getTileSize().y;
            const auto& layer = layers[idx]->getLayerAs<tmx::TileLayer>();
            createChunks(map, layer);

            auto mapSize = map.getBounds();
            m_globalBounds.width = mapSize.width;
            m_globalBounds.height = mapSize.height;
        }
        else
        {
            std::cout << "Not a valid orthogonal layer, nothing will be drawn." << std::endl;
        }
         */
    }

    void dibujar(sf::RenderWindow &w) {
        for (int i = 0; i < (map.getTileCount().x * map.getTileCount().y); ++i) {
            w.draw(capa[i]);
        }
    }
};


#endif //TESTSFML_MAPATMX_H
