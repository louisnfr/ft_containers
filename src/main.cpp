#include "inc/utility/libs.hpp"

#include "inc/test/map_test.hpp"

int main(void) {
	// ft_test::map();

	ft::map<char, int> mymap;

	mymap.insert(ft::make_pair<char, int>('a', 100));
	mymap.insert(ft::make_pair<char, int>('z', 200));

	ft::pair<ft::map<char, int>::iterator, bool> ret;
	ret = mymap.insert(ft::make_pair<char, int>('z', 500));
	
	std::cout << ret.second << std::endl;

}
