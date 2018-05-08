#ifndef Angelo_hpp
#define Angelo_hpp
#include "Baddy.h"
#include <cmath>

class Angelo: public Baddy{
    int phase;
    public:
        Angelo();
        ~Angelo();
        int pistolClip =10000;
        int shotgunClip =20000;
        
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
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false; 
        void shoot(float,float,float,float,bulletType);

        void phase1(int);//entering screen
        void phase2(int);//phase 2
        void phase3(int);//transfer phase 3
        void phase4(int);//phase 4
        void phase5(int);//ded?


};

#endif
 
