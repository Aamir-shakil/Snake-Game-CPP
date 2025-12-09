#pragma once
#include "Snake.h"

class Game {
private:
    Snake* snake;
    int width;
    int height;
    bool running;
	int score;
    int foodX;
    int foodY;

public:
    Game(int w, int h);
    ~Game();

    void run();
    void update();
    void render();
    void processInput();

    void placeFood();
};
#pragma once
