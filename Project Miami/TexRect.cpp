#include "TexRect.h"

static TexRect* textures;

TexRect::TexRect (const char* filename, int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    
    RgbImage theTex( filename );
    
    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );
    
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTex.GetNumCols(), theTex.GetNumRows(),GL_RGB, GL_UNSIGNED_BYTE, theTex.ImageData());
    //this->texture_map_id = texture_id;
    //this
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    pos_x=pos_y=1;
    sides=1;
    textures = this;
}

void TexRect::draw(){
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    
    glBegin(GL_QUADS);
    
    glTexCoord2f(pos_x-sides,pos_y-sides);
    glVertex2f(x, y - h);
    
    glTexCoord2f(pos_x-sides, pos_y);
    glVertex2f(x, y);
    
    glTexCoord2f(pos_x,pos_y);
    glVertex2f(x+w, y);
    
    glTexCoord2f(pos_x, pos_y-sides);
    glVertex2f(x+w, y - h);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    
}

bool TexRect::contains(float mx, float my){
    return mx >= x && mx <= x+w && my <= y && my >= y - h;
}




