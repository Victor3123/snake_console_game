//
// Created by user on 06.06.2021.
//

#ifndef SNAKE_CONSOLE_GAME_SNAKE_H
#define SNAKE_CONSOLE_GAME_SNAKE_H

#include "Renderable.h"
#include "Point.h"

class Snake : public Renderable {
public:

    using Renderable::Renderable;

    void render() {
        this->screen->setPoint(*new Point(3, 3), '*');
        this->screen->setPoint(*new Point(2, 3), '*');
        this->screen->setPoint(*new Point(1, 3), '*');
    }

    void move(){

    }
};


#endif //SNAKE_CONSOLE_GAME_SNAKE_H
