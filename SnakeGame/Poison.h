#pragma once
#include "GameObject.h"

// Represents a harmful game object that penalises the player on collision
class Poison : public GameObject {
public:

    // Constructs a poison object within the game board bounds
    Poison(int w, int h);

    // Handles collision logic between the poison and the snake
    void onCollision(Snake* snake, int& score, bool& running) override;

    // Returns the character used to render poison on the board
    char getSymbol() const override;
};
