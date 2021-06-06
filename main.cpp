#include "Screen.h"
#include "Snake.h"


using namespace std;

int main()
{
    Screen *screen = new Screen();
    screen->clear();

    Snake *snake = new Snake(*screen);
    snake->render();

    screen->render();

    Sleep(10000);

    return 0;
}
