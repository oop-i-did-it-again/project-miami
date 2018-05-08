#ifndef Crosshairs_hpp
#define Crosshairs_hpp

#include "GlutApp.h"

class Game;

class Crosshairs{

public:
    Crosshairs();
    ~Crosshairs();
    void draw();
    void update(int delta);
    static Game* gm;
    static void setGM(Game* gm);
};

#endif
