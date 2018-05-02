#include "Gun.h"

Gun::Gun(){

}
Gun::~Gun(){

}



void Gun::shoot(float y1, float x1, float y2, float x2,bulletType a){
    if (projectileType == shotgun){
        new Projectile(x2,y2, atan2(y1- y2,x1-x2), 250,.003, .01,a,projectileType);
        new Projectile(x2,y2, atan2(y1- y2,x1-x2)+.05, 250,.003,.01,a,projectileType);
        new Projectile(x2,y2, atan2(y1- y2,x1-x2)+.1, 250,.003,.01,a,projectileType);
        new Projectile(x2,y2, atan2(y1- y2,x1-x2)-.05, 250,.003,.01,a,projectileType);
        new Projectile(x2,y2, atan2(y1- y2,x1-x2)-.1, 250,.003,.01,a,projectileType);

    }

    if (projectileType == pistol){
        new Projectile(x2,y2, atan2(y1- y2,x1-x2), 1250,.002,.02,a,projectileType);
    }
}

void Gun::changeWeapon(weaponType a){
	projectileType =a;
}
 
