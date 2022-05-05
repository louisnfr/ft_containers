#if STD
  #define NS std
  #define NSd "std"
  #include <iostream>
  #include <map>
  #include <stack>
  #include <vector>
#else
  #define NS ft
  #define NSd "ft"
  #include "stack.hpp"
  #include "vector.hpp"
  // #include "map.hpp"
#endif

int main(void) {
	NS::vector<int> vect(5, 42);
	NS::vector<int> copy(vect);

	vect[4] = 0;

	std::cout << copy[4] << std::endl;
	std::cout << vect[4] << std::endl;

	return (0);
}
