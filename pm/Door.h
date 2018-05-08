#ifndef Door_hpp
#define Door_hpp
#include "Entity.h"
/*  Base class for all objects with hitbox
 *  We use circle hitboxes because they're FAAAAAST
 * 
 */
 


class Door: public Entity{
private:
public:

    Door();

    ~Door();
    virtual void draw();
      TexRect* model=new TexRect("assets/door.bmp",1,1,x-.05,y+.1,.1,.2);
    //TexRect* texture;

    bool open = false;
    float radius;
    

    float length;
    float height;
    float r;
    float g;
    float b;

};

#endif
