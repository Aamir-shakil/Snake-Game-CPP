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

    // Constructor: initializes a snake at the given starting coordinates
    Snake(int startX, int startY);

    // Destructor: frees dynamically allocated memory for the snake body
    ~Snake();

    void move();
    void grow();
    void changeDirection(Direction newDir);

    // Returns a pointer to the head segment
    Segment* getHeadPtr() { return &body[0]; }

    // Returns a pointer to a specific segment by index
    Segment* getSegmentPtr(int index) { return &body[index]; }

    // Returns the current length of the snake
    int getLength() const { return length; }

    // Checks whether the snake has collided with itself
    bool hasCollidedWithSelf() const;
};
