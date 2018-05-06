#include "DeathMenu.h"
#include <iostream>

DeathMenu::DeathMenu(){
	popup = new TexRect("assets/deathscreen.bmp",1,1,-1,1,2,2);
}

void DeathMenu::draw(){
	popup->draw();
}