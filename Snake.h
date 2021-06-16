//
// Created by user on 06.06.2021.
//

#ifndef SNAKE_CONSOLE_GAME_SNAKE_H
#define SNAKE_CONSOLE_GAME_SNAKE_H

#include <vector>
#include "Renderable.h"
#include "Point.h"
#include "Controller.h"
#include "Apple.h"


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



public:
    vector<Point *> body;

    Controller *controller;

    Snake(Screen &screen, Controller &controller) : Renderable(screen) {
        this->controller = &controller;
        this->body.push_back(new Point(10, 10));
        this->body.push_back(new Point(10, 9));
        this->body.push_back(new Point(10, 8));

    }


    void render() {
        for (Point *point : this->body) {
            this->screen->setPoint(*point, '*');
        }
    }

    void deleteTail() {
        vector<Point *> oldBody = this->body;
        vector<Point *> newBody;

        for (int i = 1; i < oldBody.size(); ++i) {
            newBody.push_back(oldBody[i]);
        }

        this->body = newBody;
        delete &oldBody;
    }

    int translate(int key) {
        if (this->direction == this->POS_0 && key == VK_DOWN) {
            return VK_UP;
        } else if (this->direction == POS_90 && key == VK_LEFT) {
            return VK_RIGHT;
        } else if (this->direction == POS_180 && key == VK_UP) {
            return VK_DOWN;
        } else if (this->direction == POS_270 && key == VK_RIGHT) {
            return VK_LEFT;
        }
        return key;
    }

    Point *getNextPoint(int key, Point *head) {
        Point *next = new Point();

        if (key == VK_UP) {
            next->x = head->x;
            next->y = head->y - 1;
            this->direction = POS_0;
        } else if (key == VK_RIGHT) {
            next->x = head->x + 1;
            next->y = head->y;
            this->direction = POS_90;
        } else if (key == VK_DOWN) {
            next->x = head->x;
            next->y = head->y + 1;
            this->direction = POS_180;
        } else if (key == VK_LEFT) {
            next->x = head->x - 1;
            next->y = head->y;
            this->direction = POS_270;
        }
        return next;
    }

    void move(Apple &apple) {

        int key = this->translate(this->controller->getLastKey());
        Point *head = this->body.back();
        Point *next = this->getNextPoint(key, head);
        this->validate(next);
        this->body.push_back(next);
        if (!apple.isEaten(next)) {
            deleteTail();
        }

    }

    void validateBody(Point *next) {
        for (Point *point : this->body) {
            if (next->x == point->x && next->y == point->y) {
                throw 2;
            }
        }
    }

    void validate(Point *next) {
        this->screen->validatePoint(next);
        this->validateBody(next);
    }

};


#endif //SNAKE_CONSOLE_GAME_SNAKE_H
