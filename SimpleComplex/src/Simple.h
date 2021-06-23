#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <complex>
#include <chrono>

class Prime
{
public:
	typedef long long ll;
	Prime();
	Prime(ll);//seed
	//find in set logn
	bool isPrime(ll);
	//realtime O(sqrt(n))
	bool isPrimeSqrt(ll);
	std::pair<std::vector<std::pair<sf::Vector2f, bool>>, sf::VertexArray> //auto don't work :(
		createPoints(ll, std::pair<ll, ll>, sf::Color f, sf::Color s);
	~Prime() = default;
private:
	bool Sieve;
	std::set<ll> simple;
	ll sizeSieve;
};

