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

void Projectile::updatep(int delta){
    lifeTime -= delta;
    if(lifeTime <= 0)
        removeProjectile();
    else{
    //now move the projectile, then check for collisions
    x +=  speed * delta * cos(dir);
    y +=  speed * delta * sin(dir);
     std::cout<<x<<", "<<y<<std::endl;
     
    draw();
    }
}

void Projectile::draw(){
    glPointSize(10);
    
    glColor3d(1,0,0);
    // Draw something
    glBegin(GL_POINTS);
    glVertex2f(x, y);
     glColor3d(1,1,1);
    glEnd();
}

void Projectile::removeProjectile(){

}