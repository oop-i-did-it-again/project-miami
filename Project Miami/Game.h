#ifndef Game_hpp
#define Game_hpp

#include "Gamepiece.h"
#include "Player.h"

class Game{
    Gamepiece* gp; //replace this with array of gamepieces
    Player* p;
public:
    Game();
    ~Game();
    
    void init();
    void update(int delta); // called every frame, handle game logic here
    void draw(); // called every frame, render stuff here
    Player* getPlayerObject();
};

#endif