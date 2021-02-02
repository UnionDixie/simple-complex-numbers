#include "gui.h"

int main()
{
	//n->n*n plate,x and y origin,sieve 1..n,simple color,other color
	GUI gui(500,400,300,1000,sf::Color::Red,sf::Color::White);
	gui.run();

	return 0;
}