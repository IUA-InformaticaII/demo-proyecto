//
// Created by martin on 5/11/21.
//

#ifndef TESTSFML_ANIMATOR_H
#define TESTSFML_ANIMATOR_H

#include <SFML/Graphics.hpp>

class Animator : public sf::Sprite {
    int fila, columna, columnaActual;
    int fps,fpsActual;
public:
    Animator();

    void setFila(int fila);
    void setFps(int fps);

    void setAnimation(int fila);

    void setColumna(int columna);

    void animate();
};


#endif //TESTSFML_ANIMATOR_H
