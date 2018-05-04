#ifndef App_hpp
#define App_hpp
#include "GlutApp.h"
#include "Game.h"
#include "StartMenu.h"
#include "time.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
    int t;
    int lastT;
    double delta;
    const double TARGET_FPS = 62.0;
	bool playing;
    timespec ts;
    Game* game; // gamemanager, handles all game logic
	StartMenu* startMenu;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void idle();
    void keyPress(unsigned char key);
    void keyLift(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);

    double getfttime();
};

#endif
