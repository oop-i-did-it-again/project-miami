#include "Projectile.h"


Projectile::Projectile(float x, float y, float rad, int lifeTime, float speed){
    this->x = x;
    this->y = y;
    this->dir = rad;
    this->lifeTime = lifeTime;
    this->speed = speed;
}

Projectile::~Projectile(){
    
}

void Projectile::update(int delta){
    lifeTime -= delta;
    if(lifeTime <= 0)
        removeProjectile();

    //now move the projectile, then check for collisions
    x +=  speed * delta * cos(dir);
    y +=  speed * delta * sin(dir);
}

void Projectile::draw(){
    
}

void Projectile::removeProjectile(){

}
