#pragma once
#include "GameObject.h"

/**
 * Food represents a consumable game object.
 * It inherits from GameObject and implements polymorphic behaviour by
 * defining its own collision logic and visual representation.
 * When the snake collides with food, the snake grows and the score increases.
 */
class Food : public GameObject {
public:
    Food(int w, int h);
    void onCollision(Snake* snake, int& score, bool& running) override;
    char getSymbol() const override;
};
