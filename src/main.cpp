#include "inc/utility/libs.hpp"

// #include "inc/test/map_test.hpp"

int main(void) {
	ft::map<char, int> mymap;

	mymap['a'] = 101;
	mymap['b'] = 202;
	mymap['c'] = 303;

	char c = 'a';

	mymap.count(c);
}
