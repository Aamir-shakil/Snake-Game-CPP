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
}


// Destructor
Game::~Game() {
    snake = nullptr;
}

// Place food randomly on board
void Game::placeFood() {
    foodX = std::rand() % width;
    foodY = std::rand() % height;
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
    Segment head = snake->getHead();
    if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height) {
        running = false;
        return;
    }

    // Self-collision
    if (snake->hasCollidedWithSelf()) {
        running = false;
        return;
    }

    // Food collision
    if (head.x == foodX && head.y == foodY) {
        snake->grow();
        score++;
        placeFood();
    }
}


// Render simple terminal output
void Game::render() {
    system("cls"); // clear screen (Windows only)

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bool printed = false;

            // Print snake
            for (int i = 0; i < snake->getLength(); i++) {
                Segment s = snake->getSegment(i);  // <-- FIXED
                if (s.x == x && s.y == y) {
                    std::cout << "O";
                    printed = true;
                    break;
                }
            }

            // Print food
            if (!printed && x == foodX && y == foodY) {
                std::cout << "*";
                printed = true;
            }

            if (!printed) std::cout << ".";
        }
        std::cout << "\n";
    }

    std::cout << "Score: " << snake->getLength() - 1 << "\n";
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
