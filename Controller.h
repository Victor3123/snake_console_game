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
    int lastKey = VK_UP;

public:


    void readKey(){
        if (GetKeyState(VK_ESCAPE) & 0x8000) {
            this->lastKey = VK_ESCAPE;
        }else if(GetKeyState(VK_LEFT) & 0x8000){
            this->lastKey = VK_LEFT;
        }else if(GetKeyState(VK_RIGHT) & 0x8000){
            this->lastKey = VK_RIGHT;
        }else if(GetKeyState(VK_UP) & 0x8000){
            this->lastKey = VK_UP;
        }else if(GetKeyState(VK_DOWN) & 0x8000){
            this->lastKey = VK_DOWN;
        }
    }

    int getLastKey(){
        return this->lastKey;
    }
};


#endif //SNAKE_CONSOLE_GAME_CONTROLLER_H
