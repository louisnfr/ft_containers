#ifndef VECTOR_TEST_HPP_
#define VECTOR_TEST_HPP_

#include <stdlib.h>

#include <string>
#include <vector>
#include <iostream>

#include "vector.hpp"
#include "utils/logger.hpp"
#include "utils/run_test.hpp"

namespace ft_test {
ft_test::Logger *v_log;

bool	test_vector_empty_constructor() {
	ft::vector<int>		i;
	std::vector<int>	i_og;

	if (i.size() != 0 || i.capacity() != 0)
		return false;
	if (i_og.size() != i.size() || i_og.capacity() != i.capacity())
		return v_log->err("1: size() differs");

	ft::vector<bool> 	b;
	std::vector<bool> 	b_og;

	if (b.size() != 0 || b.capacity() != 0)
		return false;
	if (b_og.size() != b.size() || b_og.capacity() != b.capacity())
		return v_log->err("2: size() differs");
	return true;
}
bool	test_vector_fill_constructor() {
	ft::vector<int> i(10);
	std::vector<int> i_og(10);
	if (i.size() != i_og.size() || i.capacity() != i_og.capacity())
		return v_log->err("1: size() differs");

	ft::vector<int> i1(10, 42);
	std::vector<int> i1_og(10, 42);
	if (i1.size() != i1_og.size() || i1.capacity() != i1_og.capacity())
		return v_log->err("2: size() differs");
	for (size_t i = 0; i < i1.size(); i++)
		if (i1[i] != i1_og[i])
			return v_log->err("3: content() differs");

	ft::vector<int> i2(112, 42);
	std::vector<int> i2_og(112, 42);
	if (i2.size() != i2_og.size() || i2.capacity() != i2_og.capacity())
		return v_log->err("4: size() differs");
	for (size_t i = 0; i < i2.size(); i++)
		if (i2[i] != i2_og[i])
			return v_log->err("5: content() differs");
	return true;
}
bool	test_vector_range_constructor() {
	ft::vector<int> ref(10, 42);
	std::vector<int> ref_og(10, 42);

	ft::vector<int> v(ref.begin(), ref.end());
	std::vector<int> v_og(ref_og.begin(), ref_og.end());
	if (v.size() != v_og.size() || v.capacity() != v_og.capacity())
		return v_log->err("1: size() differs");
	for (size_t i = 0; i < v.size(); i++)
		if (v[i] != v_og[i])
			return v_log->err("2: content() differs");
	return true;
}
bool	test_vector_copy_constructor() {
	ft::vector<int> ref(10, 42);
	std::vector<int> ref_og(10, 42);

	ft::vector<int> v(ref);
	std::vector<int> v_og(ref_og);

	if (v.size() != v_og.size() || v.size() != ref.size()
		|| v.capacity() != v_og.capacity() || v.capacity() != ref.capacity())
		return v_log->err("1: size() differs");
	for (size_t i = 0; i < v.size(); i++)
		if (v[i] != v_og[i])
			return v_log->err("2: content() differs");
	return true;
}

bool	test_vector_destructor() {
	ft::vector<int> *v = new ft::vector<int>(100, 42);

	delete v;
	return true;
}

bool	test_vector_assignement_operator() {
	ft::vector<int> ref(10, 42);
	std::vector<int> ref_og(10, 42);

	ft::vector<int> v = ref;
	std::vector<int> v_og = ref_og;

	if (v.size() != v_og.size() || v.capacity() != v_og.capacity())
		return v_log->err("1: size() differs");

	for (size_t i = 0; i < v.size(); i++)
		if (v[i] != v_og[i])
			return v_log->err("2: content() differs");
	return true;
}

bool	test_vector_begin() {
	ft::vector<int> v;
	std::vector<int> v_og;

	for (int i = 1; i <= 5; i++) {
		v.push_back(i);
		v_og.push_back(i);
	}

	ft::vector<int> store_v;
	std::vector<int> store_v_og;

	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		store_v.push_back(*it);
	for (std::vector<int>::iterator it = v_og.begin(); it != v_og.end(); it++)
		store_v_og.push_back(*it);

	for (int i = 0; i < 5; i++) {
		if (store_v[i] != store_v_og[i])
			return v_log->err("1: content() differs");
	}

	ft::vector<int> store_v2;
	for (ft::vector<int>::const_iterator it = v.begin(); it 	!= v.end(); it++)
		store_v2.push_back(*it);
	for (int i = 0; i < 5; i++) {
		if (store_v[i] != store_v_og[i])
			return v_log->err("2: content() differs");
	}
	return true;
}
bool	test_vector_end() {
	ft::vector<int> v;
	std::vector<int> v_og;

	for (int i = 0; i < 5; i++) {
		v.push_back(i);
		v_og.push_back(i);
	}

	ft::vector<int> store_v;
	std::vector<int> store_v_og;

	for (ft::vector<int>::const_iterator it = v.end();
		it != v.begin(); it--)
		store_v.push_back(*it);
	for (std::vector<int>::const_iterator it = v_og.end();
		it != v_og.begin(); it--)
		store_v_og.push_back(*it);

	if (store_v.size() != store_v_og.size())
		return v_log->err("1: size() differs");

	if (store_v.capacity() != store_v_og.capacity())
		return v_log->err("2: capacity() differs");

	for (unsigned i = 1; i < store_v_og.size(); i++) {
		if (store_v[i] != store_v_og[i])
			return v_log->err("3: content() differs");
	}
	return true;
}
bool	test_vector_rbegin() {
	ft::vector<int> v(5);
	std::vector<int> v_og(5);

	ft::vector<int>::reverse_iterator it = v.rbegin();
	std::vector<int>::reverse_iterator it_og = v_og.rbegin();
	for (int i = 0; it != v.rend(); ++it)
		*it = ++i;
	for (int i = 0; it_og != v_og.rend(); ++it_og)
		*it_og = ++i;

	for (int i = 0; i < 5; i++)
		if (v[i] != v_og[i])
			return v_log->err("1: content() differs");

	int i = 1;
	for (ft::vector<int>::const_reverse_iterator it = v.rbegin();
		it != v.rend(); it++)
		if (*it != i++)
			return v_log->err("2: content() differs");
	return true;
}
bool	test_vector_rend() {
	return true;
}

bool	test_vector_size() {
	ft::vector<int> v(10, 42);
	std::vector<int> v_og(10, 42);

	ft::vector<int> v1;
	std::vector<int> v1_og;

	if (v.size() != v_og.size())
		return v_log->err("1: size() differs");
	if (v1.size() != v1_og.size())
		return v_log->err("2: size() differs");
	return true;
}
bool	test_vector_max_size() {
	ft::vector<int> v(10, 42);
	std::vector<int> v_og(10, 42);

	ft::vector<int> v1;
	std::vector<int> v1_og;

	if (v.max_size() != v_og.max_size())
		return v_log->err("1: max_size() differs");
	if (v1.max_size() != v1_og.max_size())
		return v_log->err("2: max_size() differs");
	return true;
}
bool	test_vector_resize() {
	ft::vector<int> v;
	std::vector<int> v_og;

	for (int i = 1; i < 10; i++) {
		v.push_back(i);
		v_og.push_back(i);
	}

	v.resize(5);
	v_og.resize(5);
	if (v.size() != v_og.size())
		return v_log->err("1: size() differs");
	if (v.capacity() != v_og.capacity())
		return v_log->err("2: capacity() differs");

	v.resize(8, 100);
	v_og.resize(8, 100);
	if (v.size() != v_og.size())
		return v_log->err("3: size() differs");
	if (v.capacity() != v_og.capacity())
		return v_log->err("4: capacity() differs");

	v.resize(12);
	v_og.resize(12);
	if (v.size() != v_og.size())
		return v_log->err("5: size() differs");
	if (v.capacity() != v_og.capacity())
		return v_log->err("6: capacity() differs");

	for (size_t i = 0; i < v_og.size(); i++)
		if (v[i] != v_og[i])
			return v_log->err("7: content() differs");

	ft::vector<int> v1(12, 12);
	std::vector<int> v_og1(12, 12);

	v1.resize(17);
	v_og1.resize(17);

	if (v1.size() != v_og1.size())
		return v_log->err("8: size() differs");

	v1.resize(33);
	v_og1.resize(33);

	if (v1.size() != v_og1.size())
		return v_log->err("9: size() differs");

	v1.resize(800);
	v_og1.resize(800);

	if (v1.size() != v_og1.size())
		return v_log->err("10: size() differs");
	return true;
}
bool	test_vector_capacity() {
	ft::vector<int> v(10, 42);
	std::vector<int> v_og(10, 42);

	ft::vector<int> v1;
	std::vector<int> v1_og;

	if (v.capacity() != v_og.capacity())
		return v_log->err("1: capacity() differs");
	if (v1.capacity() != v1_og.capacity())
		return v_log->err("2: capacity() differs");

	v.push_back(42);
	v_og.push_back(42);
	if (v1.capacity() != v1_og.capacity())
		return v_log->err("3: capacity() differs");

	v1.push_back(42);
	v1_og.push_back(42);
	if (v.capacity() != v_og.capacity())
		return v_log->err("4: capacity() differs");
	return true;
}
bool	test_vector_empty() {
	ft::vector<int> v(10, 42);
	std::vector<int> v_og(10, 42);

	ft::vector<int> v1;
	std::vector<int> v1_og;

	if (v.empty() != v_og.empty())
		return v_log->err("1: empty() differs");
	if (v1.empty() != v1_og.empty())
		return v_log->err("2: empty() differs");
	return true;
}
bool	test_vector_reserve() {
	ft::vector<int> v;
	std::vector<int> v_og;

	if (v.capacity() != v_og.capacity())
		return v_log->err("1: capacity() differs");

	v.reserve(10);
	v_og.reserve(10);
	if (v.capacity() != v_og.capacity())
		return v_log->err("2: capacity() differs");

	v.reserve(100);
	v_og.reserve(100);
	if (v.capacity() != v_og.capacity())
		return v_log->err("3: capacity() differs");

	ft::vector<int> v1(10, 42);
	std::vector<int> v1_og(10, 42);

	if (v1.capacity() != v1_og.capacity())
		return v_log->err("4: capacity() differs");

	v1.reserve(10);
	v1_og.reserve(10);
	if (v1.capacity() != v1_og.capacity())
		return v_log->err("5: capacity() differs");

	v1.reserve(100);
	v1_og.reserve(100);
	if (v1.capacity() != v1_og.capacity())
		return v_log->err("6: capacity() differs");
	return true;
}

bool	test_vector_operator_access() {
	ft::vector<int> v(10, 42);
	std::vector<int> v_og(10, 42);

	for (size_t i = 0; i < v.size(); i++)
		if (v[i] != v_og[i])
			return v_log->err("1: content() differs");

	ft::vector<int> v1(10);
	ft::vector<int>::size_type sz = v1.size();
	for (size_t i = 0; i < sz; i++)
		v1[i] = i;
	for (size_t i = 0; i < sz / 2; i++) {
		int tmp = v1[sz-1-i];
		v1[sz-1-i] = v1[i];
		v1[i] = tmp;
	}
	for (size_t i = 0; i < sz; i++)
		if (v1[i] != 10 - static_cast<int>(i) - 1)
			return v_log->err("2: content() differs");
	return true;
}
bool	test_vector_at() {
	ft::vector<int> v(10);
	std::vector<int> v_og(10);

	for (size_t i = 0; i < v.size(); i++)
		v.at(i) = i;
	for (size_t i = 0; i < v_og.size(); i++)
		v_og.at(i) = i;

	for (size_t i = 0; i < v.size(); i++)
		if (v.at(i) != v_og.at(i))
			return v_log->err("1: content() differs");
	return true;
}
bool	test_vector_front() {
	ft::vector<int> v;
	std::vector<int> v_og;

	v.push_back(78);
	v_og.push_back(78);

	if (v.front() != v_og.front())
		return v_log->err("1: front() differs");

	v.push_back(16);
	v_og.push_back(16);

	v.front() -= v.back();
	v_og.front() -= v_og.back();

	if (v.front() != v_og.front() || v.front() != 62)
		return v_log->err("2: front() differs");
	return true;
}
bool	test_vector_back() {
	ft::vector<int> v;

	v.push_back(10);

	while (v.back() != 0) {
		v.push_back(v.back() - 1);
	}

	if (v.size() != 11)
		return v_log->err("1: size() differs");

	for (unsigned i = 0; i < v.size(); i++)
		if (v[i] != 10 - static_cast<int>(i))
			return v_log->err("2: content() differs");

	return true;
}

bool	test_vector_assign() {
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign(7, 100);

	ft::vector<int>::iterator it = first.begin() + 1;
	second.assign(it, first.end() - 1);
	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 3);

	if (first.size() != 7)
		return v_log->err("1: size() differs");
	if (second.size() != 5)
		return v_log->err("2: size() differs");
	if (third.size() != 3)
		return v_log->err("3: size() differs");
	return true;
}

bool	test_vector_push_back() {
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	if (v.size() != 10)
		return v_log->err("1: size() differs");
	for (int i = 0; i < 10; i++) {
		if (v[i] != i)
			return v_log->err("2: content() differs");
	}
	return true;
}

bool	test_vector_pop_back() {
	ft::vector<int> v;

	int sum(0);
	v.push_back(100);
	v.push_back(200);
	v.push_back(300);

	while (!v.empty()) {
		sum += v.back();
		v.pop_back();
	}
	if (sum != 600)
		return v_log->err("1: sum() differs");
	return true;
}

bool	test_vector_insert() {
	ft::vector<int> v(3, 100);
	ft::vector<int>::iterator it;

	it = v.begin();
	it = v.insert(it, 200);
	int	nums0[] = {200, 100, 100, 100};
	for (unsigned i = 0; i < v.size(); i++) {
		if (v[i] != nums0[i])
			return v_log->err("0: content() differs");
	}

	v.insert(it, 2, 300);
	it = v.begin();
	int nums1[] = {300, 300, 200, 100, 100, 100};
	for (unsigned i = 0; i < v.size(); i++) {
		if (v[i] != nums1[i]) {
			for (unsigned k = 0; k < v.size(); k++)
				std::cout << v[k] << " ";
			return v_log->err("1: content() differs");
		}
	}

	ft::vector<int> v2(2, 400);
	v.insert(it + 2, v2.begin(), v2.end());

	int myarray[] = {501, 502, 503};
	v.insert(v.begin(), myarray, myarray + 3);

	int nums[] = {501, 502, 503, 300, 300, 400, 400, 200, 100, 100, 100};
	int i = 0;
	for (it = v.begin(); it != v.end(); it++, i++) {
		if (*it != nums[i]) {
			std::cout << "Had: ";
			for (unsigned k = 0; k < v.size(); k++)
				std::cout << v[k] << " ";
			std::cout << std::endl;
			return v_log->err("2: content() differs");
		}
	}
	return true;
}

bool	test_vector_erase() {
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	// erase the 6th element
	myvector.erase(myvector.begin()+5);

	int nums1[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
	for (unsigned i = 0; i < myvector.size(); i++)
		if (myvector[i] != nums1[i])
			return v_log->err("1: content() differs");

	// erase the first 3 elements:
	myvector.erase(myvector.begin(), myvector.begin() + 3);

	int nums2[] = {4, 5, 7, 8, 9, 10};
	for (unsigned i = 0; i < myvector.size(); ++i) {
		if (myvector[i] != nums2[i]) {
			for (unsigned k = 0; k < myvector.size(); ++k)
				std::cout << myvector[k] << " ";
			return v_log->err("2: content() differs");
		}
	}
	return true;
}

bool	test_vector_swap() {
	ft::vector<int> v1(3, 100);
	ft::vector<int> v2(5, 100);

	v1.swap(v2);
	if (v1.size() != 5 || v1.capacity() != 5 || v1[0] != 100 || v1[1] != 100
		|| v1[2] != 100 || v1[3] != 100 || v1[4] != 100)
		return v_log->err("1: swap failed");
	if (v2.size() != 3 || v2.capacity() != 3 || v2[0] != 100 || v2[1] != 100
		|| v2[2] != 100)
		return v_log->err("2: swap failed");
	return true;
}

bool	test_vector_clear() {
	ft::vector<int> myvector;
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	int	nums[] = {100, 200, 300};
	for (unsigned i = 0; i < myvector.size(); i++)
		if (myvector[i] != nums[i])
			return v_log->err("1: content() differs");

	myvector.clear();
	myvector.push_back(1101);
	myvector.push_back(2202);

	int nums2[] = {1101, 2202};
	for (unsigned i = 0; i < myvector.size(); i++)
		if (myvector[i] != nums2[i])
			return v_log->err("2: content() differs");

	return true;
}

bool	test_vector_allocator() {
	ft::vector<int> v;
	int	*p = 0;
	unsigned int i = 0;

	p = v.get_allocator().allocate(5);
	for (i = 0; i < 5; i++)
		v.get_allocator().construct(&p[i], i);
	for (i = 0; i < 5; i++)
		if (p[i] != static_cast<int>(i))
			return v_log->err("1: allocator() failed");
	for (i = 0; i < 5; i++)
		v.get_allocator().destroy(&p[i]);
  	v.get_allocator().deallocate(p, 5);
	return true;
}

bool	test_vector_non_member_function_operator() {
	ft::vector<int> v1(3, 100);
	ft::vector<int> v2(2, 200);

	std::vector<int> v1_og(3, 100);
	std::vector<int> v2_og(2, 200);

	if ((v1 == v2) != (v1_og == v2_og))
		return v_log->err("operator == failed");
	if ((v1 != v2) != (v1_og != v2_og))
		return v_log->err("operator != failed");
	if ((v1 < v2) != (v1_og < v2_og))
		return v_log->err("operator < failed");
	if ((v1 > v2) != (v1_og > v2_og))
		return v_log->err("operator > failed");
	if ((v1 <= v2) != (v1_og <= v2_og))
		return v_log->err("operator <= failed");
	if ((v1 >= v2) != (v1_og >= v2_og))
		return v_log->err("operator >= failed");
	return true;
}

bool	test_vector_non_member_function_swap() {
	ft::vector<int> v1(3, 100);
	ft::vector<int> v2(5, 100);

	v1.swap(v2);
	if (v1.size() != 5 || v1.capacity() != 5 || v1[0] != 100 || v1[1] != 100
		|| v1[2] != 100 || v1[3] != 100 || v1[4] != 100)
		return v_log->err("1: swap failed");
	if (v2.size() != 3 || v2.capacity() != 3 || v2[0] != 100 || v2[1] != 100
		|| v2[2] != 100)
		return v_log->err("2: swap failed");
	return true;
}

bool	benchmark_vector_constructor() {
	time_t start = clock();
	ft::vector<int> *v = new ft::vector<int>(10000000, 42);
	time_t end = clock();
	delete v;

	time_t start_og = clock();
	std::vector<int> *v_og = new std::vector<int>(10000000, 42);
	time_t end_og = clock();
	delete v_og;

	return v_log->benchmark(end - start, end_og - start_og);
}
bool	benchmark_vector_destructor() {
	ft::vector<int> *v = new ft::vector<int>(10000000, 42);
	time_t start = clock();
	delete v;
	time_t end = clock();

	std::vector<int> *v_og = new std::vector<int>(10000000, 42);
	time_t start_og = clock();
	delete v_og;
	time_t end_og = clock();

	return v_log->benchmark(end - start, end_og - start_og);
}
bool	benchmark_vector_assignement_operator() {
	ft::vector<int> *v = new ft::vector<int>(10000000, 42);
	std::vector<int> *v_og = new std::vector<int>(10000000, 42);

	time_t start = clock();
	ft::vector<int> *v2 = new ft::vector<int>(*v);
	time_t end = clock();

	time_t start_og = clock();
	std::vector<int> *v2_og = new std::vector<int>(*v_og);
	time_t end_og = clock();


	delete v;
	delete v_og;

	for (size_t i = 0; i < v2->size(); i++)
		if (v2->at(i) != v2_og->at(i))
			return v_log->err("content differs from original container");
	delete v2;
	delete v2_og;
	return v_log->benchmark(end - start, end_og - start_og);
}
bool	benchmark_vector_assign() {
	ft::vector<int> *v = new ft::vector<int>(10, 42);
	std::vector<int> *v_og = new std::vector<int>(10, 42);

	time_t start = clock();
	v->assign(10000000, 42);
	time_t end = clock();

	time_t start_og = clock();
	v_og->assign(10000000, 42);
	time_t end_og = clock();

	delete v;
	delete v_og;
	return v_log->benchmark(end - start, end_og - start_og);
}
bool	benchmark_vector_push_back() {
	ft::vector<int> *v = new ft::vector<int>(10, 42);
	std::vector<int> *v_og = new std::vector<int>(10, 42);

	time_t start = clock();
	for (size_t i = 0; i < 1000000; i++)
		v->push_back(42);
	time_t end = clock();

	time_t start_og = clock();
	for (size_t i = 0; i < 1000000; i++)
		v_og->push_back(42);
	time_t end_og = clock();

	delete v;
	delete v_og;
	return v_log->benchmark(end - start, end_og - start_og);
}
bool	benchmark_vector_insert_regular() {
	ft::vector<int> *v = new ft::vector<int>(10000, 42);
	std::vector<int> *v_og = new std::vector<int>(10000, 42);

	time_t start = clock();
	for (size_t i = 0; i < 10000; i++)
		v->insert(v->begin(), 42);
	time_t end = clock();

	time_t start_og = clock();
	for (size_t i = 0; i < 10000; i++)
		v_og->insert(v_og->begin(), 42);
	time_t end_og = clock();

	if (v_og->size() != v->size())
		return v_log->err("size differs");
	for (size_t i = 0; i < v_og->size(); i++)
		if (v->at(i) != v_og->at(i))
			return v_log->err("content differs from original container");

	delete v;
	delete v_og;
	return v_log->benchmark(end - start, end_og - start_og);
}
bool	benchmark_vector_insert_n() {
	ft::vector<int> *v = new ft::vector<int>(10000, 42);
	std::vector<int> *v_og = new std::vector<int>(10000, 42);
	std::vector<int> n;
	size_t	num_it = 1000;

	unsigned int seed = time(NULL);
	for (size_t i = 0; i < num_it; i++) {
		int buf;
		buf = rand_r(&seed) % 100 + 1;
		n.push_back(buf);
	}

	time_t start = clock();
	for (size_t i = 0; i < num_it; i++)
		v->insert(v->begin(), 42, n[i]);
	time_t end = clock();

	time_t start_og = clock();
	for (size_t i = 0; i < num_it; i++)
		v_og->insert(v_og->begin(), 42, n[i]);
	time_t end_og = clock();

	if (v_og->size() != v->size())
		return v_log->err("size differs");
	for (size_t i = 0; i < v_og->size(); i++)
		if (v->at(i) != v_og->at(i))
			return v_log->err("content differs from original container");

	delete v;
	delete v_og;
	return v_log->benchmark(end - start, end_og - start_og);
}
bool	benchmark_vector_insert_range() {
	ft::vector<int> *v = new ft::vector<int>(10000, 42);
	std::vector<int> *v_og = new std::vector<int>(10000, 42);

	int	myArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int	arrSize = 10;

	time_t start = clock();
	for (size_t i = 0; i < 1000; i++)
		v->insert(v->begin(), myArr, myArr + arrSize);
	time_t end = clock();

	time_t start_og = clock();
	for (size_t i = 0; i < 1000; i++)
		v_og->insert(v_og->begin(), myArr, myArr + arrSize);
	time_t end_og = clock();

	if (v_og->size() != v->size())
		return v_log->err("size differs");
	for (size_t i = 0; i < v_og->size(); i++)
		if (v->at(i) != v_og->at(i))
			return v_log->err("content differs from original container");

	delete v;
	delete v_og;
	return v_log->benchmark(end - start, end_og - start_og);
}
bool	benchmark_vector_erase() {
	ft::vector<int> *v = new ft::vector<int>(10000, 42);
	std::vector<int> *v_og = new std::vector<int>(10000, 42);

	time_t start = clock();
	for (size_t i = 0; i < 10000; i++)
		v->erase(v->begin());
	time_t end = clock();

	time_t start_og = clock();
	for (size_t i = 0; i < 10000; i++)
		v_og->erase(v_og->begin());
	time_t end_og = clock();

	delete v;
	delete v_og;
	return v_log->benchmark(end - start, end_og - start_og);
}

void	vector() {
	v_log = new ft_test::Logger("vector");

	v_log->section("CONSTRUCTORS");
	ft_test::run(v_log, &test_vector_empty_constructor, "Empty Constructor");
	ft_test::run(v_log, &test_vector_fill_constructor, "Fill Constructor");
	ft_test::run(v_log, &test_vector_range_constructor, "Range Constructor");
	ft_test::run(v_log, &test_vector_copy_constructor, "Copy Constructor");

	v_log->section("DESTRUCTOR");
	ft_test::run(v_log, &test_vector_destructor, "Destructor");

	v_log->section("ASSIGNEMENT OPERATOR");
	ft_test::run(v_log, &test_vector_assignement_operator, "Assignement Operator");


	v_log->section("ITERATORS");
	ft_test::run(v_log, &test_vector_begin, "Begin");
	ft_test::run(v_log, &test_vector_end, "End");
	ft_test::run(v_log, &test_vector_rbegin, "RBegin");
	ft_test::run(v_log, &test_vector_rend, "REnd");

	v_log->section("CAPACITY");
	ft_test::run(v_log, &test_vector_size, "Size");
	ft_test::run(v_log, &test_vector_max_size, "Max Size");
	ft_test::run(v_log, &test_vector_resize, "Resize");
	ft_test::run(v_log, &test_vector_capacity, "Capacity");
	ft_test::run(v_log, &test_vector_empty, "Empty");
	ft_test::run(v_log, &test_vector_reserve, "Reserve");


	v_log->section("ELEMENT ACCESS");
	ft_test::run(v_log, &test_vector_operator_access, "Operator []");
	ft_test::run(v_log, &test_vector_at, "At");
	ft_test::run(v_log, &test_vector_front, "Front");
	ft_test::run(v_log, &test_vector_back, "Back");

	v_log->section("MODIFIERS");
	ft_test::run(v_log, &test_vector_assign, "Assign");
	ft_test::run(v_log, &test_vector_push_back, "Push Back");
	ft_test::run(v_log, &test_vector_pop_back, "Pop Back");
	ft_test::run(v_log, &test_vector_insert, "Insert");
	ft_test::run(v_log, &test_vector_erase, "Erase");
	ft_test::run(v_log, &test_vector_swap, "Swap");
	ft_test::run(v_log, &test_vector_clear, "Clear");

	v_log->section("ALLOCATOR");
	ft_test::run(v_log, &test_vector_allocator, "Allocator");

	v_log->section("NON-MEMBER FUNCTION OVERLOADS");
	ft_test::run(v_log, &test_vector_non_member_function_operator,
		"Non-member function operators");
	ft_test::run(v_log, &test_vector_non_member_function_swap,
		"Non-member function swap");

	#ifdef FT_BENCHMARK
	v_log->section("BENCHMARKS");
	ft_test::run(v_log, &benchmark_vector_constructor, "Benchmark Constructor");
	ft_test::run(v_log, &benchmark_vector_destructor, "Benchmark Destructor");
	ft_test::run(v_log, &benchmark_vector_assignement_operator,
		"Benchmark Assign Op");
	ft_test::run(v_log, &benchmark_vector_assign, "Benchmark Assign\t");
	ft_test::run(v_log, &benchmark_vector_push_back, "Benchmark Push Back");
	ft_test::run(v_log, &benchmark_vector_insert_regular,
		"Benchmark Insert Regular");
	ft_test::run(v_log, &benchmark_vector_insert_n, "Benchmark Insert N");
	ft_test::run(v_log, &benchmark_vector_insert_range, "Benchmark Insert Range");
	ft_test::run(v_log, &benchmark_vector_erase, "Benchmark Erase\t");
	#endif
	delete v_log;
}
}  // namespace ft_test

#endif  // VECTOR_TEST_HPP_
