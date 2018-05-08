#include "Crosshairs.h"
#include <iostream>
#include "Game.h"

Game* Crosshairs::gm;
Crosshairs::Crosshairs(){

}

Crosshairs::~Crosshairs(){
    
}

void Crosshairs::draw(){
    float offset = 0.05;
    glColor3d(1.0, 1.0, 1.0);
    for (int i = 0; i <=1; i++){

        float length = 0.01;
        if(i ==  1)
        {
            glColor3d(0.0, 0.0, 0.0);
            length = 0.0155;
        }
        glBegin(GL_POLYGON);
        glVertex2f(gm->mx -length, gm->my - length + offset);
        glVertex2f(gm->mx + length, gm->my - length + offset);
        glVertex2f(gm->mx + length, gm->my + length + offset);
        glVertex2f(gm->mx-length, gm->my + length + offset);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(gm->mx -length, gm->my - length - offset);
        glVertex2f(gm->mx + length, gm->my - length - offset);
        glVertex2f(gm->mx + length, gm->my + length - offset);
        glVertex2f(gm->mx-length, gm->my + length - offset);

        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(gm->mx -length + offset, gm->my - length);
        glVertex2f(gm->mx + length + offset, gm->my - length);
        glVertex2f(gm->mx + length + offset, gm->my + length);
        glVertex2f(gm->mx-length + offset, gm->my + length);
        glEnd();

        
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(gm->mx -length - offset, gm->my - length);
        glVertex2f(gm->mx + length - offset, gm->my - length);
        glVertex2f(gm->mx + length - offset, gm->my + length);
        glVertex2f(gm->mx-length - offset, gm->my + length);
        glEnd();
    }

}

void Crosshairs::update(int delta){

}

void Crosshairs::setGM(Game* game){
    Crosshairs::gm = game;
}