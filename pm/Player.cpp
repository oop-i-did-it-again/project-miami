#include "Player.h"
#define SIZE .06

Player::Player(){
    //speed = .001;
    //radius = 10;
	model=new TexRect("assets/player.bmp",1,1,x-SIZE,y+SIZE,SIZE*2,SIZE*2);
}

Player::~Player(){
	delete model;
}

void Player::update(int delta){
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

void Player::moveL(){
    vx = -1.0;
}

void Player::moveR(){
    vx = 1.0;
}

void Player::moveU(){
    vy = 1.0;
}

void Player::moveD(){
    vy = -1.0;
}

void Player::normalize(){
    if(abs(vy) == 1.0 && abs(vx) == 1.0){
        vy = vy * DIAG_VSPEED;
        vx = vx * DIAG_VSPEED;
    }   
    

}


  void Player::shoot(float y1, float x1, float y2, float x2,bulletType a){
      if (gun == shotgun){
           if(shotgunClip == -1)
                    shotgunClip =2;//reload
          if(shotgunClip >0){
                new Projectile(x2,y2, atan2(y1- y2,x1-x2), 250,.003, .01,a,gun);
                new Projectile(x2,y2, atan2(y1- y2,x1-x2)+.05, 250,.003,.01,a,gun);
                new Projectile(x2,y2, atan2(y1- y2,x1-x2)+.1, 250,.003,.01,a,gun);
                new Projectile(x2,y2, atan2(y1- y2,x1-x2)-.05, 250,.003,.01,a,gun);
                new Projectile(x2,y2, atan2(y1- y2,x1-x2)-.1, 250,.003,.01,a,gun);
          }
          shotgunClip--;
    }

      if (gun == pistol){
           if(pistolClip == -1)
                    pistolClip =9;//reload
          if(pistolClip >0){
                    new Projectile(x2,y2, atan2(y1- y2,x1-x2), 1250,.002,.02,a,gun);
          }
          pistolClip--;
    }
      
  }

 void Player::checkKey(unsigned char key, bool state){
	 if (key == 'w')
        up = state;
    if (key == 'a' )
        left = state;
    if (key == 's' )
        down = state;
    if (key == 'd' )
        right=state;
	if (key == '1' )
		changeWeapon(pistol);
    if (key == '3' )
        changeWeapon(shotgun);
 }
