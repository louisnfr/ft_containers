#include "inc/utility/libs.hpp"

static void	announce(std::string msg) {
	std::cout << "\033[1;31m" << msg << "\033[0m" << std::endl;
}

int main(void) {
	announce("VECTOR");
	iterator_comparison();
	reallocation();
	vector_swap();

	announce("MAP");
	pair_test();
	unique_keys();
	erase();
	swap();

	test::vector();
	test::stack();
	test::map();
	test::set();
}
