#include "DeathMenu.h"
#include <iostream>

DeathMenu::DeathMenu(){
	popup = new TexRect("assets/deathscreen.bmp",1,1,-.7,.7,1.4,1);
}

void DeathMenu::draw(){
	popup->draw();
}