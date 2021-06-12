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
    bool alive = true;

    const string DIR_FORWARD = "DIR_FORWARD";
    const string DIR_LEFT = "DIR_LEFT";
    const string DIR_RIGHT = "DIR_RIGHT";
    const string DIR_IGNORE = "DIR_IGNORE";

    const string POS_0 = "POS_0";
    const string POS_90 = "POS_90";
    const string POS_180 = "POS_180";
    const string POS_270 = "POS_270";

    string direction = DIR_FORWARD;


    vector<Point*> body;

public:
    Controller *controller;

    Snake(Screen &screen, Controller &controller) : Renderable(screen) {
        this->controller = &controller;
        this->body.push_back(new Point(3, 3));
        this->body.push_back(new Point(3, 2));
        this->body.push_back(new Point(3, 1));
    }

    void setSnakeAlive(bool alive){
        this->alive = alive;
    }

    bool getSnakeAlive(){
        return this->alive;
    }

    void render() {
        for (Point *point : this->body) {
            this->screen->setPoint(*point, '*');
        }
    }

    void deleteTail() {
        vector<Point*> oldBody = this->body;
        vector<Point*> newBody;

        for (int i = 1; i < oldBody.size(); ++i) {
            newBody.push_back(oldBody[i]);
        }

        this->body = newBody;
        delete &oldBody;
    }

    int translate(int key) {
        if (this->direction == this->POS_0 && key == VK_DOWN){
            return VK_UP;
        } else if (this->direction == POS_90 && key == VK_LEFT){
            return VK_RIGHT;
        } else if(this->direction == POS_180 && key == VK_UP){
            return VK_DOWN;
        } else if (this->direction == POS_270 && key == VK_RIGHT){
            return VK_LEFT;
        }
        return key;
    }

    void getNextPoint(){    }

    void move() {

        int key = this->translate(this->controller->getLastKey());
        Point* head = this->body.back();
        Point* next = new Point(1,1);

        if(key == VK_UP){
            next->x = head->x;
            next->y = head->y - 1;
            this->direction=POS_0;
        } else if (key == VK_RIGHT){
            next->x = head->x + 1;
            next->y = head->y;
            this->direction=POS_90;
        } else if(key == VK_DOWN){
            next->x = head->x;
            next->y = head->y + 1;
            this->direction=POS_180;
        } else if(key == VK_LEFT){
            next->x = head->x - 1;
            next->y = head->y;
            this->direction=POS_270;
        }

        this->body.push_back(next);

        deleteTail();
    }
};


#endif //SNAKE_CONSOLE_GAME_SNAKE_H
