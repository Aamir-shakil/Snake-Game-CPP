#include "Game.h"
#include "Food.h"
#include "Poison.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

// Constructor: sets up the game board, snake, and game objects
Game::Game(int w, int h)
    : width(w), height(h), running(true), score(0)
{
    srand(static_cast<unsigned>(time(nullptr)));

    // Create snake at center using smart pointer for automatic memory management
    snake = std::make_unique<Snake>(w / 2, h / 2);

    // Add one food
    objects.push_back(new Food(width, height));

    // Add 3 poison
    for (int i = 0; i < 3; i++) {
        objects.push_back(new Poison(width, height));
    }
}

// Destructor: cleans up dynamically allocated GameObjects
Game::~Game() {
    for (auto obj : objects) delete obj;
    objects.clear();
}

// Displays instructions to the player
void Game::showInstructions() {
    system("cls");
    std::cout << "=== SNAKE GAME ===\n\n";
    std::cout << "Use arrow keys to move.\n";
    std::cout << "Eat '*' to grow.\n";
    std::cout << "Avoid walls, poison 'X', and yourself.\n";
    std::cout << "Press any key to start...\n";
    (void)_getch();
}

void Game::processInput() {
    if (_kbhit()) {
        int c = _getch();
        if (c == 224) {
            c = _getch();
            switch (c) {
            case 72: snake->changeDirection(UP); break;
            case 80: snake->changeDirection(DOWN); break;
            case 75: snake->changeDirection(LEFT); break;
            case 77: snake->changeDirection(RIGHT); break;
            }
        }
    }
}


// Updates game state: snake movement, collision detection, and scoring
void Game::update() {
    snake->move();

    Segment* pHead = snake->getHeadPtr();

    // Wall collision
    if (pHead->x < 0 || pHead->x >= width ||
        pHead->y < 0 || pHead->y >= height) {
        running = false;
        return;
    }

    // Self collision
    if (snake->hasCollidedWithSelf()) {
        running = false;
        return;
    }

    // Object collisions
    for (auto obj : objects) {
        Segment pos = obj->getPosition();
        if (pHead->x == pos.x && pHead->y == pos.y) {
            obj->onCollision(snake.get(), score, running);
            if (!running) return;
        }
    }
}

// Renders the game board, snake, and objects to console
void Game::render() {
    system("cls");

    std::cout << '+';
    for (int x = 0; x < width; x++) std::cout << '-';
    std::cout << "+\n";

    for (int y = 0; y < height; y++) {
        std::cout << '|';
        for (int x = 0; x < width; x++) {
            bool printed = false;

            Segment* pHead = snake->getHeadPtr();
            for (int i = 0; i < snake->getLength(); i++) {
                Segment* seg = snake->getSegmentPtr(i);
                if (seg->x == x && seg->y == y) {
                    std::cout << (seg == pHead ? '@' : 'o');
                    printed = true;
                    break;
                }
            }
            
            // Render polymorphic game objects
            for (auto obj : objects) {
                Segment pos = obj->getPosition();
                if (!printed && pos.x == x && pos.y == y) {
                    std::cout << obj->getSymbol();
                    printed = true;
                    break;
                }
            }

            if (!printed) std::cout << ' ';
        }
        std::cout << "|\n";
    }

    std::cout << '+';
    for (int x = 0; x < width; x++) std::cout << '-';
    std::cout << "+\n";

    std::cout << "Score: " << score << "\n";

    if (!running)
        std::cout << "\nGAME OVER! Final Score: " << score << "\n";
}

// Runs the main game loop
void Game::run() {
    showInstructions();
    while (running) {
        processInput();
        update();
        render();
        Sleep(150);
    }
}
