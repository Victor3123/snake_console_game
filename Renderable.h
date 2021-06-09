//
// Created by user on 06.06.2021.
//

#ifndef SNAKE_CONSOLE_GAME_RENDERABLE_H
#define SNAKE_CONSOLE_GAME_RENDERABLE_H
#include "Screen.h"

using namespace std;

class Renderable
{
public:

    Screen* screen;


    Renderable(Screen &screen1)
    {
        screen = &screen1;
    }

    void render()
    {
        // override in children
    }
};


#endif //SNAKE_CONSOLE_GAME_RENDERABLE_H
