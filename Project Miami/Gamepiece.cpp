#include "Gamepiece.h"
#include "Game.h"

Game* Gamepiece::gm;

Gamepiece::Gamepiece(){
    gm->addGP(this);
    x = 0.0;
    y = 0.0;
	px = 0.0;
	py = 0.0;

    init();
}

Gamepiece::~Gamepiece(){

}

void Gamepiece::init(){
    // Do something
}

void Gamepiece::update(int delta){
    // Do something
}

void Gamepiece::draw(){
    // Do something
}

void Gamepiece::setGM(Game* game){
    Gamepiece::gm = game;
}
