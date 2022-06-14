#include "inc/utility/libs.hpp"

int main(void) {
	NS::pair<int,int> p(1,10);
	std::cout << p.second << std::endl;

	NS::map<int, int> map;

	map.insert(NS::pair<int, int>(0, 0));
	map.insert(NS::pair<int, int>(10, 0));
	map.insert(NS::pair<int, int>(1, 0));
	map.insert(NS::pair<int, int>(-1, 0));

	NS::map<int, int>::iterator it = map.begin();

	// it--;

	std::cout << it->first << std::endl;

	// map.print_tree();
}
