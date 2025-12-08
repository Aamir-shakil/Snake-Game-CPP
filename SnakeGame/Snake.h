#pragma once
#include "Segment.h"

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
private:
    Segment* body;   // Dynamic array of segments
    int length;      // Current number of segments
    int capacity;    // Allocated memory
    Direction dir;

public:
    Snake(int startX, int startY);
    ~Snake();

    void move();
    void grow();
    void changeDirection(Direction newDir);

    Segment getHead() const;
    int getLength() const { return length; }
    const Segment* getBody() const { return body; }
};


