#include "Entity.h"

Entity::Entity(){
    radius = .06;
    r = 1.0;
    g = 0.0;
    b = 0.0;
}

Entity::~Entity(){

}


void Entity::draw(){
    
	/*if(this->type == hero){
		glColor3d(0,1,1);
        glBegin(GL_POLYGON);
        for (double i = 0; i <2*3.141692;i+=3.151592/75)
            glVertex2f(cos(i)*radius+x,sin(i)*radius+y);
        glEnd();
		glColor3d(0,0,0);	
		
	}
	else {
		glColor3d(1,1,1);
        glBegin(GL_POLYGON);
        for (double i = 0; i <2*3.141692;i+=3.151592/75)
            glVertex2f(cos(i)*radius+x,sin(i)*radius+y);
        glEnd();
		glColor3d(0,0,0);

    }*/
	model->draw();



	
	
	

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
