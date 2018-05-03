#ifndef Projectile_hpp
#define Projectile_hpp
#include "Entity.h"

<<<<<<< HEAD
enum bulletType { heroBullet, baddyBullet, notABullet };
enum weaponType { pistol, shotgun, mini };


=======
>>>>>>> parent of 9700525... bots and wall fixes and other good stuff
class Projectile: public Entity{
private:

public:
    int lifeTime;
    float speed;
    float dir;
<<<<<<< HEAD
    Projectile(float x, float y, float rad, int lifeTime, float speed,float size, bulletType, weaponType);
    ~Projectile();
    void update(int delta);
    void draw();
    bulletType whoseBullet = notABullet;
    weaponType projectileType;
    
=======
    Projectile(float x, float y, float rad, int lifeTime, float speed,float size);
    ~Projectile();
    void update(int delta);
    void draw();

>>>>>>> parent of 9700525... bots and wall fixes and other good stuff
    void removeProjectile();
};

#endif
