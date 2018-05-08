#include "Door.h"
#include "Game.h"

Door::Door( ){
   
    r = 1.0;
    g = 0.0;
    b = 0.0;

    
    radius = .07;

    length = .1;
    height = .2;        
    this->type = door;
    gm->addDoor(this);
}

Door::~Door(){
    gm->removeDoor(this);
}

void Door::draw(){
    
        if(open ==false){
		glPointSize(length);
		glColor3d(1,0,0);	
		glBegin(GL_POLYGON);
		glVertex2f(x-length/2, y+height/2);
		glVertex2f(x+length/2, y+height/2);
		glVertex2f(x+length/2, y-height/2);
		glVertex2f(x-length/2, y-height/2);
		glEnd();	
		glColor3d(0,0,0);
        }
        else{
        glPointSize(length);
		glColor3d(1,0,0);	
		glBegin(GL_POLYGON);
		glVertex2f(x-length/2, y+height/2);
		glVertex2f(x+length/4, y+height/2);
		glVertex2f(x+length/4, y-height/2);
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
