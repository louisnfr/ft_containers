#include "inc/utility/libs.hpp"

static void	announce(std::string msg) {
	std::cout << "\033[1;32m" << msg << "\033[0m" << std::endl;
}

void	iterator_comparison(void) {
	announce("iterator comparison");

	NS::vector<int> vect(5, 24);

	NS::vector<int>::const_iterator cit = vect.begin();
	NS::vector<int>::iterator end = vect.end();

	for (; cit != end; cit++)
		std::cout << *cit << std::endl;
}

/*
**	https://www32.cplusplus.com/reference/vector/vector/reserve/
*/
void	reallocation(void) {
	announce("reallocation");

	NS::vector<int>::size_type sz;

	NS::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		// std::cout << "(" << foo.size();
		// std::cout << "," << foo.capacity() << ")" << std::endl;
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	NS::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << "\nmaking bar grow:\n";
	for (int i = 0; i < 101; ++i) {
		// std::cout << "(" << bar.size();
		// std::cout << "," << bar.capacity() << ")" << std::endl;
		bar.push_back(i);
		if (sz != bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void	vector_swap(void) {
	announce("vector swap");

	NS::vector<int> vect1;
	vect1.push_back(11);
	vect1.push_back(22);
	vect1.push_back(33);
	NS::vector<int> vect2;
	vect2.push_back(44);
	vect2.push_back(55);
	vect2.push_back(66);
	vect2.push_back(77);
	vect2.push_back(88);

	NS::vector<int>::iterator it = vect1.begin();

	vect1.swap(vect2);

	for (; it != vect2.end(); it++) {
		std::cout << *it << std::endl;
	}
}
