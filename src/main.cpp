#include "inc/utility/libs.hpp"

int main(void) {

	ft::pair<int, int> pr;
	ft::pair<int, int> prr;
	ft::pair<std::string, char> pr2;

	pr = ft::make_pair(1, 33);
	prr = ft::make_pair(1, 33);
	pr2 = ft::make_pair("bonjour", 'A');

	std::cout << pr.first << std::endl;
	std::cout << pr.second << std::endl;
	std::cout << pr2.first << std::endl;
	std::cout << pr2.second << std::endl;

	std::cout << (pr == prr) << std::endl;


	// ft_test::vector();
	// ft_test::stack();
	// ft_test::map();

	return (0);
}
