#include "gui.h"

int main()
{  	
	//It's my first project on GitHub.com
	//What does this program -
	//user input counts nums(bigger than more beautiful circle
	//also size of window(middle of screen w/2,h/2) and def seeting(for prime nums)
	//GUI has def constructor
	GUI gui(500, {800,600}, 1000,
		    sf::Color::Red, sf::Color::Blue);
	gui.run();

	return 0;
}



