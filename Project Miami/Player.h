#ifndef Player_hpp
#define Player_hpp
#include "Actor.h"
#include <cmath>

class Player: public Actor{

    public:
        Player();
        ~Player();

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
		
		


};

#endif
