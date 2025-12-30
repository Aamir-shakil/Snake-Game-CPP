#include "Snake.h"
#include <iostream>

Snake::Snake(int startX, int startY) {
    capacity = 100;
    body = new Segment[capacity];
    length = 1;

    body[0] = { startX, startY };
    dir = RIGHT; // default direction
}

Snake::~Snake() {
    delete[] body;
}

void Snake::changeDirection(Direction newDir) {
    // Prevent reversing direction directly
    if ((dir == UP && newDir == DOWN) ||
        (dir == DOWN && newDir == UP) ||
        (dir == LEFT && newDir == RIGHT) ||
        (dir == RIGHT && newDir == LEFT))
        return;

    dir = newDir;
}

void Snake::move() {
    // Move body backward
    for (int i = length - 1; i > 0; i--) {
        body[i] = body[i - 1];
    }

    // Move head
    switch (dir) {
    case UP:    body[0].y--; break;
    case DOWN:  body[0].y++; break;
    case LEFT:  body[0].x--; break;
    case RIGHT: body[0].x++; break;
    }
}

void Snake::grow() {
    if (length < capacity) {
        body[length] = body[length - 1];
        length++;
    }
}

Segment Snake::getHead() const {
    return body[0];
}

Segment* Snake::getSegmentPtr(int index) {
    return &body[index];
}


Segment* Snake::getHeadPtr() {
    return &body[0];   // 
}

Segment* Snake::getBodyPtr() {
    return body;       // raw pointer to dynamic array
}

Segment* Snake::getHeadPtr() {
    return &body[0];
}



bool Snake::hasCollidedWithSelf() const {
    if (length <= 2) return false;

    Segment head = body[0];
    for (int i = 1; i < length; i++) {
        if (body[i].x == head.x && body[i].y == head.y)
            return true;
    }

    return false;
}
