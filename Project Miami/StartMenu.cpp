#include "StartMenu.h"
#include <iostream>

StartMenu::StartMenu(){
	init();
}

void StartMenu::init(){
    background = new TexRect("retro-title.bmp",1,1,0,0,1,1);
}

void StartMenu::draw(){
	std::cout<<"CALLED\n";
	background->draw();
}