#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <utility>

class Prime
{
public:
	Prime();
	bool isPrime(int);
	~Prime();
private:
	std::set<int> simple;
};

Prime::Prime()
{
	int n = 120;
	std::vector<char> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; ++i)
		if (prime[i])
			if (i * 1ll * i <= n)
				for (int j = i * i; j <= n; j += i)
					prime[j] = false;

	for (size_t i = 0; i < prime.size(); i++)
	{
		if (prime[i] == 1)
			simple.insert(i);
	}

}

bool Prime::isPrime(int a) {
	return simple.find(a) != simple.end();
}

Prime::~Prime()
{
}
