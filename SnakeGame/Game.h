#pragma once
#include "Snake.h"
#include "GameObject.h"
#include <vector>
#include <memory>

class Game {
private:
    std::unique_ptr<Snake> snake;
    int width;
    int height;
    bool running;
    int score;

    std::vector<GameObject*> objects;

public:
    Game(int w, int h);
    ~Game();

    void run();
    void update();
    void render();
    void processInput();
    void showInstructions();
};
