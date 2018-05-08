#include "Angelo.h"
#include "Game.h"
#include <iostream>
#define SIZE 0.2
using namespace std;

Angelo::Angelo(){
    //speed = .001;
    //radius = 10;
    phase = 1;
    this->type = baddy;
    this->health = 8000;
    this->radius = .25;
    this->y = 0.95;
    this->speed =  0.0007;
    gm->addBaddie(this);
	model = new TexRect("assets/boss.bmp",1,1,x-SIZE,y+SIZE,SIZE*2,SIZE*2);
    this->gun = pistol;
}

Angelo::~Angelo(){
    //std::cout << "Deleting baddy" << std::endl;
    gm->removeBaddie(this);
	delete model;
}

void Angelo::update(int delta){
    
    vx = 0.0;
    vy = 0.0;
    std::cout << "phase: " << phase << std::endl;
    switch(phase){
        case 1:
            phase1(delta);
            break;
        case 2:
            phase2(delta);
            break;
        
        case 3:
            phase3(delta);
            break;
        case 4:
            phase4(delta);
            break;
        case 5:
            phase5(delta);
            break;
    }

    normalize();
    px=x;
    py=y;
    x += delta * vx * speed;
    y += delta * vy * speed;

    if(x > .95){
        x = px;
    }
    if(y > .95){
        y =py;
    }
    if(x < -.95){
        x = px;
    }if(y < -.95){
        y = py;
    }
    vx = 0.0;
    vy = 0.0;
	model->changePos(x-SIZE,y+SIZE);
}

void Angelo::moveL(){
    vx = -1.0;
}

void Angelo::moveR(){
    vx = 1.0;
}

void Angelo::moveU(){
    vy = 1.0;
}

void Angelo::moveD(){
    vy = -1.0;
}

void Angelo::normalize(){
    if(abs(vy) == 1.0 && abs(vx) == 1.0){
        vy = vy * DIAG_VSPEED;
        vx = vx * DIAG_VSPEED;
    }   
    

}
  void Angelo::shootX(){      
        radX +=0.1;
        int numBullet = 4 ;  
        for (int i =0; i < numBullet; i++){
            new Projectile(this->x,this->y, radX, 25000,.0003, .01 , pistol);
            radX+= 2.0 / numBullet * 3.14  ;
        }
  }

  void Angelo::shootO(){   
        int numBullet = 25;  
        for (int i =0; i < numBullet; i++){
            new Projectile(this->x,this->y, radO, 25000,.0001, .01 , pistol);
            radO += 2.0 / numBullet * 3.14 ;
        }
  }
  void Angelo::shoot(float y1, float x1, float y2, float x2,bulletType a){

  }

void Angelo::phase1(int delta){
    moveD();
    float dy = abs(delta * vy * speed);
    cout << dy << endl;
    if(y <= 0.0 + dy && y >= 0.0 - dy){
        y = 0.0;
        phase = 2;
    }
    if( spawnMinionTimer - 3*spawnMinionTimer/4 < 0){
        spawnMinionTimer = spawnMinionCD;
        Baddy* b = new Baddy();
        int r2 = rand() % 3 +1;
        if(r2 == 3)
            b->changeWeapon(shotgun);
        else
            b->changeWeapon(pistol);
    }
}
void Angelo::phase2(int delta){

    if(health < 4000){
        phase = 3;
    }
    else if( spawnMinionTimer < 0){
        spawnMinionTimer = spawnMinionCD;
        Baddy* b = new Baddy();
        int r2 = rand() % 3 +1;
        if(r2 == 3)
            b->changeWeapon(shotgun);
        else
            b->changeWeapon(pistol);
    }else{
        spawnMinionTimer-= delta;
    }
}
void Angelo::phase3(int delta){

    if( xTimer < 0){
        xTimer = xCD;
        shootX();
    }else{
        xTimer -= delta;
    }

    if( oTimer < 0){
        oTimer = oCD;
        shootO();
    }else{
        oTimer -= delta;
    }
    //wander();
}

void Angelo::phase4(int delta){

}

void Angelo::phase5(int delta){

}