#include "inc/utility/libs.hpp"

void	iterator_comparison(void) {
	std::cout << "iterator comparison" << std::endl;

	NS::vector<int> vect(5, 24);

	NS::vector<int>::const_iterator cit = vect.begin();
	NS::vector<int>::iterator end = vect.end();

	for (; cit != end; cit++)
		std::cout << *cit << std::endl;
}
