#include "Actor.h"

Actor::Actor(){
    init();
}

Actor::~Actor(){

}

void Actor::init(){
    vx = 0.0;
    vy = 0.0;
    health = 100;
    speed = 0.001;
}

void Actor::shoot(float y1, float x1, float y2, float x2,bulletType a){
    if (gun == shotgun){
        new Projectile(x2,y2, atan2(y1- y2,x1-x2), 250,.003, .01,a,gun);
        new Projectile(x2,y2, atan2(y1- y2,x1-x2)+.05, 250,.003,.01,a,gun);
        new Projectile(x2,y2, atan2(y1- y2,x1-x2)+.1, 250,.003,.01,a,gun);
        new Projectile(x2,y2, atan2(y1- y2,x1-x2)-.05, 250,.003,.01,a,gun);
        new Projectile(x2,y2, atan2(y1- y2,x1-x2)-.1, 250,.003,.01,a,gun);

    }

    if (gun == pistol){
        new Projectile(x2,y2, atan2(y1- y2,x1-x2), 1250,.002,.02,a,gun);
    }
}

void Actor::changeWeapon(weapon a){
	gun =a;
}
