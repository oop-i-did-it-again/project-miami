#include "Actor.h"

Actor::Actor(){
    init();
}

Actor::~Actor(){

}

void Actor::init(){
    vx = 0.0;
    vy = 0.0;
    health = 100;
    speed = 0.001;
}