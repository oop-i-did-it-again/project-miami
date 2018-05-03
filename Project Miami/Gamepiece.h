#ifndef Gamepiece_hpp
#define Gamepiece_hpp
#include "GlutApp.h"


class Game;

class Gamepiece{
public:

    float x;
    float y;

    Gamepiece();
    ~Gamepiece();

    virtual void init();
    virtual void update(int delta);
    virtual void draw();

    static Game* gm;
    static void setGM(Game* gm);
};

#endif