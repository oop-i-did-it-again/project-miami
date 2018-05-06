#include "WallSection.h"


WallSection::WallSection(double x1, double y1, double length, char direction ){
    
    
    if (direction == 'x'){
    for (double i =0; i <=length; i+=.01){
            Wall* wall = new Wall();
            wall->x = x1 +i;
            wall->y = y1 ;
            wall->type = environment;
            section.push_back(wall);
    }
    }
     if (direction == 'y'){
    for (double i =0; i <=length; i+=.01){
            Wall* wall = new Wall();
            wall->x = x1;
            wall->y = y1+i ;
            wall->type = environment;
            section.push_back(wall);
    }
    }       
        
    
}

WallSection::~WallSection(){
}

void WallSection::draw(){
    for(int i=0; i < section.size(); i++){

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
 
