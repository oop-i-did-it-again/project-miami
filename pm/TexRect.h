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
	float red;
	float blue;
	float green;
    GLuint texture_id;

public:
    TexRect (const char*, int, int, float, float, float, float);
    void draw();
    void changePos(float, float);
    bool contains(float, float);
	void updateColor(float,float,float);
    float pos_x,pos_y;
    float sides;
};

#endif
