#ifndef StartMenu_hpp
#define StartMenu_hpp
#include "TexRect.h"

class StartMenu{
	TexRect* background[5];
	TexRect* winscreen;

	int quality;
	bool win = false;
    bool pause = false;
	public:
		
		StartMenu();
		
		void init();
		void draw();
		void displayWin(bool,bool);
        
		int checkKey(unsigned char key);

};

#endif
