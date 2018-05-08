#include "Projectile.h"
#include "Game.h"

Projectile::Projectile(float x, float y, float rad, int lifeTime, float speed, float size, weapon b){
    this->x = x;
    this->y = y;
    this->radius = size;
    this->dir = rad;
    this->lifeTime = lifeTime;
    this->speed = speed;
	this->type = bullet;
    this->whoseBullet = baddyBullet;
    this->projectileType = b;
}

Projectile::Projectile(float x, float y, float rad, int lifeTime, float speed, float size, bulletType a, weapon b){
    this->x = x;
    this->y = y;
    this->radius = size;
    this->dir = rad;
    this->lifeTime = lifeTime;
    this->speed = speed;
	this->type = bullet;
    this->whoseBullet = a;
    this->projectileType = b;
}

Projectile::~Projectile(){
    //    std::cout << "deleted" << std::endl;
}

void Projectile::update(int delta){
    lifeTime -= delta;


        //removeProjectile();
    if (lifeTime < -0){
        delete this;
        return;
    }
    //now move the projectile, then check for collisions
    x +=  speed * delta * cos(dir);
    y +=  speed * delta * sin(dir);
     
    draw();
    

}

void Projectile::draw(){

    glColor3d(0,1,1);
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
