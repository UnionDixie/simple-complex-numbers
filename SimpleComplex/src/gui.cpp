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
	:GUI(cnt, {800,600,400,300},cnt*2,sf::Color::Red, sf::Color::Blue)
{

}

GUI::GUI(ll cnt, std::tuple<ll, ll, ll, ll> resAndOrg, ll size, sf::Color simple, sf::Color other)
	:countPoints(cnt), seed(size),
	 prime(size), main(simple), minnor(other)
{
	auto& [w, h, x, y] = resAndOrg;
	orign = std::make_pair(x, y);
	resoultion = sf::VideoMode(w, h);

	createPoints();
}

void GUI::run() {
	sf::RenderWindow window(resoultion, "Simple_Complex_Nums");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed
				|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {
				std::string str;
				std::cout << "Write new CntPoints\n";
				std::cin >> str;
				countPoints = stoi(str);
				createPoints();
			}
		}
		window.clear();
		window.draw(points);
		window.display();
	}
}

void GUI::createPoints()
{
	std::cout << "Start crtPoints\n";
	points.clear();
	entity.clear();
	auto startTime = std::chrono::system_clock::now();

	for (int i = countPoints; i >= -countPoints; i--)//
	{
		for (int j = -countPoints; j <= countPoints; j++)
		{
			auto&& [x, y] = orign;
			std::complex<int> z(j, i);
			if (prime.isPrimeSqrt(std::abs(z))) {//or use preCntSet
				entity.push_back({ sf::Vector2f(j + x, i + y), true });
			}
			else {
				entity.push_back({ sf::Vector2f(j + x, i + y), false });
			}
		}
	}
	points.setPrimitiveType(sf::Points);
	points.resize(entity.size());
	ll i = 0;
	for (const auto& [vec, color] : entity) {
		points[i] = vec;
		if (color)
			points[i].color = main;
		else
			points[i].color = minnor;
		i++;
	}

	auto endTime = std::chrono::system_clock::now();

	auto elapsedTime =
		std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

	std::cout << "Time cntPoints = " << elapsedTime.count() << '\n';
}

GUI::~GUI() {

}
