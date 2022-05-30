#if STD
 #define NS std
 #include <iostream>
 #include <vector>
 #include <stack>
 #include <map>
#else
 #define NS ft
 #include "inc/vector.hpp"
 #include "inc/stack.hpp"
 #include "inc/map.hpp"
#endif

#include "inc/vector_test.hpp"
#include "inc/stack_test.hpp"

int main(void) {
	ft_test::vector();
	ft_test::stack();

	return (0);
}
