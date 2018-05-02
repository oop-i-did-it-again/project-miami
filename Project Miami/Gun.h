#ifndef Gun_hpp
#define Gun_hpp
#include "Projectile.h"


 


class Gun: public Projectile{

public:
        
	
   Gun();
    ~Gun();

	void shoot(float,float,float,float,bulletType);
	void changeWeapon(weaponType);
    

};

#endif
