#include <SFML/Graphics.hpp>

#include "Simple.h"

class GUI
{
public:
	using ll = long long;
	GUI();
	//Count points on plate
	GUI(ll cnt);
	//Count points, Color simple,Color and Other color
	GUI(ll cnt,sf::Color simple, sf::Color other);
	//Count points, orign, siZieSieve~n, Color simple, Color and Other color
	GUI(ll cnt, std::pair<ll,ll> sizeScreen,ll size, sf::Color simple, sf::Color other);
	void run();
	~GUI() = default;
private:
	//void createPoints();
	Prime prime;//checks num
	std::vector<std::pair<sf::Vector2f, bool>> entity;
	sf::VertexArray points;
	ll countPoints;
	ll seed;
	sf::Color main, minnor;
	std::pair<ll, ll> orign;
	sf::VideoMode resoultion;
};

