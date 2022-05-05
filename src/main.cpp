#if STD
  #define NS std
  #include <iostream>
  #include <vector>
  #include <stack>
  #include <map>
  #define diff "std"
#else
  #define NS ft
  #include "inc/vector.hpp"
  #include "inc/stack.hpp"
  // #include "inc/map.hpp"
  #define diff "ft"
#endif

int main(void) {
	NS::vector<int> vect(5, 42);
	NS::vector<int> copy(vect);

	vect[4] = 0;

	std::cout << copy[4] << std::endl;
	std::cout << vect[4] << std::endl;

	return (0);
}
