#ifndef Gamepiece_hpp
#define Gamepiece_hpp
#include "GlutApp.h"

class Gamepiece{

public:
    float x;
    float y;

    Gamepiece();
    ~Gamepiece();

    virtual void init();
    virtual void update(int delta);
    virtual void draw();
};

#endif
