#include "Simple.h"

#include <complex>
#include <vector>

int main() {
	Prime prime;

	std::vector<std::pair<int, int>> vec;//all point
	std::vector<std::pair<int, int>> simplePoint;

	for (int i = 10; i >= -10; i--)
	{
		for (int j = -10; j <= 10; j++)
		{
			std::complex<int> z(j, i);
			vec.push_back({ j,i });
			if (prime.isPrime(std::abs(z))) {
				std::cout << " ";
				simplePoint.push_back({ j,i });
			}
			else
				std::cout << ".";
		}
		std::cout << "\n";
	}

	return 0;
}