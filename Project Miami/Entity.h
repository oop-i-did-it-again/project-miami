#ifndef Entity_hpp
#define Entity_hpp
#include "Gamepiece.h"
#include <cmath>
/*  Base class for all objects with hitbox
 *  We use circle hitboxes because they're FAAAAAST
 * 
 */
class Entity: public Gamepiece{
private:
public:

    Entity();
    ~Entity();
    virtual void draw();
    
    float radius;
    float r;
    float g;
    float b;
};

#endif