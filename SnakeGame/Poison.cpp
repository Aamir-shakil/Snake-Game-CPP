#include "Poison.h"
#include <cstdlib>

Poison::Poison(int w, int h) : GameObject(w, h) {
    pos.x = rand() % boardWidth;
    pos.y = rand() % boardHeight;
}

char Poison::getSymbol() const { return 'X'; }

void Poison::onCollision(Snake* snake, int& score, bool& running) {
    running = false; // game ends
}
