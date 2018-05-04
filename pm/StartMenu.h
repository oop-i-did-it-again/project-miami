#ifndef StartMenu_hpp
#define StartMenu_hpp
#include "TexRect.h"

class StartMenu{
	TexRect* background[5];
	int quality;
	public:
		
		StartMenu();
		
		void init();
		void draw();
		void update();
		void checkKey(unsigned char key);

};

#endif
