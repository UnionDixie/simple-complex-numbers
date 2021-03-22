#include <SFML/Graphics.hpp>

#include <complex>
#include <list>
#include <chrono>
#include <tuple>

#include "Simple.h"

class GUI
{
public:
	typedef long long ll;
	GUI();
	//Count points on plate
	GUI(ll cnt);
	//Count points, Color simple,Color and Other color
	GUI(ll cnt,sf::Color simple, sf::Color other);
	//Count points, orign, siZieSieve~n, Color simple, Color and Other color
	GUI(ll cnt, std::tuple<ll,ll,ll,ll> resAndOrg,ll size, sf::Color simple, sf::Color other);
	void run();
	~GUI();
private:
	void createPoints();
	Prime prime;//checks num
	std::vector<std::pair<sf::Vector2f, bool>> entity;
	sf::VertexArray points;
	ll countPoints;
	ll seed;
	sf::Color main, minnor;
	std::pair<ll, ll> orign;
	sf::VideoMode resoultion;
};

