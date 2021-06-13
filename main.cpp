#include "Screen.h"
#include "Snake.h"
#include <sys/time.h>



using namespace std;

int64_t currentTimeMillis() {
    struct timeval time;
    gettimeofday(&time, NULL);
    int64_t s1 = (int64_t)(time.tv_sec) * 1000;
    int64_t s2 = (time.tv_usec / 1000);
    return s1 + s2;
}
int main() {
    Screen screen;
    Controller controller;
    Snake snake(screen, controller);


    while (snake.getSnakeAlive() == true) {

        int lastRenderTime = currentTimeMillis();
        int currentTime = lastRenderTime;

        while ((currentTime = currentTimeMillis()) <= (lastRenderTime + 350)) {
            controller.readKey();
            if (controller.getLastKey() == VK_ESCAPE){
                exit(0);
            }
        }

        lastRenderTime = currentTime;

        screen.clear();
        snake.move();
        snake.render();

        screen.render();



    }

    return 0;
}
