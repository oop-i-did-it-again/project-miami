#include "Wall.h"
#include "Game.h"

Wall::Wall( ){
   
    r = 1.0;
    g = 0.0;
    b = 0.0;
    x=-5;
    y=-5;
    radius = .05;
    length = .1;
    height = .1;        
    this->type = environment;
    gm->addWall(this);
}

Wall::~Wall(){
    gm->removeWall(this);
}

void Wall::draw(){
    
    if(this->type != door || this->type != nothing){

		glPointSize(length);
		glColor3d(1,1,1);	
		glBegin(GL_POLYGON);
		glVertex2f(x-length/2, y+height/2);
		glVertex2f(x+length/2, y+height/2);
		glVertex2f(x+length/2, y-height/2);
		glVertex2f(x-length/2, y-height/2);
		glEnd();	
		glColor3d(0,0,0);
    }
}
