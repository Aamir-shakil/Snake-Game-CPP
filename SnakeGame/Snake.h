#pragma once
#include "Segment.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake {
private:
    Segment* body;
    int capacity;
    int length;
    Direction dir;

public:
    Snake(int startX, int startY);
    ~Snake();

    void move();
    void grow();
    void changeDirection(Direction newDir);

    Segment* getHeadPtr() { return &body[0]; }
    Segment* getSegmentPtr(int index) { return &body[index]; }
    int getLength() const { return length; }
    bool hasCollidedWithSelf() const;
};
