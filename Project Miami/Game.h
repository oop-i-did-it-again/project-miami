#ifndef Game_hpp
#define Game_hpp
#include "Projectile.h"
#include "Gamepiece.h"
#include "Player.h"
#include <vector>
#include <iostream>


class Game{
    std::vector<Gamepiece*> gp; //replace this with array of gamepieces
    //std::vector<Projectile*> heroBullets; 
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


    void addGP(Gamepiece*);
    void removeGP(Gamepiece*);
	void checkCollisions();
	bool collides(Gamepiece* a, Gamepiece* b);

};

#endif
