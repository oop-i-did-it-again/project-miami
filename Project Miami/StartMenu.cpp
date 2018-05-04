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
	/*float y_rand = 0;
	glColor3d(1,1,1);
	for(int i=0;i<4;i++){
		glBegin(GL_LINE);
		y_rand = float(rand()%100)/1000;
		y_rand=0;
		glVertex2f(0,y_rand);
		glVertex2f(.5,y_rand);
		glEnd();
		std::cout<<"WEE\n";
	}*/
	background[quality]->draw();
}

void StartMenu::checkKey(unsigned char key){
	if(key == 's' && quality<3)
		quality++;
	if(key == 'w' && quality>0)
		quality--;
}