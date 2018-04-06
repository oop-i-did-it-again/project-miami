#ifndef Actor_hpp
#define Actor_hpp
#include "Gamepiece.h"

class Actor: public Gamepiece{

public:
    float speed;
    int health;
    float r;
    float g;
    float b;

    Actor();
    ~Actor();
    void init();
    void update(int delta);
    void draw();
};

#endif