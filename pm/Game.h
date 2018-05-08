#ifndef Game_hpp
#define Game_hpp
#include "Projectile.h"
#include "Gamepiece.h"
#include "Baddy.h"
#include "Player.h"
#include "TexRect.h"
#include "Wall.h"
#include "Door.h"
#include <vector>
#include <iostream>
#include "DeathMenu.h"
#include "Crosshairs.h"

class Game{
    std::vector<Gamepiece*> gp; //replace this with array of gamepieces
    std::vector<Wall*> walls;
	std::vector<Baddy*> baddies;
    std::vector<Door*> doors;
    std::vector <unsigned char> keyList;
    Player* player;
    static Game *instance;
	int baddiesleft;
	int death;
    int gamemode;
    Game();
public:
    TexRect* background;
	DeathMenu* popup;
    static Game* getGame();
    ~Game();
	

    void init();
    void update(int delta); // called every frame, handle game logic here
    void draw(); // called every frame, render stuff here
    Player* getPlayerObject();
	void setLevel(int);
	int numberOfBaddies();

    void addGP(Gamepiece*);
    void addBaddie(Baddy*);
    void addWall(Wall*);
    void addDoor(Door*);
    void removeGP(Gamepiece*);
    void removeBaddie(Baddy*);
    void removeWall(Wall*);
    void removeDoor(Door*);

	void checkCollisions();
	void checkKey(unsigned char);
    void checkDoorCollisions();
	bool collides(Gamepiece* a, Gamepiece* b);
    bool Doorcollides(Gamepiece* a, Gamepiece* b);
    void reset();
    void clearScreen();
    float mx;
    float my;
    void WallSection(double, double, double, char);

    Crosshairs* ch;
};

#endif
