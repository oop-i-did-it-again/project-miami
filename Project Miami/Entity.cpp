#include "Entity.h"

Entity::Entity(){
    radius = 80;
    r = 0.5;
    g = 0.5;
    b = 0.5;
}


Entity::Entity(bool c){
    isCircle = c;
    r = 0.5;
    g = 0.5;
    b = 0.5;
    
    if(c){
    radius = 40;
    }
    else{
    length = 40;
    width = 40;        
    }
}

Entity::~Entity(){

}

void Entity::draw(){
    
    glPointSize(radius);
    // Draw something
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

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
