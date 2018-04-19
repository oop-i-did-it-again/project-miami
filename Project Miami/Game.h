#ifndef Game_hpp
#define Game_hpp

#include "Gamepiece.h"
#include "Player.h"
#include <vector>

class Game{
    std::vector<Gamepiece*> gp; //replace this with array of gamepieces
    std::vector <unsigned char> keyList;
    static Game *instance;
    Game();
public:
    
    static Game* getGame();
    ~Game();
    
    void init();
    void update(int delta); // called every frame, handle game logic here
    void draw(); // called every frame, render stuff here
    Player* getPlayerObject();
    void addKey(unsigned char key);
    void removeKey(unsigned char key);
    int keyListSize();
    bool keyListContains(unsigned char key);

    void addGP(Gamepiece*);
};

#endif
