#pragma once
#include "GameObject.h"

class Poison : public GameObject {
public:
    Poison(int w, int h);
    void onCollision(Snake* snake, int& score, bool& running) override;
    char getSymbol() const override;
};
