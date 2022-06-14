#include "inc/utility/libs.hpp"

int main(void) {
	ft::map<int, int> map;

	map.insert(ft::pair<int,int>(0, 0));
	map.insert(ft::pair<int,int>(10, 10));
	map.insert(ft::pair<int,int>(1, 1));
	map.insert(ft::pair<int,int>(-1, -1));

	map.print_tree();
}
