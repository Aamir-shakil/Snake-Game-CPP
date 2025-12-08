#include "Game.h"
#include <iostream>
#include <conio.h>  // for _kbhit() and _getch()
#include <cstdlib>  // for rand()
#include <ctime>
#include <Windows.h>

// Constructor
Game::Game(int w, int h) : width(w), height(h), running(true), foodX(0), foodY(0) {
    snake = new Snake(width / 2, height / 2);
    std::srand(static_cast<unsigned>(std::time(nullptr))); // seed random
    placeFood();
}

// Destructor
Game::~Game() {
    delete snake;
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
        char c = _getch();
        switch (c) {
        case 72: snake->changeDirection(Direction::UP); break;
        case 80: snake->changeDirection(Direction::DOWN); break;
        case 75: snake->changeDirection(Direction::LEFT); break;
        case 77: snake->changeDirection(Direction::RIGHT); break;
        }
    }
}

// Update game logic
void Game::update() {
    snake->move();

    // Check if snake ate food
    Segment head = snake->getHead();
    if (head.x == foodX && head.y == foodY) {
        snake->grow();
        placeFood();
    }

    // Check wall collision (simple)
    if (head.x < 0 || head.x >= width || head.y < 0 || head.y >= height) {
        running = false;
        std::cout << "Game Over! Hit the wall.\n";
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
                Segment s = snake->getBody()[i];
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
