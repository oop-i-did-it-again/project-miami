#include "Player.h"

Player::Player(){
    //speed = .001;
    //radius = 10;
}

Player::~Player(){

}

void Player::update(int delta){
    normalize();
	px = x;
	py = y;
    
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
