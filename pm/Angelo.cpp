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
    this->health = 5000;
    this->radius = .25;
    this->y = 0.95;
    this->speed =  0.0007;
    gm->addBaddie(this);
	model = new TexRect("assets/boss.bmp",1,1,x-SIZE,y+SIZE,SIZE*2,SIZE*2);
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
  void Angelo::shoot(float y1, float x1, float y2, float x2,bulletType a){
      
      if (gun == shotgun){
          if(shotgunClip == 0 || shotgunClip == 1){
                if(shotgunClip == 0)
                    shotgunClip =20;
                new Projectile(x2,y2, atan2(y1- y2,x1-x2), 250,.003, .01,a,gun);
                new Projectile(x2,y2, atan2(y1- y2,x1-x2)+.05, 250,.003,.01,a,gun);
                new Projectile(x2,y2, atan2(y1- y2,x1-x2)+.1, 250,.003,.01,a,gun);
                new Projectile(x2,y2, atan2(y1- y2,x1-x2)-.05, 250,.003,.01,a,gun);
                new Projectile(x2,y2, atan2(y1- y2,x1-x2)-.1, 250,.003,.01,a,gun);
          }
          shotgunClip--;
    }

    if (gun == pistol){
        if(pistolClip == 0){
            pistolClip =10;
            new Projectile(x2,y2, atan2(y1- y2,x1-x2), 1250,.002,.02,a,gun);
        }
        pistolClip--;
      }
      
  }


void Angelo::phase1(int delta){
    moveD();
    float dy = abs(delta * vy * speed);
    cout << dy << endl;
    if(y <= 0.0 + dy && y >= 0.0 - dy){
        y = 0.0;
        phase = 2;
    }
}
void Angelo::phase2(int delta){

}
void Angelo::phase3(int delta){

}
void Angelo::phase4(int delta){

}
void Angelo::phase5(int delta){

}