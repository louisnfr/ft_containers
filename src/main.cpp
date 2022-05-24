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

	NS::vector<int> ref(10, 42);

	NS::vector<int> v(ref.begin(), ref.end());
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;

	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;

	// NS::vector<int> ref(10, 42);

	// NS::vector<int> v(ref.begin(), ref.end());
	// std::cout << v.size() << std::endl;
	// std::cout << v.capacity() << std::endl;

	// for (NS::vector<int>::iterator ite = v.begin(); ite != v.end(); ++ite)
	// 	std::cout << *ite << std::endl;

	// NS::vector<int> vect;
	// NS::vector<int> v;
	// std::cout << "size: " << v.size() << std::endl;

	// for (size_t i = 0; i < 5; i++)
	// 	v.push_back(i);

	// std::cout << "capacity: " << v.capacity() << std::endl;
	// v.resize(5, 49);

	// std::cout << "capacity: " << v.capacity() << std::endl;
	// for (NS::vector<int>::iterator ite = v.begin(); ite != v.end(); ++ite)
	// 	std::cout << *ite << std::endl;
	// std::cout << "size: " << v.size() << std::endl;

	// delete v;
	// v.push_back(468);
	// v.push_back(0);
	// v.push_back(-2);
	// v.push_back(4);


	// for (NS::vector<int>::iterator ite = v.begin(); ite != v.end(); ++ite)
	// 	std::cout << *ite << std::endl;

	// std::cout << std::endl;

	// NS::vector<int>::iterator it = v.begin();
	// std::cout << it[3] << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// std::cout << *it << std::endl;
	// std::cout << *it << std::endl;

	// v.at(0) = 42;

	// std::cout << v.front() << std::endl;
	// std::cout << v.back() << std::endl;
	// std::cout << v.size() << std::endl;

	// for (; it != v.end(); ++it)
	// 	std::cout << *it << std::endl;

	// int o = -1;
	// while(++o < 1)
	// 	++it;

	// std::cout << &(*it) << std::endl;
	// ++it;
	// std::cout << &(*it) << std::endl;

	// // capacity and reserve throw error test
	// NS::vector<int>::size_type sz;
	// NS::vector<int> foo;
	// sz = foo.capacity();
	// std::cout << "making foo grow:\n";
	// for (int i = 0; i < 100; ++i) {
	// 	foo.push_back(i);
	// 	if (sz != foo.capacity()) {
	// 	sz = foo.capacity();
	// 	std::cout << "capacity changed: " << sz << '\n';
	// 	}
	// }

	// NS::vector<int> bar;
	// sz = bar.capacity();
	// std::cout << bar.max_size() << std::endl;
	// // try {
	// // 	bar.reserve(2305843009213693959);
	// // }
	// // catch(const std::exception& e) {
	// // 	std::cerr << e.what() << '\n';
	// // }

	// std::cout << "making bar grow:\n";
	// for (int i = 0; i < 100; ++i) {
	// 	bar.push_back(i);
	// 	if (sz != bar.capacity()) {
	// 	sz = bar.capacity();
	// 	std::cout << "capacity changed: " << sz << '\n';
	// 	}
	// }

	// // size and empty tests
	// NS::vector<int> vct;
	// std::cout << vct.capacity() << std::endl;
	// std::cout << vct.size() << std::endl;
	// std::cout << vct.empty() << std::endl;
	// std::cout << "PUSH_BACK" << std::endl;
	// vct.push_back(1);
	// std::cout << vct.capacity() << std::endl;
	// std::cout << vct.size() << std::endl;
	// std::cout << vct.empty() << std::endl;
	// vct.pop_back();
	// std::cout << vct.capacity() << std::endl;
	// std::cout << vct.size() << std::endl;
	// std::cout << vct.empty() << std::endl;

	return (0);
}
