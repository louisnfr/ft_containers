#include "inc/utility/libs.hpp"

int main(void) {
	
	NS::vector<int> vect(5, 24);

	NS::vector<int>::const_iterator cit = vect.begin();
	NS::vector<int>::iterator end = vect.end();

	for (; cit != end; cit++)
		std::cout << *cit << std::endl;

}
