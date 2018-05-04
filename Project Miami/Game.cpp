#include "Game.h"
#include <stdio.h>
Game* Game::instance = 0;


Game* Game::getGame(){
    if(instance == 0){
        instance = new Game();
    }

    return instance;
}

Game::Game(){
    Gamepiece::setGM(this);
    srand (time(NULL));
    init();
}

Game::~Game(){}

void Game::init(){
    // initializes every gamepiece
    // may not be necessary if we gamepieces calls their own inits
    // from their constructors. we shall see
    
	Player* Hero = new Player();
	Hero->type = hero;
	std::vector<Wall*> walls;
	std::vector<Baddy*> baddies;
	
	for(int i = 0; i <10; i+=1){
		baddies.push_back(new Baddy());
		baddies[i]->type = baddy;
        int r2 = rand() % 3 +1;
        baddies[i]->x = rand() % 2-1;
        baddies[i]->y = rand() % 2-1;
        if(r2 == 3)
            baddies[i]->changeWeapon(shotgun);
        else
             baddies[i]->changeWeapon(pistol);
	}
	
	for(int i = 0; i <=200; i+=1){
        Wall* wall = new Wall();
        wall->x = -1+double(i)/100;
		wall->y = .8;
        
		wall->type = environment;
		walls.push_back(wall);
		

	}


}

void Game::update(int delta){
    // Calls update function from every gamepiece
    // delta is milliseconds elapsed since last frame
	
    Player* hero = dynamic_cast<Player*>(gp[0]);
	
	//baddy movement
	srand (time(NULL));
	for(int i = 0; i < gp.size(); i++){
		if(gp[i]-> type == baddy){
			Baddy* bad = dynamic_cast<Baddy*>(gp[i]);
			int random = rand() % 20;
			if (random == 0){
				bad->moveU();
            }
			if (random == 1 ){
				bad->moveD();
            }
			if (random == 2 ){
				bad->moveL();
            }
			if (random == 3 ){
				bad->moveR();
            }
            if (random == 4){
				bad->moveU();
                bad->moveL();
            }
			if (random == 5 ){
				bad->moveD();
                bad->moveL();
            }
			if (random == 6){
                bad->moveU();
				bad->moveR();
            }
			if (random == 7 ){
                bad->moveD();
				bad->moveR();
            }
            if (random > 17 )
                bad->shoot(hero->y,hero->x,bad->y,bad->x, baddyBullet);
		}
	}
	
	checkCollisions();

	//hero movements
    if (hero->up )
        hero->moveU();
    if (hero->down )
       hero->moveD();
    if (hero->left )
        hero->moveL();
    if (hero->right )
       hero->moveR();

	//update every gamepiece
    for(int i = 0; i < gp.size(); i++)
        gp[i]->update(delta);
}

void Game::draw(){
    //  Calls draw function from every gamepiece
    for(int i = 0; i < gp.size(); i++)
        gp[i]->draw();
	background->draw();
}

Player* Game::getPlayerObject(){
    Player* p = dynamic_cast<Player*>(gp[0]);
    return p;
}



void Game::addGP(Gamepiece* gamepiece){
    this->gp.push_back(gamepiece);
}

// DO NOT CALL - GamePieces already calls this in its deconstructor
// use delete instead
void Game::removeGP(Gamepiece* toErase){
   // std::cout << gp.size() << std::endl;
    for(int i = 0; i < gp.size(); i++){
        if (toErase == gp[i]){
            gp.erase(gp.begin() + i);
            //std::cout << gp.size() << std::endl;
        }
    }
}

void Game::checkCollisions(){
    
    for(int i = 0; i < gp.size(); i++){
		for(int j = i+1; j <gp.size(); j++){

			if(collides(gp[i], gp[j])){
                
                //bullet hitting something
                if(gp[j]->type == bullet){
                    
                    //bullet hitting wall
                    if(gp[i]->type == environment){
                       delete gp[j];
                       continue;
                    }
                    
                    //bullet hitting player
                    if(i==0){
                        Projectile* b = dynamic_cast<Projectile*>(gp[j]);
                        if(b->whoseBullet == baddyBullet){
                            Player* p = dynamic_cast<Player*>(gp[i]);
                            if(b->projectileType == shotgun)
                                p->health-=33.4;
                            if(b->projectileType == pistol)
                                p->health-=50;     
                            if(p->health <=0)
                                std::cout<<"player dead"<<std::endl;
                            delete gp[j]; 
                            continue;
                        }
                    }
                    
                    //bullet hitting enemy
                     if(i!=0){
                        Projectile* b = dynamic_cast<Projectile*>(gp[j]);
                        if(b->whoseBullet == heroBullet){
                            if(Baddy* p = dynamic_cast<Baddy*>(gp[i])){
                                delete gp[j]; 
                                if(b->projectileType == shotgun)
                                    p->health-=33.4;
                                if(b->projectileType == pistol)
                                    p->health-=50;     
                                if(p->health <=0)
                                    delete gp[i];
                            continue;
                            }
                        }                   
                    }
                }
                
                //nonwall hitting wall
				if(gp[j]->type == environment){
                    if(gp[i]->type != environment){
                        gp[i]->x=gp[i]->px;
                        gp[i]->y=gp[i]->py;	
                        continue;
                    }
				}
			}
		}
	}
 }
 

 bool Game::collides(Gamepiece* a, Gamepiece* b){
     
	double D = sqrt( pow(a->x - b->x,2.0)+pow(a->y - b->y,2.0));
    Entity* c = dynamic_cast<Entity*>(a);
    Entity* d = dynamic_cast<Entity*>(b);

	return (D< c->radius+d->radius);

 }
