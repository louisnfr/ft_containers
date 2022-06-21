#include "inc/utility/libs.hpp"

int main(void) {

	ft::map<std::string, int> m;

	m.insert(ft::make_pair<std::string, unsigned int>("louis", 3));
	m.insert(ft::make_pair<std::string, int>("22", 3));
	m.insert(ft::make_pair<std::string, int>("lou43is", 3));
	m.insert(ft::make_pair<std::string, int>("lou5is", 3));

	m.print_tree();

	// ft_test::vector();
	// ft_test::stack();
	// ft_test::map();
	// ft_test::set();
}
