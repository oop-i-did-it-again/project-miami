#ifndef Game_hpp
#define Game_hpp
#include "Projectile.h"
#include "Gamepiece.h"
#include "Baddy.h"
#include "Player.h"
#include "TexRect.h"
#include "Door.h"
#include "WallSection.h"
#include <vector>
#include <iostream>


class Game{
    std::vector<Gamepiece*> gp; //replace this with array of gamepieces
    std::vector <unsigned char> keyList;
    static Game *instance;
    Game();
public:
    TexRect* background =  new TexRect("assets/gameboard.bmp",1,1,-1,1,2,2);
    static Game* getGame();
    ~Game();
	
    void init();
    void update(int delta); // called every frame, handle game logic here
    void draw(); // called every frame, render stuff here
    Player* getPlayerObject();


    void addGP(Gamepiece*);
    void removeGP(Gamepiece*);
	void checkCollisions();
	void checkKey(unsigned char);
    void checkDoorCollisions();
	bool collides(Gamepiece* a, Gamepiece* b);
    bool Doorcollides(Gamepiece* a, Gamepiece* b);
};

#endif
