#include <iostream>
#include <cmath>
#include <vector>

size_t t_sequence(size_t k) {
	size_t powerOfTwo = (1 << (k + 1));
	int sign = (k % 2 == 0) ? 1 : -1;
	size_t jacobsthal_number = (powerOfTwo + sign) / 3;
	return jacobsthal_number;
}

long _jacobsthal_number(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }

int main()
{
	// std::vector<int> t_seq;
	// std::vector<int> _jast;
	// for (size_t i = 0; i < 10; i++)
	// {
	// 	int tk = t_sequence(i);
	// 	int tk1 = _jacobsthal_number(i);
	// 	t_seq.push_back(tk);
	// 	_jast.push_back(tk1);
	// }

	// for (size_t i = 0; i < t_seq.size(); i++)
	// {
	// 	std::cout << t_seq[i] << " ";
	// }
	// std::cout << std::endl;
	// std::cout << std::endl;
	// for (size_t i = 0; i < _jast.size(); i++)
	// {
	// 	std::cout << _jast[i] << " ";
	// }

	std::cout << t_sequence(3) << std::endl;

	std::vector<int> vect;

	vect.push_back(4);
	vect.push_back(6);
	vect.push_back(9);

	std::cout << "----- Before -----\n";
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	
	std::vector<int>::iterator it = std::lower_bound(vect.begin(), vect.end(), 5);
	vect.insert(it, 5);
	
	std::cout << "\n\n----- after -----\n";
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
}