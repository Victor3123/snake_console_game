//
// Created by user on 07.06.2021.
//

#ifndef SNAKE_CONSOLE_GAME_CONTROLLER_H
#define SNAKE_CONSOLE_GAME_CONTROLLER_H

#include <windows.h>
#include <conio.h>

using namespace std;

class Controller {
private:
    int lastKey = NULL;

public:
    void readKey(){
        this->lastKey = getch();
    }

    int getLastKey(){
        return this->lastKey;
    }
};


#endif //SNAKE_CONSOLE_GAME_CONTROLLER_H
