#include <iostream>
#include "Segment.h"
#include "Snake.h"
#include "Game.h"

int main() {
    std::cout << "Headers included successfully!" << std::endl;

    // Test creating a Segment
    Segment s(5, 10);
    std::cout << "Segment at (" << s.x << ", " << s.y << ")" << std::endl;

    // Test creating a Snake pointer (constructor not implemented yet)
    // Snake* snake = new Snake(0, 0);
    // delete snake;

    // Test creating a Game pointer (constructor not implemented yet)
    // Game* game = new Game(20, 20);
    // delete game;

    return 0;
}
