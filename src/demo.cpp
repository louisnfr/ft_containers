#include "inc/utility/demo.hpp"

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

void	pair_test(void) {
	announce("pair test");

	NS::pair<char, int> p;

	p = NS::make_pair('s', 2);

	std::cout << p.first << std::endl;
	std::cout << p.second << std::endl;
}

void	unique_keys(void) {
	announce("unique keys");

	NS::map<int, int> map;

	map.insert(NS::make_pair(7, 1));
	map.insert(NS::make_pair(2, 1));
	map.insert(NS::make_pair(3, 1));
	map.insert(NS::make_pair(7, 10));

	std::cout << map.count(7) << std::endl;

	// map.print_tree();
}

void	erase(void) {
	announce("erase");

	NS::map<int, int> map;

	map.insert(NS::make_pair(7, 1));
	map.insert(NS::make_pair(2, 1));
	map.insert(NS::make_pair(4, 1));

	NS::map<int, int>::iterator it = map.begin();
	it++;

	map.erase(7);

	std::cout << (*it).first << std::endl;

	map.insert(NS::make_pair(3, 1));

	std::cout << (*it).first << std::endl;
}

void	swap(void) {
	announce("swap");

	NS::map<int, int> map1;

	map1.insert(NS::make_pair(7, 1));
	map1.insert(NS::make_pair(2, 1));
	map1.insert(NS::make_pair(4, 1));

	NS::map<int, int>::iterator it = map1.begin();

	NS::map<int, int> map2;

	map2.insert(NS::make_pair(70, 10));
	map2.insert(NS::make_pair(20, 10));
	map2.insert(NS::make_pair(40, 10));

	map1.swap(map2);

	std::cout << map1.count(7) << std::endl;
	std::cout << map1.count(70) << std::endl;

	for (; it != map2.end(); it++)
		std::cout << (*it).first << std::endl;
}
