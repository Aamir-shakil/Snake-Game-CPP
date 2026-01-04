#include "Poison.h"
#include <cstdlib>

// Initialises the poison at a random position within the game board
Poison::Poison(int w, int h) : GameObject(w, h) {
    pos.x = rand() % boardWidth;
    pos.y = rand() % boardHeight;
}

// Returns the symbol used to display poison on the board
char Poison::getSymbol() const { return 'X'; }

// Terminates the game when the snake collides with poison
void Poison::onCollision(Snake* snake, int& score, bool& running) {
    running = false; // game ends
}
