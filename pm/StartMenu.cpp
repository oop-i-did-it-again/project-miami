#include "StartMenu.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

StartMenu::StartMenu(){
	init();
}

void StartMenu::init(){
   winscreen = new TexRect("assets/winscreen.bmp",1,1,-1,1,2,2);
   background[0]=new TexRect("assets/title1.bmp",1,1,-1,1,2,2);
   background[1]=new TexRect("assets/title2.bmp",1,1,-1,1,2,2);
   background[2]=new TexRect("assets/title3.bmp",1,1,-1,1,2,2);
   background[3]=new TexRect("assets/title4.bmp",1,1,-1,1,2,2);
   background[4]=new TexRect("assets/title5.bmp",1,1,-1,1,2,2);
   quality = 0;
}

void StartMenu::draw(){
	background[quality]->draw();
	
}

void StartMenu::checkKey(unsigned char key){
	if(key == 's' && quality<4)
		quality++;
	if(key == 'w' && quality>0)
		quality--;
}

void StartMenu::update(){
}