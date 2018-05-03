#include "StartMenu.h"
#include <iostream>

StartMenu::StartMenu(){
	init();
}

void StartMenu::init(){
    background = new TexRect("retro.bmp",1,1,-1,1,2,2);
}

void StartMenu::draw(){
	background->draw();
}