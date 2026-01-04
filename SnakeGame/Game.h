#pragma once
#include "Snake.h"
#include "GameObject.h"
#include <vector>
#include <memory>

// Controls the main game loop and manages core game state
class Game {
private:
    std::unique_ptr<Snake> snake;
    int width;
    int height;
    bool running;
    int score;

    // Collection of interactable game objects (Food, Poison, etc.)
    std::vector<GameObject*> objects;

public:
    Game(int w, int h);
    ~Game();

    // Main game loop
    void run();

    // Updates game logic (movement, collisions, scoring)
    void update();


    // Renders the game state to the console
    void render();

    // Handles user input
    void processInput();

    // Displays initial game instructions
    void showInstructions();
};
