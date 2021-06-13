//
// Created by user on 06.06.2021.
//


#ifndef SNAKE_CONSOLE_GAME_SCREEN_H
#define SNAKE_CONSOLE_GAME_SCREEN_H

//class Renderable;

#include <iostream>
#include <Windows.h>
#include <vector>
#include "Point.h"


using namespace std;

class Screen {
private:

    int sizeX = 21;
    int sizeY = 21;
    int offsetX = 1;
    int offsetY = 1;
    int blancChar = ' ';

    vector<vector<char>> screen;

public:
    Screen() {
        screen.resize(sizeX);
        for (int i = 0; i < sizeX; i++) {
            screen[i].resize(sizeY);
        }
    }


    void clear() {
        for (int x = 0; x < sizeX; x++) {
            for (int y = 0; y < sizeY; y++) {
                screen[x][y] = this->blancChar;
            }
        }
    }

    void render() {
        system("cls");

        for(int x = 0; x < sizeX; x++){
            screen[0][x] = '+';
            screen[sizeY-1][x] = '+';
        }
        for(int y = 0; y < sizeY; y++){
            screen[y][0] = '+';
            screen[y][sizeX -1] = '+';
        }


        for (int x = 0; x < sizeX; x++) {
            for (int y = 0; y < sizeY; y++) {
                cout << screen[y][x] << " ";
            }
            cout << endl;
        }
    }

    void setPoint(Point point, char content) {
        screen[point.x + offsetX - 1][point.y + offsetY - 1] = content;
    }
};


#endif //SNAKE_CONSOLE_GAME_SCREEN_H
