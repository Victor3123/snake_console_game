#include "Screen.h"
#include "Snake.h"
#include "Controller.h"
#include <ctime>
#include <windows.h>


using namespace std;

int main() {
    Screen screen;
    Controller controller;
    Snake snake(screen);


    while (true) {

        screen.clear();

        snake.render();

        screen.render();

        int lastRenderTime = time(0);
        int currentTime = lastRenderTime;
        while (currentTime = time(0) <= lastRenderTime) {
            if (GetKeyState(VK_ESCAPE) & 0x8000) {
                exit(0);
            } else {
                Sleep(5);
            }
        }

        lastRenderTime = currentTime;


    }
    return 0;
}
