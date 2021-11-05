//
// Created by martin on 5/11/21.
//

#include "Animator.h"

void Animator::setFila(int fila) {
    this->fila = fila;
    sf::IntRect rect = this->getTextureRect();
    rect.height = this->getTexture()->getSize().y / fila;
    this->setTextureRect(rect);
}

void Animator::setColumna(int columna) {
    this->columna = columna;
    sf::IntRect rect = this->getTextureRect();
    rect.width = this->getTexture()->getSize().x / columna;
    this->setTextureRect(rect);
}

void Animator::animate() {
    sf::IntRect rect = this->getTextureRect();
    auto anchoColumna = this->getTexture()->getSize().x / columna;

    fpsActual++;
    if (fpsActual < fps)
        return;

    fpsActual = 0;

    columnaActual++;
    if (columnaActual >= columna)
        columnaActual = 0;

    rect.left = columnaActual * anchoColumna;
    this->setTextureRect(rect);
}

Animator::Animator() {
    columnaActual = 0;
    fpsActual = 0;
}

void Animator::setFps(int fps) {
    this->fps = fps;
}

void Animator::setAnimation(int fila) {
    sf::IntRect rect = this->getTextureRect();
    auto altoFila = this->getTexture()->getSize().y / this->fila;

    rect.top = fila * altoFila;
    this->setTextureRect(rect);
}

