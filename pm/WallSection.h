#ifndef WallSection_hpp
#define WallSection_hpp
#include "Wall.h"
#include <vector>



class WallSection: public Wall{
private:
public:

    WallSection(double, double, double, char);

    ~WallSection();
     void draw();
    
   std::vector <Wall*> section;
    TexRect* Walltexture;

};

#endif
 
