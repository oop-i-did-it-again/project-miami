#ifndef DeathMenu_hpp
#define DeathMenu_hpp
#include "TexRect.h"

class DeathMenu{
	TexRect* popup;
	public:
		
		DeathMenu();
		void draw();
		void checkKey(unsigned char key);

};

#endif
