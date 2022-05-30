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
 #include "inc/map.hpp"
 #define diff "ft"
#endif

#include "inc/vector_test.hpp"


int main(void) {
	ft_test::vector();

	return (0);
}
