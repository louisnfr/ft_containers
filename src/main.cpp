#include "inc/utility/libs.hpp"

int main(void) {
	NS::map<int, int> map;

	map.insert(NS::pair<int, int>(55, 0));
	map.insert(NS::pair<int, int>(40, 0));
	map.insert(NS::pair<int, int>(60, 0));
	map.insert(NS::pair<int, int>(57, 0));
	map.insert(NS::pair<int, int>(65, 0));
	map.insert(NS::pair<int, int>(75, 0));
	map.insert(NS::pair<int, int>(55, 0));
	map.insert(NS::pair<int, int>(55, 0));
	map.insert(NS::pair<int, int>(55, 0));

	NS::map<int,int>::iterator it = map.begin();

	map.erase(it);

	map.print_tree();
}
