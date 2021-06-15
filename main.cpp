#include "Screen.h"
#include "Snake.h"
#include <sys/time.h>
#include <windows.h>


using namespace std;

int64_t currentTimeMillis() {

    struct timeval time;
    gettimeofday(&time, NULL);
    int64_t s1 = (int64_t) (time.tv_sec) * 1000;
    int64_t s2 = (time.tv_usec / 1000);
    return s1 + s2;
}

int main() {
    ShowCursor(false);
    Screen screen;
    Controller controller;
    Snake snake(screen, controller);


    try {
        while (snake.getSnakeAlive() == true) {
            int lastRenderTime = currentTimeMillis();
            int currentTime = lastRenderTime;

            while ((currentTime = currentTimeMillis()) <= (lastRenderTime + 350)) {
                controller.readKey();
                if (controller.getLastKey() == VK_ESCAPE) {
                    exit(0);
                }
            }

            lastRenderTime = currentTime;

            screen.clear();
            snake.move();
            snake.render();

            screen.render();
        }
    } catch (int e) {
        if(e == 1){
            cout << "\nOh...the snake went out of the field\n to quit the game press any key...\n";
            system("pause");
        }
        if(e == 2){
            cout << "\nOps...The snake pierced itself\n to quit the game press any key...\n";
            system("pause");
        }
    }

    return 0;
}
