//
// Created by user on 15.06.2021.
//

#ifndef SNAKE_CONSOLE_GAME_APPLE_H
#define SNAKE_CONSOLE_GAME_APPLE_H

#include <vector>
#include "Renderable.h"
#include "Point.h"

class Apple : public Renderable{
private:
    Point* point;

    int customRand(int min, int max) {
        return rand() % (max - min + 1) + min;
    }
public:

    bool eaten = false;

    Apple(Screen &screen, Point* point) : Renderable(screen){
        this->point = point;
    }

    void render() {
        if(this->eaten){
            spawn();
        }
        this->screen->setPoint(*point, 'O');
    }

    bool isEaten(Point* point) {
        if(this->point->x == point->x && this->point->y == point->y) {
            eaten = true;
        }

        return this->eaten;
    }

    void spawn(){
        while(screen->screen[point->x][point->y] != ' '){
            point->x = customRand(screen->offsetX, screen->sizeX - 1 - screen->offsetX);
            point->y = customRand(screen->offsetY, screen->sizeY - 1 - screen->offsetY);
        }

        eaten = false;
    }
};


#endif //SNAKE_CONSOLE_GAME_APPLE_H
