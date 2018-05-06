#include "Wall.h"


Wall::Wall( ){
   
    r = 1.0;
    g = 0.0;
    b = 0.0;
x=-5;
y=-5;
    
    radius = .05;
    length = .1;
    height = .1;        
    
}

Wall::~Wall(){
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

	



	
	
	

    //MAYBE A TEXTURE
    /*
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)*/
}
