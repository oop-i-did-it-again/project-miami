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

            model->changePos(x-.07, y+.05);
                model->draw();
   

    }
}
