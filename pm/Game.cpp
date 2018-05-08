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
    Crosshairs::setGM(this);
    srand (time(NULL));
    //init();
}

Game::~Game(){
	delete getPlayerObject();
	for(int i=0;i<gp.size();i++){
		removeGP(gp.at(i));
	}
}

void Game::init(){
    // initializes every gamepiece
    // may not be necessary if we gamepieces calls their own inits
    // from their constructors. we shall see
   
    background = new TexRect("assets/gameboard.bmp",1,1,-1,1,2,2);
	popup = new DeathMenu();
	Player* Hero = new Player();
	Hero->type = hero;
    Hero->x = -.9;
    Hero->y = -.9;
	std::vector<Wall*> walls;
	std::vector<Baddy*> baddies;
	death = 0;
    
    std::cout<<gamemode<<std::endl;
    if (gamemode ==1){
	for(int i = 0; i <10; i+=1){
		baddies.push_back(new Baddy());
		baddies[i]->type = baddy;
        int r2 = rand() % 3 +1;

        if(r2 == 3)
            baddies[i]->changeWeapon(shotgun);
        else
             baddies[i]->changeWeapon(pistol);
	}
	
	WallSection *s1 = new WallSection(-1.0,-.75,.3,'x');
	WallSection *s2 = new WallSection(-.15,.3,.7,'y');
	WallSection *s3 = new WallSection(.3,0,.7,'x');
	WallSection *s4 = new WallSection(.3,.5,.7,'x');

	Door * thisDoor = new Door();
	thisDoor->x = -.71;
    thisDoor->y = -.9;
	thisDoor->type = door;
    }
    if (gamemode == 2){
        	for(int i = 0; i <10; i+=1){
		baddies.push_back(new Baddy());
		baddies[i]->type = baddy;
        int r2 = rand() % 3 +1;

        if(r2 == 3)
            baddies[i]->changeWeapon(shotgun);
        else
             baddies[i]->changeWeapon(pistol);
	}

    
<<<<<<< HEAD
	//Door * thisDoor1 = new Door();
	//thisDoor1->x = -.7;
    //thisDoor1->y = -.95;
	//thisDoor1->type = door;
    ch = new Crosshairs();
=======
   

     WallSection *s1 = new WallSection(-1.0,-.75,.3,'x');
    Door * thisDoor = new Door();
	thisDoor->x = -.71;
    thisDoor->y = -.9;
	thisDoor->type = door;
    
    
    WallSection *s2 = new WallSection(-1,.5,1,'x');
	WallSection *s3 = new WallSection(.4,.2,.8,'y');
	WallSection *s4 = new WallSection(.4,-1,.8,'y');
    WallSection *s5 = new WallSection(.0,.15,.41,'x');
	WallSection *s6 = new WallSection(.0,-.15,.41,'x');
    
    Door * thisDoor1 = new Door();
	thisDoor1->x = 0;
    thisDoor1->y = 0;
	thisDoor1->type = door;
    }
>>>>>>> 4e858c415d095658bdeb0e97c4e1e4d39422b8ce
}

void Game::update(int delta){
    // Calls update function from every gamepiece
    // delta is milliseconds elapsed since last frame
	baddiesleft = 0;
    Player* hero = dynamic_cast<Player*>(gp[0]);
	
	//baddy movement
	if(death==1){
		for(int i=0;i<gp.size();i++){
			if(gp[i]-> type == baddy){
				Baddy* bad = dynamic_cast<Baddy*>(gp[i]);
				bad->updateColor(1,0,0);
			}
		}
		hero->updateColor(1,0,0);
		background->updateColor(1,0,0);
		death = 2;
	}
	else if(death==-1){
		hero->health = 1000;
		for(int i=0;i<gp.size();i++){
			if(gp[i]-> type == baddy){
				Baddy* bad = dynamic_cast<Baddy*>(gp[i]);
				bad->updateColor(1,1,1);
			}
		}
		hero->updateColor(1,1,1);
		background->updateColor(1,1,1);
		death = 0;
	}
	srand (time(NULL));
	for(int i = 0; i < gp.size(); i++){
		if(gp[i]-> type == baddy){
			baddiesleft++;
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
    ch->draw();
    //  Calls draw function from every gamepiece
	if(death>0)
		popup->draw();
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
                    if(gp[i]->type == environment ){
                       delete gp[j];
                       continue;
                    }
                    
                    if(gp[i]->type == door){
                        Door* d = dynamic_cast<Door*>(gp[i]);
                        if(d->open ==false){
                            delete gp[j];
                            continue;
                        }                        
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
                            if(p->health <=0){
								death = 1;
							}
							else
								death = 0;
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
                    if(gp[i]->type != environment && gp[i]->type != door){
                        gp[i]->x=gp[i]->px;
                        gp[i]->y=gp[i]->py;	
                        continue;
                    }
				}
				
                if(gp[j]->type == door && gp[i]->type != environment){
                    if(gp[i]->type != door ){
                        Door* d = dynamic_cast<Door*>(gp[j]);
                        if(d->open == false){
                        gp[i]->x=gp[i]->px;
                        gp[i]->y=gp[i]->py;	
                        }
                        continue;
                    }
				}
				
			}
		}
	}
 }
 
void Game::checkDoorCollisions(){
    for(int i = 1; i < gp.size(); i++){
       if(gp[i]->type == door){
           Door* d = dynamic_cast<Door*>(gp[i]);
            if (d->open == false)
                d->radius = .11;
            else
                d->radius = .05;
		if(collides(gp[i], gp[0])){
             d->open= !d->open;
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

 void Game::checkKey(unsigned char key){
	 if(key == 'h')
		 death = -1;
 }
 
 void Game::setLevel(int num){
gamemode = num;
init();
 }
 
int Game::numberOfBaddies(){
	return baddiesleft;
}


 void Game::reset(){
     gp.erase (gp.begin(),gp.end());
        init();
        
    
 }
