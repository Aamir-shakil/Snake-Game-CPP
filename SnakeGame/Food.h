#pragma once
#include "GameObject.h"

class Food : public GameObject {
public:
    Food(int w, int h);
    void onCollision(Snake* snake, int& score, bool& running) override;
    char getSymbol() const override;
};
