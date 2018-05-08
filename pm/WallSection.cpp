#include "WallSection.h"


WallSection::WallSection(double x1, double y1, double length, char direction ){
    xx = x1;
    yy = y1;
    llength = length;
    cdir = direction;
    
    if (direction == 'x'){
    for (double i =0; i <=length; i+=.01){
            Wall* wall = new Wall();
            wall->x = x1 +i;
            wall->y = y1 ;
            //section.push_back(wall);
    }
    }
     if (direction == 'y'){
    for (double i =0; i <=length; i+=.01){
            Wall* wall = new Wall();
            wall->x = x1;
            wall->y = y1+i;
            //section.push_back(wall);
    }
    }       
        
    
}

WallSection::~WallSection(){

}

void WallSection::draw(){
    
    

    
}
