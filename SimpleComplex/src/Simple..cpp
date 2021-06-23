#include "Simple.h"

Prime::Prime() : Prime(100)
{

}

Prime::Prime(ll a) : Sieve(true),sizeSieve(a)
{
	std::vector<bool> prime(sizeSieve + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sizeSieve; ++i) {
		if (prime[i]) {
			if (i * 1ll * i <= sizeSieve) {
				for (int j = i * i; j <= sizeSieve; j += i) {
					prime[j] = false;
				}
			}
		}
	}
	for (size_t i = 0; i < prime.size(); i++)
	{
		if (prime[i]) {
			simple.insert(i);
		}
	}
}

bool Prime::isPrime(ll n) {
	return simple.find(n) != simple.end();
}

bool Prime::isPrimeSqrt(ll n)
{
	std::list<ll> divisors;
	for (ll i = 1; i <= sqrt(n); ++i)
	{
		if (n % i == 0) {
			divisors.push_back(i);
			if (i * i != n) {
				divisors.push_back(n / i);//n/i always int
			}
		}
		if (divisors.size() > 3) {
			break;//so it's not prime num
		}
	}
	return divisors.size() == 2;
}

std::pair<std::vector<std::pair<sf::Vector2f, bool>>, sf::VertexArray>
	Prime::createPoints(ll countPoints,std::pair<ll,ll> orign,sf::Color f,sf::Color s)
{
	std::cout << "Start crtPoints\n";
	
	std::vector<std::pair<sf::Vector2f, bool>> entity;
	sf::VertexArray points;

	auto startTime = std::chrono::system_clock::now();

	for (int i = countPoints; i >= -countPoints; i--)//
	{
		for (int j = -countPoints; j <= countPoints; j++)
		{
			auto&& [x, y] = orign;
			std::complex<int> z(j, i);
			if (isPrimeSqrt(std::abs(z))) {//or use preCntSet
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
			points[i].color = f;
		else
			points[i].color = s;
		i++;
	}

	auto endTime = std::chrono::system_clock::now();

	auto elapsedTime =
		std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

	std::cout << "Time cntPoints = " << elapsedTime.count() << '\n';

	return make_pair(entity, points);
}


