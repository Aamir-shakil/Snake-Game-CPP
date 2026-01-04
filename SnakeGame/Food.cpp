#include "Food.h"
#include <cstdlib>

// Constructs a Food object at a random position on the board
Food::Food(int w, int h) : GameObject(w, h) {
    pos.x = rand() % boardWidth;
    pos.y = rand() % boardHeight;
}

// Returns the character used to display food
char Food::getSymbol() const { return '*'; }

// Handles collision between the snake and food
void Food::onCollision(Snake* snake, int& score, bool& running) {
    snake->grow();
    score++;
    pos.x = rand() % boardWidth;
    pos.y = rand() % boardHeight;
}
