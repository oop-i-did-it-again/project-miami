#ifndef StartMenu_hpp
#define StartMenu_hpp
#include "TexRect.h"

class StartMenu{
	TexRect* background[5];
	TexRect* winscreen;
	int quality;
	bool win;
	public:
		
		StartMenu();
		
		void init();
		void draw();
		void displayWin(bool);
		int checkKey(unsigned char key);

};

#endif
