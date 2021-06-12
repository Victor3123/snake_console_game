#include "Screen.h"
#include "Snake.h"
#include "Controller.h"
#include <ctime>
#include <windows.h>


using namespace std;

int main() {
    Screen screen;
    Controller controller;
    Snake snake(screen, controller);


    while (snake.getSnakeAlive() == true) {

        int lastRenderTime = time(0);
        int currentTime = lastRenderTime;
        while (currentTime = time(0) <= lastRenderTime) {
            controller.readKey();
            if (controller.getLastKey() == VK_ESCAPE){
                exit(0);
            }
        }

        lastRenderTime = currentTime;

        screen.clear();

        snake.render();

        screen.render();

        snake.move();

    }
    return 0;
}
