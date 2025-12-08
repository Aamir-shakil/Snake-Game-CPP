#include <iostream>
#include "Segment.h"
#include "Snake.h"
#include "Game.h"

int main() {
    Snake snake(5, 5);

    snake.grow();
    snake.grow();

    Segment head = snake.getHead();
    std::cout << "Snake head at (" << head.x << ", " << head.y << ")\n";

    snake.move();
    head = snake.getHead();
    std::cout << "Snake moved to (" << head.x << ", " << head.y << ")\n";

    return 0;
}
