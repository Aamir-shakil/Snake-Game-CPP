#pragma once
#include "Segment.h"
#include "Snake.h"

// Abstract base class representing any object that can exist on the game board
class GameObject {
protected:
    Segment pos;
    int boardWidth;
    int boardHeight;

public:
    // Constructs a game object with access to board dimensions
    GameObject(int w, int h) : boardWidth(w), boardHeight(h) {}

    // Virtual destructor to allow safe polymorphic deletion
    virtual ~GameObject() = default;

    // Handles interaction between the object and the snake
    virtual void onCollision(Snake* snake, int& score, bool& running) = 0;

    // Returns the symbol used to render the object
    virtual char getSymbol() const = 0;

    // Returns the current position of the object
    Segment getPosition() const { return pos; }
};
