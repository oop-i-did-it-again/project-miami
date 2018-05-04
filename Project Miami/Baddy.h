#ifndef Baddy_hpp
#define Baddy_hpp
#include "Actor.h"
#include <cmath>

class Baddy: public Actor{

    public:
        Baddy();
        ~Baddy();
        int pistolClip =10;
        int shotgunClip =20;
        
        void update(int delta);
        void moveL();
        void moveR();
        void moveU();
        void moveD();
        void moveUL();
        void moveUR();
        void moveDL();
        void moveDR();
        void normalize();
		void draw();
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
		TexRect* baddyModel; 
        void shoot(float,float,float,float,bulletType);


};

#endif
 
