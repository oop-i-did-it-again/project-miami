#include "Baddy.h"
#define SIZE 0.06

Baddy::Baddy(){
    //speed = .001;
    //radius = 10;
	baddyModel = new TexRect("assets/baddy.bmp",1,1,x-SIZE,y+SIZE,SIZE*2,SIZE*2);
}

Baddy::~Baddy(){
	delete baddyModel;
}

void Baddy::update(int delta){
    normalize();
    px=x;
    py=y;
    x += delta * vx * speed;
    y += delta * vy * speed;

    if(x > 1.0){
        x = -1.0;
    }
    if(y > 1.0){
        y = -1.0;
    }
    if(x < -1.0){
        x = 1.0;
    }if(y < -1.0){
        y = 1.0;
    }
    vx = 0.0;
    vy = 0.0;
	baddyModel->changePos(x-SIZE,y+SIZE);
}

void Baddy::moveL(){
    vx = -1.0;
}

void Baddy::moveR(){
    vx = 1.0;
}

void Baddy::moveU(){
    vy = 1.0;
}

void Baddy::moveD(){
    vy = -1.0;
}

void Baddy::normalize(){
    if(abs(vy) == 1.0 && abs(vx) == 1.0){
        vy = vy * DIAG_VSPEED;
        vx = vx * DIAG_VSPEED;
    }   
    

}
  void Baddy::shoot(float y1, float x1, float y2, float x2,bulletType a){
      
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

void Baddy::draw(){
	baddyModel->draw();
}