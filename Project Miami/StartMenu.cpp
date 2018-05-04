#include "StartMenu.h"
#include <iostream>

StartMenu::StartMenu(){
	init();
}

void StartMenu::init(){
   background[0]=new TexRect("assets/title1.bmp",1,1,-1,1,2,2);
   background[1]=new TexRect("assets/title2.bmp",1,1,-1,1,2,2);
   background[2]=new TexRect("assets/title3.bmp",1,1,-1,1,2,2);
   background[3]=new TexRect("assets/title4.bmp",1,1,-1,1,2,2);
   quality = 0;
}

void StartMenu::draw(){
	background[quality]->draw();
	//glBegin(GL_LINE);
}

void StartMenu::changeQuality(int q){
	quality = q;
}

void StartMenu::checkKey(unsigned char key){
	if(key == 's' && quality<3)
		quality++;
	if(key == 'w' && quality>0)
		quality--;
}