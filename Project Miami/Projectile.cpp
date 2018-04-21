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

    glColor3d(1,0,0);
    // Draw something
    
    //draw circular bullet. replace with texture
    glBegin(GL_POLYGON);
	for (double i = 0; i <2*3.141692;i+=3.151592/50)
		glVertex2f(cos(i)*.02+x,sin(i)*.02+y);
	glEnd();


     glColor3d(1,1,1);

}

void Projectile::removeProjectile(){

}
