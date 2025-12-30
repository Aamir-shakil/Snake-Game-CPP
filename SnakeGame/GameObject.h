#pragma once
#include "Segment.h"
#include "Snake.h"

class GameObject {
protected:
    Segment pos;
    int boardWidth;
    int boardHeight;

public:
    GameObject(int w, int h) : boardWidth(w), boardHeight(h) {}
    virtual ~GameObject() = default;

    virtual void onCollision(Snake* snake, int& score, bool& running) = 0;
    virtual char getSymbol() const = 0;
    Segment getPosition() const { return pos; }
};
