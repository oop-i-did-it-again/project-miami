#ifndef Actor_hpp
#define Actor_hpp
#include "Entity.h"
<<<<<<< HEAD
#include "Gun.h"
#include "Projectile.h"

=======
>>>>>>> parent of 9700525... bots and wall fixes and other good stuff
#define DIAG_VSPEED  0.70710678118; 

class Actor: public Entity{

public:
    float vx; //keep this between 0 and 1 movement should be dx * speed * delta
    float vy;
    float speed;
    int health;
<<<<<<< HEAD
    Gun gun;
	
=======

>>>>>>> parent of 9700525... bots and wall fixes and other good stuff
    Actor();
    ~Actor();
    
    virtual void init();
    //virtual void update(int delta);
<<<<<<< HEAD
	

=======
>>>>>>> parent of 9700525... bots and wall fixes and other good stuff
    

};

#endif