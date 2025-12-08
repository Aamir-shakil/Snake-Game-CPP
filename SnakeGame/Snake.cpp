#include "Snake.h"
#include <iostream> 

// Constructor
Snake::Snake(int startX, int startY) {
    capacity = 10; // initial allocated size
    length = 1;    // start with head only
    body = new Segment[capacity]; // allocate dynamic array
    body[0] = Segment(startX, startY);
    dir = Direction::RIGHT;

    std::cout << "Snake created at (" << startX << ", " << startY << ")\n";
}

// Destructor
Snake::~Snake() {
    delete[] body;
    body = nullptr;
    length = 0;
    capacity = 0;

    std::cout << "Snake destroyed and memory cleaned up\n";
}

// Grow snake by 1 segment
void Snake::grow() {
    if (length >= capacity) {
        // Double the capacity
        int newCapacity = capacity * 2;
        Segment* newBody = new Segment[newCapacity];

        // Copy old segments
        for (int i = 0; i < length; i++) {
            newBody[i] = body[i];
        }

        delete[] body;   // free old memory
        body = newBody;
        capacity = newCapacity;
    }

    // Add new segment at the end (same as last segment for now)
    body[length] = body[length - 1];
    length++;

    std::cout << "Snake grew to length " << length << "\n";
}

// Move the snake one step in current direction
void Snake::move() {
    // Shift segments from tail to head
    for (int i = length - 1; i > 0; i--) {
        body[i] = body[i - 1];
    }

    // Move head based on direction
    switch (dir) {
    case Direction::UP:    body[0].y--; break;
    case Direction::DOWN:  body[0].y++; break;
    case Direction::LEFT:  body[0].x--; break;
    case Direction::RIGHT: body[0].x++; break;
    }
}

// Change direction
void Snake::changeDirection(Direction newDir) {
    dir = newDir;
}

// Get head segment
Segment Snake::getHead() const {
    return body[0];
}
