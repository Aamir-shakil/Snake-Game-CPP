#include "Food.h"
#include <cstdlib>

Food::Food(int w, int h) : GameObject(w, h) {
    pos.x = rand() % boardWidth;
    pos.y = rand() % boardHeight;
}

char Food::getSymbol() const { return '*'; }

void Food::onCollision(Snake* snake, int& score, bool& running) {
    snake->grow();
    score++;
    pos.x = rand() % boardWidth;
    pos.y = rand() % boardHeight;
}
