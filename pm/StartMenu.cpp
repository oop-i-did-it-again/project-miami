#include "StartMenu.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

StartMenu::StartMenu(){
	init();
}

void StartMenu::init(){
	 srand (time(NULL));
   background[0]=new TexRect("assets/title1.bmp",1,1,-1,1,2,2);
   background[1]=new TexRect("assets/title2.bmp",1,1,-1,1,2,2);
   background[2]=new TexRect("assets/title3.bmp",1,1,-1,1,2,2);
   background[3]=new TexRect("assets/title4.bmp",1,1,-1,1,2,2);
   background[4]=new TexRect("assets/title5.bmp",1,1,-1,1,2,2);
   quality = rand() % 4;
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
	if(key == 's' && quality<4)
		quality++;
	if(key == 'w' && quality>0)
		quality--;
}

void StartMenu::update(){
	quality++;
	if(quality > 4)
		quality = 0;
}