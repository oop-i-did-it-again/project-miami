#ifndef Sprite_hpp
#define Sprite_hpp
#include "GlutApp.h"
#include <string>

//taken from Jeffrey Chastine https://www.youtube.com/watch?v=Eh0HeTCCgnE

class Sprite: public GlutApp{
private:
    GLuint textBufferID; //OpenGL var
    GLuint texCoordID, texID;   //shader var
    GLuint loadBMP_custom(const char * imagepath);
    GLuint image;
    GLfloat* uvs;
public:
    Sprite();
    ~Sprite();
};

#endif