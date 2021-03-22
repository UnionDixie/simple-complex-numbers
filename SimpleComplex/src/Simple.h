#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <set>

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
	~Prime();
private:
	bool Sieve;
	std::set<ll> simple;
	ll sizeSieve;
};

