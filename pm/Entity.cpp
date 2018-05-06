#include "Entity.h"

Entity::Entity(){
    radius = .06;
}

Entity::~Entity(){

}


void Entity::draw(){
	model->draw();
}

void Entity::updateColor(int r,int g, int b){
	model->updateColor(r,g,b);
}
