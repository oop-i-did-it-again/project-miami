#ifndef Wall_hpp
#define Wall_hpp
#include "Entity.h"
/*  Base class for all objects with hitbox
 *  We use circle hitboxes because they're FAAAAAST
 * 
 */
 


class Wall: public Entity{
private:
public:

    Wall();

    ~Wall();
    virtual void draw();
    
    //TexRect* texture;

    float radius;
    float length;
    float height;
    float r;
    float g;
    float b;

};

#endif
