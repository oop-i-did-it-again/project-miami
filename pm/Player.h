#ifndef Player_hpp
#define Player_hpp
#include "Actor.h"
#include <cmath>

class Player: public Actor{

    public:
        Player();
        ~Player();
        float recoil;
        float recoilRecoveryRate = 0.00025;
        float maxRecoil = 0.5;
        int pistolClip =9;
        int shotgunClip =2;

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
		void checkKey(unsigned char key, bool state);
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
		void shoot(float,float,float,float,bulletType);
};

#endif
