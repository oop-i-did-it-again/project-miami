#include "Game.h"

Game* Game::instance = 0;

Game* Game::getGame(){
    if(instance == 0){
        instance = new Game();
    }

    return instance;
}

Game::Game(){
    Gamepiece::setGM(this);
    init();
}

Game::~Game(){}

void Game::init(){
    // initializes every gamepiece
    // may not be necessary if we gamepieces calls their own inits
    // from their constructors. we shall see
    Player* p = new Player();
    Player* p2 = new Player();
}

void Game::update(int delta){
    // Calls update function from every gamepiece
    // delta is milliseconds elapsed since last frame
    Player* hero = dynamic_cast<Player*>(gp[0]);
    Player* example = dynamic_cast<Player*>(gp[1]);
    example->moveL();
    
    if (hero->up){
        hero->moveU();
    }
    if (hero->down){
       hero->moveD();
    }
    if (hero->left){
        hero->moveL();
    }
    if (hero->right){
       hero->moveR();
    }

    for(int i = 0; i < heroBullets.size(); i++)
        if( heroBullets[i]->lifeTime > 0)
            heroBullets[i]->updatep(delta);
        else{
            heroBullets[i]->removeProjectile();
            heroBullets.erase(heroBullets.begin()+i);
        }
        
    for(int i = 0; i < gp.size(); i++)
        gp[i]->update(delta);
    

}

void Game::draw(){
    //  Calls draw function from every gamepiece
    for(int i = 0; i < gp.size(); i++)
        gp[i]->draw();
    for(int i = 0; i < heroBullets.size(); i++)
        heroBullets[i]->draw();
}

Player* Game::getPlayerObject(){
    Player* p = dynamic_cast<Player*>(gp[0]);
    return p;
}



void Game::addGP(Gamepiece* gamepiece){
    this->gp.push_back(gamepiece);
}

void Game::addheroBullet(Projectile* bullet){
    this->heroBullets.push_back(bullet);
}
