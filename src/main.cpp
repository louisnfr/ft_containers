#include "inc/utility/libs.hpp"

int main(void) {
	NS::map<int, int> map;

	map.insert(NS::pair<int, int>(0, 0));
	map.insert(NS::pair<int, int>(10, 0));
	map.insert(NS::pair<int, int>(1, 0));
	map.insert(NS::pair<int, int>(-1, 0));

	NS::map<int, int>::iterator it = map.begin();
	std::cout << it->first << std::endl;
	it++;
	std::cout << it->first << std::endl;
	// it++;
	std::cout << it->first << std::endl;


	// map.print_tree();
}
