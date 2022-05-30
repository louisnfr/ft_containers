#include "inc/utils/libs.hpp"

int main(void) {
	ft_test::vector();
	ft_test::stack();

	NS::stack<int>	 first;
	NS::stack<int>	 second;

	first.push(2);

	std::cout << (first == second) << std::endl;
	std::cout << (first != second) << std::endl;

	std::cout << (first < second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first >= second) << std::endl;

	std::cout << (second < first) << std::endl;
	std::cout << (second > first) << std::endl;
	std::cout << (second <= first) << std::endl;
	std::cout << (second >= first) << std::endl;

	second.push(343);
	second.push(3433);
	second.push(3434);

	std::cout << (first == second) << std::endl;
	std::cout << (first != second) << std::endl;

	std::cout << (first < second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first >= second) << std::endl;

	std::cout << (second < first) << std::endl;
	std::cout << (second > first) << std::endl;
	std::cout << (second <= first) << std::endl;
	std::cout << (second >= first) << std::endl;

	return (0);
}
