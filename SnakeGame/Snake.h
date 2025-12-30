#pragma once
#include "Segment.h"
/**
 * Snake class manages the snake’s body, movement, and direction.
 * Uses a dynamic array of Segment objects to represent the body.
 */
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
private:
    Segment* body; // dynamic array of snake segments
    int capacity;
    int length;
    Direction dir;

public:
    Snake(int startX, int startY); // constructor
    ~Snake(); //destructor

    Segment* getHeadPtr();
    Segment* getBodyPtr();
    void move();
    void grow();
    void changeDirection(Direction newDir);
    Segment* getSegmentPtr(int index);



    Segment getHead() const;
    bool hasCollidedWithSelf() const;

    int getLength() const { return length; }
    Segment getSegment(int i) const { return body[i]; }
};
