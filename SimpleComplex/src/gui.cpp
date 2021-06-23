#include "gui.h"

GUI::GUI() 
	:GUI(100)
{
}

GUI::GUI(ll cnt) 
	:GUI(cnt,sf::Color::Red,sf::Color::Blue)
{

}

GUI::GUI(ll cnt, sf::Color simple, sf::Color other) 
	:GUI(cnt, {800,600},cnt*2,sf::Color::Red, sf::Color::Blue)
{

}

GUI::GUI(ll cnt, std::pair<ll, ll> sizeScreen, ll size, sf::Color simple, sf::Color other)
	:countPoints(cnt), seed(size),
	 prime(size), main(simple), minnor(other)
{
	auto& [w, h] = sizeScreen;
	orign = { w / 2, h / 2 };
	resoultion = sf::VideoMode(w, h);

	auto it = prime.createPoints(countPoints, orign, main, minnor);
	entity = std::move(it.first);
	points = std::move(it.second);
}

void GUI::run() {
	sf::RenderWindow window(resoultion, "Simple_Complex_Nums");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed	||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {
				std::string str;
				std::cout << "Write new CntPoints\n";
				std::cin >> str;
				countPoints = stoi(str);
				auto it = prime.createPoints(countPoints, orign, main, minnor);
				entity = std::move(it.first);
				points = std::move(it.second);
			}
		}
		window.clear();
		window.draw(points);
		window.display();
	}
}

