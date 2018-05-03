#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <iostream>
#include "RgbImage.h"

class TexRect {
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;

public:
    TexRect (const char*, int, int, float, float, float, float);
    
    void draw();
    
    bool contains(float, float);
    
    float pos_x,pos_y;
    float sides;
};

#endif
