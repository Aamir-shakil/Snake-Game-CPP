#include "Game.h"
#include <iostream>

// Constructor
Game::Game(int w, int h) : width(w), height(h), running(true), foodX(0), foodY(0) {
    snake = nullptr; 
}

// Destructor
Game::~Game() {
    delete snake;
    snake = nullptr;
}

// Stub functions
void Game::run() {
    std::cout << "Game run placeholder\n";
}

void Game::update() {
    std::cout << "Game update placeholder\n";
}

void Game::render() {
    std::cout << "Game render placeholder\n";
}

void Game::processInput() {
    std::cout << "Game processInput placeholder\n";
}

void Game::placeFood() {
    std::cout << "Game placeFood placeholder\n";
}
