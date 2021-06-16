#include <sys/time.h>
#include <fstream>
#include "Apple.h"
#include "Screen.h"
#include "Snake.h"


using namespace std;

int64_t currentTimeMillis() {

    struct timeval time;
    gettimeofday(&time, NULL);
    int64_t s1 = (int64_t) (time.tv_sec) * 1000;
    int64_t s2 = (time.tv_usec / 1000);
    return s1 + s2;
}

int main() {
    srand(time(0));

    ShowCursor(false);
    Screen screen;
    Controller controller;
    Snake snake(screen, controller);
    Apple apple(screen, new Point(13, 10));


    try {
        while (true) {


            int lastRenderTime = currentTimeMillis();
            int currentTime = lastRenderTime;

            while ((currentTime = currentTimeMillis()) <= (lastRenderTime + 300)) {
                controller.readKey();
                if (controller.getLastKey() == VK_ESCAPE) {
                    exit(0);
                }
            }

            lastRenderTime = currentTime;

            screen.clear();
            snake.move(apple);
            snake.render();
            apple.render();
            screen.render();
            cout << "\nTo quit Press ESC;  Current score is " << snake.body.size() - 3;
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
