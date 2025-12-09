#pragma once
#include "Segment.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
private:
    Segment* body; // dynamic array
    int capacity;
    int length;
    Direction dir;

public:
    Snake(int startX, int startY);
    ~Snake();

    void move();
    void grow();
    void changeDirection(Direction newDir);

    Segment getHead() const;
    bool hasCollidedWithSelf() const;

    int getLength() const { return length; }
    Segment getSegment(int i) const { return body[i]; }
};
