#ifndef StartMenu_hpp
#define StartMenu_hpp
#include "TexRect.h"

class StartMenu{
	TexRect* background[4];
	int quality;
	public:
		
		StartMenu();
		
		void init();
		void draw();
		void checkKey(unsigned char key);

};

#endif
