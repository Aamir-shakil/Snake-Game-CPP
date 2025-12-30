#include <iostream>
#include "Segment.h"
#include "Snake.h"
#include "Game.h"

/**
 * @brief Entry point of the Snake game.
 *
 * Creates a Game object with a specified board size and starts the game loop.
 */
int main() {
    Game game(20, 10); // width x height
	game.run(); // start the game loop

	return 0; //program exits when the game ends 
}
