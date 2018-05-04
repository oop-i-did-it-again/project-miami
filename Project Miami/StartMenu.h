#ifndef StartMenu_hpp
#define StartMenu_hpp
#include "TexRect.h"

class StartMenu{
	TexRect* background = new TexRect("assets/work.bmp",1,1,-1,1,2,2);;
	public:
		
		StartMenu();
		
		void init();
		void draw();
		/*void checkButton();
		void drawMenu();*/
    

};

#endif
