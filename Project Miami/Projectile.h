#ifndef Projectile_hpp
#define Projectile_hpp
#include "Entity.h"

class Projectile: public Entity{
private:

public:
    int lifeTime;
    float speed;
    float dir;
    Projectile(float x, float y, float rad, int lifeTime, float speed,float size);
    ~Projectile();
    void updatep(int delta);
    void draw();

    void removeProjectile();
};

#endif
