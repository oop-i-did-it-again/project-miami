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
        void phase3(int);//transfer phase 4?
        void phase4(int);//phase 4
        void phase5(int);//ded?


        void shootX();
        void shootO();
        int spawnMinionTimer = 0;
        int spawnMinionCD = 1700;

        int xTimer = 0;
        int xCD = 800;
        int oTimer = 0;
        int oCD = 5000;
        float radX = 0.0;
        float radO = 0.0;
};

#endif
 
