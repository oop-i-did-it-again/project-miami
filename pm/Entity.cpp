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
	model->draw();
}

void Entity::updateColor(){
	
}
