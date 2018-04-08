#include "Entity.h"

Entity::Entity(){
    radius = 40;
    r = 0.5;
    g = 0.5;
    b = 0.5;
}

Entity::~Entity(){

}

void Entity::draw(){
    
    glPointSize(radius);
    // Draw something
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    
}