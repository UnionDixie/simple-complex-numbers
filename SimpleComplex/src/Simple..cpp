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

Prime::~Prime()
{

}
