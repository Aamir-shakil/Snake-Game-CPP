#include "Snake.h"

Snake::Snake(int startX, int startY) {
    capacity = 100;
    length = 1;
    body = new Segment[capacity];
    body[0] = { startX, startY };
    dir = RIGHT;
}

Snake::~Snake() {
    delete[] body;
}

void Snake::move() {
    for (int i = length - 1; i > 0; i--)
        body[i] = body[i - 1];

    switch (dir) {
    case UP: body[0].y--; break;
    case DOWN: body[0].y++; break;
    case LEFT: body[0].x--; break;
    case RIGHT: body[0].x++; break;
    }
}

void Snake::grow() {
    if (length < capacity) {
        body[length] = body[length - 1];
        length++;
    }
}

void Snake::changeDirection(Direction newDir) {
    if ((dir == UP && newDir != DOWN) ||
        (dir == DOWN && newDir != UP) ||
        (dir == LEFT && newDir != RIGHT) ||
        (dir == RIGHT && newDir != LEFT)) {
        dir = newDir;
    }
}

bool Snake::hasCollidedWithSelf() const {
    for (int i = 1; i < length; i++) {
        if (body[i].x == body[0].x && body[i].y == body[0].y)
            return true;
    }
    return false;
}
