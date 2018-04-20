#ifndef TexRectssss_h
#define TexRectssss_h

#include <GL/freeglut.h>


#include "RgbImage.h"
    

class TexRect{
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;
public:
    TexRect (const char*, int, int, float, float, float, float);
    
    bool done();
    
    void draw();
    
    void advance();
    
    void incY();
    
    void reset();

};

#endif
