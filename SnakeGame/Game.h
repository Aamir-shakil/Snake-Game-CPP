#pragma once
#include "Snake.h"
#include <memory>

/**
 * Game class manages the main game logic and state.
 * It handles the snake, food, poison, input, rendering, and game loop.
 * Uses pointers and a dynamic array to manage objects on the board.
 */
class Game {
private:
	std::unique_ptr<Snake> snake; // smart pointer to Snake object
    int width;
    int height;
    bool running;
	int score;
    int foodX;
    int foodY;

    // Dynaimc Array for posion
    Segment* pPoison;    
    int poisonCount;      
    int poisonCapacity;   

public:
	Game(int w, int h);// constructor
	~Game();// destructor

    void run();
    void update();
    void render();
    void processInput();
    void placeFood();
    void placePoison(int x, int y);
    void showInstructions();

};
#pragma once
