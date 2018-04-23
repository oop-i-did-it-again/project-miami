#include "Projectile.h"
#include "Game.h"

Projectile::Projectile(float x, float y, float rad, int lifeTime, float speed, float size){
    this->x = x;
    this->y = y;
    this->radius = size;
    this->dir = rad;
    this->lifeTime = lifeTime;
    this->speed = speed;
}

Projectile::~Projectile(){

}

void Projectile::update(int delta){
    lifeTime -= delta;

    if (lifeTime < -100)
        removeProjectile();
    //now move the projectile, then check for collisions
    x +=  speed * delta * cos(dir);
    y +=  speed * delta * sin(dir);
     
    draw();
    

}

void Projectile::draw(){

    glColor3d(1,0,0);
    // Draw something
    
    //draw circular bullet. replace with texture
    glBegin(GL_POLYGON);
	for (double i = 0; i <2*3.141692;i+=3.151592/75)
		glVertex2f(cos(i)*radius+x,sin(i)*radius+y);
	glEnd();


     glColor3d(1,1,1);

}

void Projectile::removeProjectile(){
    //just send to the nether
    gm->removeGP(this);
}
