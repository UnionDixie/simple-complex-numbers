#include <SFML/Graphics.hpp>

#include <complex>
#include <vector>
#include <chrono>

#include "Simple.h"

class GUI
{
public:
	GUI(int n,int x,int y,int sieve, sf::Color simple, sf::Color other);
	void run();
	~GUI();
private:
	std::vector<std::pair<sf::Vector2f, bool>> entity;
	sf::VertexArray points;
	int n;
	int x,y;//orign
	Prime prime;//sieve 1..n
};

GUI::GUI(int N, int X, int Y, int sieve, sf::Color simple, sf::Color other):prime(sieve),n(N),x(X),y(Y)
{
	auto start = std::chrono::system_clock::now();

	for (int i = n; i >= -n; i--)//10 10 to cmd
	{
		for (int j = -n; j <= n; j++)
		{
			std::complex<int> z(j, i);
			if (prime.isPrime(std::abs(z))) {
				entity.push_back({ sf::Vector2f(j + x, i + y), true });
			}
			else {
				entity.push_back({ sf::Vector2f(j + x, i + y), false });
			}
		}
	}
	points.setPrimitiveType(sf::Points);
	points.resize(entity.size());

	for (size_t i = 0; i < entity.size(); i++)
	{
		points[i] = entity[i].first;
		points[i].color = (entity[i].second) ? simple : other;
	}

	auto end = std::chrono::system_clock::now();

	auto elapsed =
		std::chrono::duration_cast<std::chrono::seconds>(end - start);
	std::cout << "Time sec = " << elapsed.count() << '\n';
}

void GUI::run() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Simple-Complex");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(points);
		window.display();
	}
}

GUI::~GUI() { }


