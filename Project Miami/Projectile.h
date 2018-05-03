#ifndef Projectile_hpp
#define Projectile_hpp
#include "Entity.h"

enum bulletType { heroBullet, baddyBullet, notABullet };
enum weapon { pistol, shotgun, mini };

class Projectile: public Entity{
private:

public:
    int lifeTime;
    float speed;
    float dir;
    Projectile(float x, float y, float rad, int lifeTime, float speed,float size, bulletType, weapon);
    ~Projectile();
    void update(int delta);
    void draw();
    bulletType whoseBullet = notABullet;
    weapon projectileType;
    
    void removeProjectile();
};

#endif
