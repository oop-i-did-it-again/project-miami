#ifndef Entity_hpp
#define Entity_hpp
#include "Gamepiece.h"

/*  Base class for all objects with hitbox
 *  We use circle hitboxes because they're FAAAAAST
 * 
 */
class Entity: public Gamepiece{
    float radius;
public:
    Entity();
    ~Entity();


};

#endif