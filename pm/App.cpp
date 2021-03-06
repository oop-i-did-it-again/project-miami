#include "App.h"
#include <stdio.h>
using namespace std;

float App::x = 0.0;
float App::y = 0.0;

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    glutSetWindowTitle("Project Miami");
    glutSetCursor(GLUT_CURSOR_CROSSHAIR); 
    
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    t = 0;
    lastT = 0;
    delta = 0.0;
	playing = false;
    game = Game::getGame();
    startMenu = new StartMenu();
    glutPassiveMotionFunc(mouseMove);
    glutMotionFunc(mouseMove);
}

void App::idle(){
    t = glutGet(GLUT_ELAPSED_TIME);
    
    delta = t - lastT;

    // Update and redraw the scene when specified timestep passed
    if(delta >= 1000/TARGET_FPS){
        // Uncomment to cout fps to console
        //cout << "FPS: " << 1000/delta << endl; 

        lastT = t;
        mx = x;
        my = y;
        game->mx = this->mx;
        game->my = this->my;
        
        if(pause){
            startMenu->displayWin(false,true);
        }
		if(playing){
			game->update(delta);	
			if(game->numberOfBaddies()==0){
                        
				startMenu->displayWin(true,false);
				playing = false;
			}
		}
        redraw();
    }

}

void App::draw() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Draw gamepieces
    if(startMenu->checkWin())
		pause = false;
	if(playing){
        game->draw();
    }
    else if(!playing && pause == false){
        startMenu->draw();
	
    }else if (pause){
		pausescreen->draw();
    }
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    if(playing){
		Player *p = game->getPlayerObject();
		p->shoot(y,x,p->y,p->x,heroBullet);
		//cout << p->health << endl;
	}

    // Redraw the scene
    redraw();
}

void App::mouseMove(int xx, int yy){
    x = (float)xx/300.0 -1.0;
    y = -((float)yy/300.0 -1.0);
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyLift(unsigned char key) {
	if(!playing)
		return;
    Player *p = game->getPlayerObject();
	p->checkKey(key,false);
}

void App::keyPress(unsigned char key) {
	if (key == 27)
		exit(0);
	if(!playing){
        if (key == '1' || key == '2' ||key == '3'){
		int num = startMenu->checkKey(key);
		game->setLevel(num);
        	if(key == 'p'){
        pause=!pause;
		playing=!playing;
		startMenu->displayWin(false,false);
    }
			playing = true;
    }
	}
	if(playing){
    Player *p = game->getPlayerObject();
	p->checkKey(key,true);
	game->checkKey(key);
    if (key == ' ' )
        game->checkDoorCollisions();
	if(key == 'p'){
		playing=!playing;
        pause=!pause;
		startMenu->displayWin(false,false);
    }
    	if(key == 'r'){
        game->reset();
		startMenu->displayWin(false,false);
    }
    }
    
} 
