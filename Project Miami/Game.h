#ifndef Game_hpp
#define Game_hpp

#include "Gamepiece.h"
#include "Player.h"
#include <vector>

class Game{
    Gamepiece* gp; //replace this with array of gamepieces
    Player* p;
    Player* p2;
    std::vector <unsigned char> keyList;
    
public:
    Game();
    ~Game();
    
    void init();
    void update(int delta); // called every frame, handle game logic here
    void draw(); // called every frame, render stuff here
    Player* getPlayerObject();
    void addKey(unsigned char key);
    void removeKey(unsigned char key);
    int keyListSize();
    bool keyListContains(unsigned char key);
};

#endif
