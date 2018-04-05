#include "Game.h"

Game::Game(){}

Game::~Game(){}

void Game::init(){
    // initializes every gamepiece
    // may not be necessary if we gamepieces calls their own inits
    // from their constructors. we shall see
}

void Game::update(long delta){
    // Calls update function from every gamepiece
    // delta is time elasped since last call in milliseconds
}

void Game::draw(){
    //  Calls draw function from every gamepiece
}