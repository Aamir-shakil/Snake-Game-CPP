#include "Game.h"
#include <iostream>
#include <conio.h>  // for _kbhit() and _getch()
#include <cstdlib>  // for rand()
#include <ctime>
#include <Windows.h>

// Constructor
Game::Game(int w, int h) : width(w), height(h), running(true), score(0) {
    snake = std::make_unique<Snake>(w / 2, h / 2);
    placeFood();
    poisonCapacity = 5;
    poisonCount = 0;
    pPoison = new Segment[poisonCapacity];
    // Add 3 poison items at random positions
    for (int i = 0; i < 3; i++) {
        int x = rand() % width;
        int y = rand() % height;
        placePoison(x, y);
    }

}


// Destructor
Game::~Game() {
    snake = nullptr;
	delete[] pPoison; //free dynamic posiaon array memory
}

// Place food randomly on board
void Game::placeFood() {
    foodX = std::rand() % width;
    foodY = std::rand() % height;
}

void Game::placePoison(int x, int y) {
    // resize if needed
    if (poisonCount >= poisonCapacity) {
        int newCapacity = poisonCapacity * 2;
        Segment* pNewPoison = new Segment[newCapacity];

        for (int i = 0; i < poisonCount; i++)
            pNewPoison[i] = pPoison[i];

        delete[] pPoison;
        pPoison = pNewPoison;
        poisonCapacity = newCapacity;
    }

    pPoison[poisonCount] = { x, y };
    poisonCount++;
}


// Process simple input (WASD)
void Game::processInput() {
    if (_kbhit()) {
        int c = _getch();

        // Arrow keys send two characters (224 then code)
        if (c == 224) {
            c = _getch();  // get the actual arrow key code

            switch (c) {
            case 72: snake->changeDirection(UP); break;    // Up arrow
            case 80: snake->changeDirection(DOWN); break;  // Down arrow
            case 75: snake->changeDirection(LEFT); break;  // Left arrow
            case 77: snake->changeDirection(RIGHT); break; // Right arrow
            }
        }
    }
}


// Update game logic
void Game::update() {
    snake->move();

    // Wall collision
    Segment* pHead = snake->getHeadPtr();   // pointer variable 

    if (pHead->x < 0 || pHead->x >= width ||
        pHead->y < 0 || pHead->y >= height) {
        running = false;
        return;
    }

	//Collision with poison
    for (int i = 0; i < poisonCount; i++) {
        Segment* pPoisonSeg = &pPoison[i];
        if (pHead->x == pPoisonSeg->x && pHead->y == pPoisonSeg->y) {
            running = false; // snake hits poison → game over
            return;
        }
    }


    // Self-collision
    if (snake->hasCollidedWithSelf()) {
        running = false;
        return;
    }

    // Food collision
    if (pHead->x == foodX && pHead->y == foodY) {
        snake->grow();
        score++;
        placeFood();
    }
}


// Render simple terminal output
void Game::render() {
    system("cls"); // clear screen (Windows only)

    // Top border
    std::cout << '+';
    for (int x = 0; x < width; x++) std::cout << '-';
    std::cout << "+\n";

    for (int y = 0; y < height; y++) {
        std::cout << '|'; // left border
        for (int x = 0; x < width; x++) {
            bool printed = false;

            // Draw snake
            Segment* pHead = snake->getHeadPtr();   // pointer to head (once per frame)

            for (int i = 0; i < snake->getLength(); i++) {
                Segment* pBody = snake->getSegmentPtr(i);  // pointer with p-prefix

                if (pBody->x == x && pBody->y == y) {

                    // Pointer identity comparison (HEAD vs BODY)
                    if (pBody == pHead) {
                        std::cout << "@";   // head
                    }
                    else {
                        std::cout << "o";   // body
                    }

                    printed = true;
                    break;
                }
            }


            // Draw food
            if (!printed && x == foodX && y == foodY) {
                std::cout << '*';
                printed = true;
            }

			//Draw poison
            for (int i = 0; i < poisonCount; i++) {
                Segment* pPoisonSeg = &pPoison[i];
                if (pPoisonSeg->x == x && pPoisonSeg->y == y) {
                    std::cout << "X";  // symbol for poison
                    printed = true;
                    break;
                }
            }

            // Empty space
            if (!printed) std::cout << ' ';
        }
        std::cout << "|\n"; // right border
    }

    // Bottom border
    std::cout << '+';
    for (int x = 0; x < width; x++) std::cout << '-';
    std::cout << "+\n";

    std::cout << "Score: " << score << "\n";

    // If game over
    if (!running) {
        std::cout << "\n    GAME OVER! Final Score: " << score << "\n";
    }
}



// Game loop
void Game::run() {
    while (running) {
        processInput();
        update();
        render();
        Sleep(150); // simple delay (ms)
    }
}
