#include "inc/utility/libs.hpp"

int main(void) {
	ft::map<int, int> map;
	map.insert(ft::pair<int,int>(0, 0));
	std::cout << "SECOND INSERT" << std::endl;
	map.insert(ft::pair<int,int>(10, 10));
}
