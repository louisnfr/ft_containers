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

int main(void) {
	NS::vector<int> vect;
	NS::vector<int> v(10, 10);

	for (size_t i = 0; i < 5; i++)
		vect.push_back(i);

	v.at(0) = 42;

	std::cout << v.front() << std::endl;
	std::cout << v.back() << std::endl;
	std::cout << v.size() << std::endl;

	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;


	// capacity and reserve throw error test
	NS::vector<int>::size_type sz;
	NS::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
		sz = foo.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	NS::vector<int> bar;
	sz = bar.capacity();
	std::cout << bar.max_size() << std::endl;
	try
	{
		bar.reserve(2305843009213693959);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
		sz = bar.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	// size and empty tests
	NS::vector<int> vct;
	std::cout << vct.capacity() << std::endl;
	std::cout << vct.size() << std::endl;
	std::cout << vct.empty() << std::endl;
	std::cout << "PUSH_BACK" << std::endl;
	vct.push_back(1);
	std::cout << vct.capacity() << std::endl;
	std::cout << vct.size() << std::endl;
	std::cout << vct.empty() << std::endl;
	vct.pop_back();
	std::cout << vct.capacity() << std::endl;
	std::cout << vct.size() << std::endl;
	std::cout << vct.empty() << std::endl;
	return (0);
}
