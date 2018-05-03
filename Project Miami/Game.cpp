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
<<<<<<< HEAD
    
	Player* Hero = new Player();
	Hero->type = hero;
	
	std::vector<Entity*> walls;
	std::vector<Player*> players;
	
	for(int i = 0; i <10; i+=1){
		players.push_back(new Player());
		players[i]->type = baddy;
        int r2 = rand() % 3 +1;
        
        if(r2 == 3)
            players[i]->gun.changeWeapon(shotgun);
        else
             players[i]->gun.changeWeapon(pistol);
	}
	
	for(int i = 0; i <=80; i+=1){
        Entity* wall = new Entity(false);
        wall->x = -1+double(i)/40;
		wall->y = .8;
        
		wall->type = environment;
		walls.push_back(wall);
		

	}


=======
    Player* p = new Player();
    Player* p2 = new Player();
>>>>>>> parent of 9700525... bots and wall fixes and other good stuff
}

void Game::update(int delta){
    // Calls update function from every gamepiece
    // delta is milliseconds elapsed since last frame
    Player* hero = dynamic_cast<Player*>(gp[0]);
<<<<<<< HEAD
	
	//baddy movement
	//srand (time(NULL));
	for(int i = 0; i < gp.size(); i++){
		if(gp[i]-> type == baddy){
			Player* bad = dynamic_cast<Player*>(gp[i]);
			int random = rand() % 20;
            int r2 = rand() % 1-1;
            int r3 = rand() % 1-1;
			if (random == 0){
				bad->moveU();
            }
			if (random == 1 )
				bad->moveD();
			if (random == 2 )
				bad->moveL();
			if (random == 3 )
				bad->moveR();
            if (random == 17 )
                bad->gun.shoot(hero->y,hero->x,bad->y,bad->x, baddyBullet);
		}
	}
	
	checkCollisions();

	//hero movements
    if (hero->up )
=======
    Player* example = dynamic_cast<Player*>(gp[1]);
    example->moveL();
    
    if (hero->up){
>>>>>>> parent of 9700525... bots and wall fixes and other good stuff
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
    /*
    for(int i = 0; i < heroBullets.size(); i++)
        if( heroBullets[i]->lifeTime > 0)
            heroBullets[i]->updatep(delta);
        else{
            heroBullets[i]->removeProjectile();
            heroBullets.erase(heroBullets.begin()+i);
        }
    */
    for(int i = 0; i < gp.size(); i++)
        gp[i]->update(delta);
    

}

void Game::draw(){
    //  Calls draw function from every gamepiece
    for(int i = 0; i < gp.size(); i++)
        gp[i]->draw();
    //for(int i = 0; i < heroBullets.size(); i++)
    //    heroBullets[i]->draw();
}

Player* Game::getPlayerObject(){
    Player* p = dynamic_cast<Player*>(gp[0]);
    return p;
}



void Game::addGP(Gamepiece* gamepiece){
    this->gp.push_back(gamepiece);
}

void Game::removeGP(Gamepiece* toErase){
    std::cout << gp.size() << std::endl;
    for(int i = 0; i < gp.size(); i++){
        if (toErase == gp[i]){
            gp.erase(gp.begin() + i);
            std::cout << gp.size() << std::endl;
        }
    }

    //delete toErase;
}

// void Game::addheroBullet(Projectile* bullet){
//     //this->heroBullets.push_back(bullet);
// }
