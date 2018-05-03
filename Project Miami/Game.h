#ifndef Game_hpp
#define Game_hpp
#include "Projectile.h"
#include "Gamepiece.h"
#include "Player.h"
#include <vector>
#include <iostream>
enum weapon { pistol, shotgun, mini };

class Game{
    std::vector<Gamepiece*> gp; //replace this with array of gamepieces
    //std::vector<Projectile*> heroBullets; 
    std::vector <unsigned char> keyList;
    static Game *instance;
    Game();
public:
    
    static Game* getGame();
    ~Game();
    weapon gun = pistol;
    void init();
    void update(int delta); // called every frame, handle game logic here
    void draw(); // called every frame, render stuff here
    Player* getPlayerObject();


    void addGP(Gamepiece*);
    void removeGP(Gamepiece*);
    //void addheroBullet(Projectile*);
};

#endif
