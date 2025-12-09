#pragma once
#include "Snake.h"
#include <memory>

class Game {
private:
    std::unique_ptr<Snake> snake;;
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
