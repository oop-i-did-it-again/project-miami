#include "Actor.h"

Actor::Actor(){
    init();
}

Actor::~Actor(){

}

void Actor::init(){
    health = 100;
    speed = 0.1;
    r = 0.5;
    g = 0.5;
    b = 0.5;
}

void Actor::update(int delta){
    x += 0.001 * delta;
    if(x > 1)
        x = -1;
}

void Actor::draw(){
    // Draw something
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}