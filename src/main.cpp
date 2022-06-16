#include "inc/utility/libs.hpp"

int main(void) {
	NS::map<int, int> map;

	map.insert(NS::pair<int, int>(0, 0));
	map.insert(NS::pair<int, int>(10, 10));
	map.insert(NS::pair<int, int>(1, 1));
	map.insert(NS::pair<int, int>(-1, -1));

	NS::map<int, int>::iterator it = map.end();

	std::cout << it->first << std::endl;
	--it;
	std::cout << it->first << std::endl;
	--it;
	std::cout << it->first << std::endl;
	--it;
	std::cout << it->first << std::endl;
	--it;
	std::cout << it->first << std::endl;
	it++;
	std::cout << it->first << std::endl;
	it++;
	std::cout << it->first << std::endl;
	it++;
	std::cout << it->first << std::endl;
	it++;

	// map.print_tree();
}
