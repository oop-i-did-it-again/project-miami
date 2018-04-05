#ifndef Game_hpp
#define Game_hpp

class Game{
    
public:
    Game();
    ~Game();
    
    void init();
    void update(long delta); // called every tick, handle game logic here
    void draw(); // called every frame, render stuff here
};

#endif