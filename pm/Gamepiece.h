#ifndef Gamepiece_hpp
#define Gamepiece_hpp
#include "GlutApp.h"


class Game;
enum Type { hero, baddy, environment, bullet, door,nothing};


class Gamepiece{
public:
	
    float x;
    float y;
	float px;
	float py;

	Type type;
  
    
    Gamepiece();
    ~Gamepiece();

    virtual void init();
    virtual void update(int delta);
    virtual void draw();

    static Game* gm;
    static void setGM(Game* gm);
};

#endif
