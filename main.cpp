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


    while (true) {

        screen.clear();

        snake.render();

        screen.render();

        int lastRenderTime = time(0);
        int currentTime = lastRenderTime;
        while (currentTime = time(0) <= lastRenderTime) {
            controller.readKey();
            if (controller.getLastKey() == VK_ESCAPE){
                exit(0);
            }
        }

        lastRenderTime = currentTime;


    }
    return 0;
}
