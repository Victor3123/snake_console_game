//
// Created by user on 06.06.2021.
//

#ifndef SNAKE_CONSOLE_GAME_SNAKE_H
#define SNAKE_CONSOLE_GAME_SNAKE_H

#include <map>
#include <vector>
#include "Renderable.h"
#include "Point.h"
#include "Controller.h"

class Snake : public Renderable {
private:
    const string DIR_FORWARD = "DIR_FORWARD";
    const string DIR_LEFT = "DIR_LEFT";
    const string DIR_RIGHT = "DIR_RIGHT";
    const string DIR_IGNORE = "DIR_IGNORE";

    const string POS_0 = "POS_0";
    const string POS_90 = "POS_90";
    const string POS_180 = "POS_180";
    const string POS_270 = "POS_270";

    string direction = DIR_FORWARD;

    map<int, map<string, string>> translations = {
            {VK_UP,    {
                               {POS_0, DIR_FORWARD},
                               {POS_90, DIR_LEFT},
                               {POS_180, DIR_IGNORE},
                               {POS_270, DIR_RIGHT}
                       }},
            {VK_DOWN,  {
                               {POS_0, DIR_IGNORE},
                               {POS_90, DIR_RIGHT},
                               {POS_180, DIR_FORWARD},
                               {POS_270, DIR_LEFT}
                       }},
            {VK_LEFT,  {
                               {POS_0, DIR_LEFT},
                               {POS_90, DIR_IGNORE},
                               {POS_180, DIR_RIGHT},
                               {POS_270, DIR_FORWARD}
                       }},
            {VK_RIGHT, {
                               {POS_0, DIR_RIGHT},
                               {POS_90, DIR_FORWARD},
                               {POS_180, DIR_LEFT},
                               {POS_270, DIR_IGNORE}
                       }}
    };

    vector<Point*> body;

public:
    Controller *controller;

    Snake(Screen &screen, Controller &controller) : Renderable(screen) {
        this->controller = &controller;
        this->body.push_back(new Point(3, 3));
        this->body.push_back(new Point(3, 2));
        this->body.push_back(new Point(3, 1));
    }

    void render() {
        for (Point *point : this->body) {
            this->screen->setPoint(*point, '*');
        }
    }


    string translate(int key) {
        return translations[key][this->direction];
    }

    void move() {
        int lastKey = controller->getLastKey();
        if(lastKey == VK_UP){

        }
    }
};


#endif //SNAKE_CONSOLE_GAME_SNAKE_H
