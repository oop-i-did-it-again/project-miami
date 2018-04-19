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
    Player* example = dynamic_cast<Player*>(gp[1]);
    example->moveL();
    for(int i = 0; i < gp.size(); i++)
        gp[i]->update(delta);
}

void Game::draw(){
    //  Calls draw function from every gamepiece
    for(int i = 0; i < gp.size(); i++)
        gp[i]->draw();
}

Player* Game::getPlayerObject(){
    Player* p = dynamic_cast<Player*>(gp[0]);
    return p;
}

void Game::addKey(unsigned char key){

    if (!keyListContains(key)){
         keyList.push_back(key);
        std:: cout<<"Added " << key <<std::endl;
    }
}
void Game::removeKey(unsigned char key){
    for(int i = 0; i <keyList.size(); i++)
        if(keyList[i] == key){
            keyList.erase(keyList.begin()+i);
            std:: cout<<"Removed " << key <<std::endl;
        }
    }
int Game::keyListSize(){
    return keyList.size();
    }
    
bool Game::keyListContains(unsigned char key){
    bool contains = false;
    for(int i = 0; i <keyList.size(); i++)
        if(keyList[i] == key)
            contains = true;
    return contains;
    }

void Game::addGP(Gamepiece* gamepiece){
    this->gp.push_back(gamepiece);
}