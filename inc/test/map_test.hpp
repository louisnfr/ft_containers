#pragma once

#include "inc/test/logger.hpp"
#include "inc/test/run_test.hpp"
#include "inc/test/compare_test.hpp"

namespace ft_test {

ft_test::Logger *m_log;

bool	test_map_default_constructor() {
	ft::map<int, char> intcharmap;
	ft::map<char, int> charintmap;

	ft::map<bool, bool> boolboolmap;

	ft::map<char, int, classcomp> fourth;  // class as Compare

	bool(*fn_pt)(int, int) = fncomp;
	ft::map<char, int, bool(*)(int, int)>
		fifth(fn_pt);  // function pointer as Compare
	return true;
}
bool	test_map_range_constructor() {
	ft::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	ft::map<char, int> second(first.begin(), first.end());
	if (second.size() != 4 || second.empty())
		return false;

	ft::map<char, int> third(second.begin(), second.end());
	if (third.size() != 4 || third.empty())
		return m_log->err("1: range constructor failed");

	if (third.find('a')->second != 10)
		return m_log->err("2: range constructor failed");

	if (third.find('b')->second != 30)
		return m_log->err("3: range constructor failed");

	if (third.find('c')->second != 50)
		return m_log->err("4: range constructor failed");

	if (third.find('d')->second != 70)
		return m_log->err("5: range constructor failed");

	if (third['d'] != 70)
		return m_log->err("6: range constructor failed");
	return true;
}
bool	test_map_copy_constructor() {
	ft::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	ft::map<char, int> second(first);

	if (second.size() != 4 || second.empty())
		return m_log->err("1: copy constructor failed");

	if (second.find('a')->second != 10)
		return m_log->err("2: copy constructor failed");

	if (second.find('b')->second != 30)
		return m_log->err("3: copy constructor failed");

	if (second.find('c')->second != 50)
		return m_log->err("4: copy constructor failed");

	if (second.find('d')->second != 70)
		return m_log->err("5: copy constructor failed");
	return true;
}

bool	test_map_destructor() {
	ft::map<char, int> *mymap = new ft::map<char, int>;

	for (int i = 0; i < 10; ++i)
		mymap->insert(
			ft::make_pair<char, int>('a' + i, i * 10));

	delete mymap;
	return true;
}

bool	test_map_assignement_operator() {
	ft::map<char, int> first;
	ft::map<char, int> second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;

	second = first;
	if (second.size() != 3)
		return m_log->err("1: assignement operator failed");

	first = ft::map<char, int>();
	if (first.size() != 0 || !first.empty())
		return m_log->err("2: assignement operator failed");

	first = second;
	if (first.size() != 3 || first.size() != second.size() || first.empty())
		return m_log->err("3: assignement operator failed");

	if (first['x'] != 8)
		return m_log->err("4: assignement operator failed");

	if (first['z'] != second['z'])
		return m_log->err("5: assignement operator failed");
	return true;
}

bool	test_map_begin() {
	int myints[] = { 75, 23, 65, 42, 13 };
	ft::map<int, int> mymap;
	std::map<int, int> stdmap;

	for (int i = 0; i < 5; i++) {
		mymap.insert(ft::make_pair<int, int>(i, myints[i]));
		stdmap.insert(std::make_pair<int, int>(i, myints[i]));
	}

	ft::map<int, int>::iterator it = mymap.begin();
	std::map<int, int>::iterator it2 = stdmap.begin();
	for (; it != mymap.end(); ++it, ++it2) {
		if (it->second != it2->second)
			return m_log->err("1: begin failed");
	}
	return true;
}
bool	test_map_end() {
	int myints[] = { 75, 23, 65, 42, 13 };
	ft::map<int, int> mymap;
	std::map<int, int> stdmap;

	for (int i = 0; i < 5; i++) {
		mymap.insert(ft::make_pair<int, int>(i, myints[i]));
		stdmap.insert(std::make_pair<int, int>(i, myints[i]));
	}

	ft::map<int, int>::iterator it = mymap.end();
	std::map<int, int>::iterator it2 = stdmap.end();

	--it;
	--it2;
	for (; it != mymap.begin(); --it, --it2) {
		if (it->second != it2->second)
			return m_log->err("1: begin failed");
	}
	return true;
}
bool	test_map_rbegin() {
	int myints[] = { 75, 23, 65, 42, 13 };
	ft::map<int, int> mymap;
	std::map<int, int> stdmap;

	for (int i = 0; i < 5; i++) {
		mymap.insert(ft::make_pair<int, int>(i, myints[i]));
		stdmap.insert(std::make_pair<int, int>(i, myints[i]));
	}

	ft::map<int, int>::reverse_iterator it = mymap.rbegin();
	std::map<int, int>::reverse_iterator it2 = stdmap.rbegin();
	for (; it != mymap.rend(); ++it, ++it2) {
		if (it->second != it2->second)
			return m_log->err("1: begin failed");
	}
	return true;
}
bool	test_map_rend() {
	int myints[] = { 75, 23, 65, 42, 13 };
	ft::map<int, int> mymap;
	std::map<int, int> stdmap;

	for (int i = 0; i < 5; i++) {
		mymap.insert(ft::make_pair<int, int>(i, myints[i]));
		stdmap.insert(std::make_pair<int, int>(i, myints[i]));
	}

	ft::map<int, int>::reverse_iterator it = mymap.rend();
	std::map<int, int>::reverse_iterator it2 = stdmap.rend();

	--it;
	--it2;
	for (; it != mymap.rbegin(); --it, --it2) {
		if (it->second != it2->second)
			return m_log->err("1: begin failed");
	}
	return true;
}

bool	test_map_empty() {
	ft::map<char, int> mymap;

	if (!mymap.empty())
		return m_log->err("1: empty failed");

	mymap['a'] = 1;
	if (mymap.empty())
		return m_log->err("2: empty failed");

	mymap.clear();
	if (!mymap.empty())
		return m_log->err("3: empty failed");

	mymap['a'] = 1;
	mymap['b'] = 2;
	mymap['c'] = 3;

	if (mymap.empty())
		return m_log->err("4: empty failed");

	mymap.erase('a');
	if (mymap.empty())
		return m_log->err("5: empty failed");

	mymap.erase('b');
	if (mymap.empty())
		return m_log->err("6: empty failed");

	mymap.erase('c');
	if (!mymap.empty())
		return m_log->err("7: empty failed");
	return true;
}
bool	test_map_size() {
	ft::map<char, int> mymap;

	if (mymap.size() != 0)
		return m_log->err("1: size failed");

	mymap['a'] = 1;
	if (mymap.size() != 1)
		return m_log->err("2: size failed");

	mymap['b'] = 2;
	if (mymap.size() != 2)
		return m_log->err("3: size failed");

	mymap.erase('a');
	if (mymap.size() != 1)
		return m_log->err("4: size failed");

	mymap.erase('b');
	if (mymap.size() != 0)
		return m_log->err("5: size failed");

	mymap['a'] = 1;
	mymap['b'] = 2;
	mymap['c'] = 3;
	if (mymap.size() != 3)
		return m_log->err("6: size failed");
	return true;
}
bool	test_map_max_size() {
	// https://discord.com/channels/774300457157918772/785407584608714802/913052503736737832
	ft::map<int, int> mymap;
	std::map<int, int> theirmap;

	if (mymap.max_size() != theirmap.max_size())
		return m_log->err("1: max_size failed");
	return true;
}

bool	test_map_operator_access() {
	ft::map<char, int> mymap;

	mymap['a'] = 1;
	mymap['b'] = 2;
	mymap['c'] = mymap['b'];

	if (mymap['a'] != 1)
		return m_log->err("1: operator[] failed");

	if (mymap['b'] != 2)
		return m_log->err("2: operator[] failed");

	if (mymap['c'] != mymap['b'])
		return m_log->err("3: operator[] failed");
	return true;
}

bool	test_map_insert() {
	ft::map<char, int> mymap;

	mymap.insert(ft::make_pair<char, int>('a', 100));
	mymap.insert(ft::make_pair<char, int>('z', 200));

	ft::pair<ft::map<char, int>::iterator, bool> ret;
	ret = mymap.insert(ft::make_pair<char, int>('z', 500));
	if (ret.second)
		return m_log->err("1: insert failed");

	ft::map<char, int>::iterator it = mymap.begin();
	mymap.insert(it, ft::make_pair<char, int>('b', 300));
	mymap.insert(it, ft::make_pair<char, int>('c', 400));

	if (mymap['a'] != 100)
		return m_log->err("2: insert failed");
	if (mymap['b'] != 300)
		return m_log->err("3: insert failed");
	if (mymap['c'] != 400)
		return m_log->err("4: insert failed");
	if (mymap['z'] != 200)
		return m_log->err("5: insert failed");

	ft::map<char, int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));

	if (mymap.size() != 4)
		return m_log->err("6: insert failed");
	if (anothermap.size() != 2)
		return m_log->err("7: insert failed");

	if (mymap['a'] != 100)
		return m_log->err("8: insert failed");
	if (mymap['b'] != 300)
		return m_log->err("9: insert failed");
	if (mymap['c'] != 400)
		return m_log->err("10: insert failed");
	if (mymap['z'] != 200)
		return m_log->err("11: insert failed");

	if (anothermap['a'] != 100)
		return m_log->err("12: insert failed");
	if (anothermap['b'] != 300)
		return m_log->err("13: insert failed");
	return true;
}
bool	test_map_erase() {
	ft::map<char, int> mymap;
	ft::map<char, int>::iterator it;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	it = mymap.find('b');
	mymap.erase(it);
	if (mymap.size() != 5)
		return m_log->err("1: erase failed");

	mymap.erase('c');
	if (mymap.size() != 4)
		return m_log->err("1: erase failed");

	it = mymap.find('e');
	mymap.erase(it, mymap.end());

	if (mymap.size() != 2)
		return m_log->err("1: erase failed");

	if (mymap['a'] != 10)
		return m_log->err("2: erase failed");

	if (mymap['d'] != 40)
		return m_log->err("3: erase failed");
	return true;
}
bool	test_map_swap() {
	ft::map<char, int> foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	foo.swap(bar);

	if (foo.size() != 3)
		return m_log->err("1: swap failed");

	if (bar.size() != 2)
		return m_log->err("2: swap failed");

	if (foo['a'] != 11)
		return m_log->err("3: swap failed");

	if (foo['b'] != 22)
		return m_log->err("4: swap failed");

	if (foo['c'] != 33)
		return m_log->err("5: swap failed");

	if (bar['x'] != 100)
		return m_log->err("6: swap failed");

	if (bar['y'] != 200)
		return m_log->err("7: swap failed");
	return true;
}
bool	test_map_clear() {
	ft::map<char, int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	if (mymap.size() != 3)
		return m_log->err("1: clear failed");

	mymap.clear();

	if (mymap.size() != 0)
		return m_log->err("2: clear failed");

	mymap['a'] = 1101;
	mymap['b'] = 2202;

	if (mymap.size() != 2)
		return m_log->err("3: clear failed");

	if (mymap['a'] != 1101)
		return m_log->err("4: clear failed");
	if (mymap['b'] != 2202)
		return m_log->err("5: clear failed");
	if (mymap['x'] != 0)
		return m_log->err("6: clear failed");

	return true;
}

bool	test_map_key_comp() {
	ft::map<char, int> mymap;
	ft::map<char, int>::key_compare mycomp = mymap.key_comp();

	if (mycomp('a', 'b') != true)
		return m_log->err("1: key_comp failed");

	if (mycomp('b', 'a') != false)
		return m_log->err("2: key_comp failed");

	if (mycomp('a', 'a') != false)
		return m_log->err("3: key_comp failed");

	if (mycomp('b', 'b') != false)
		return m_log->err("4: key_comp failed");

	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;

	char highest = mymap.rbegin()->first;

	if (mycomp(highest, 'c') != 0)
		return m_log->err("5: key_comp failed");

	if (mycomp('c', highest) != 0)
		return m_log->err("6: key_comp failed");

	if (mycomp('c', 'b') > 0)
		return m_log->err("7: key_comp failed");

	return true;
}
bool	test_map_value_comp() {
	ft::map<char, int> mymap;

	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	ft::pair<char, int> highest = *mymap.rbegin();
	ft::map<char, int>::iterator it = mymap.begin();
	for (int i = 1; mymap.value_comp()(*it, highest); i++) {
		if (it->second != i * 1001)
			return m_log->err("1: value_comp failed");
		++it;
	}

	return true;
}

bool	test_map_find() {
	ft::map<char, int> mymap;
	ft::map<char, int>::iterator it;

	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase(it);

	if (mymap.size() != 3)
		return m_log->err("1: find failed");

	if (mymap['a'] != 50)
		return m_log->err("2: find failed");

	if (mymap['c'] != 150)
		return m_log->err("3: find failed");

	if (mymap['d'] != 200)
		return m_log->err("4: find failed");
	return true;
}
bool	test_map_count() {
	ft::map<char, int> mymap;

	mymap['a'] = 101;
	mymap['b'] = 202;
	mymap['c'] = 303;

	char c = 'a';

	for (; c < 'h'; c++) {
		if (c > 'c' && mymap.count(c) != 0)
				return m_log->err("1: count failed");
		else if (c <= 'c' && mymap.count(c) != 1)
			return m_log->err("2: count failed");
	}
	return true;
}
bool	test_map_lower_bound() {
	ft::map<char, int> mymap;
	ft::map<char, int>::iterator itlow, itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

	mymap.erase(itlow, itup);

	if (mymap.size() != 2)
		return m_log->err("1: lower_bound failed");

	if (mymap['a'] != 20)
		return m_log->err("2: lower_bound failed");

	if (mymap['e'] != 100)
		return m_log->err("3: lower_bound failed");
	return true;
}
bool	test_map_upper_bound() {
	ft::map<char, int> mymap;
	ft::map<char, int>::iterator itlow, itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

	mymap.erase(itlow, itup);

	if (mymap.size() != 2)
		return m_log->err("1: upper_bound failed");

	if (mymap['a'] != 20)
		return m_log->err("2: upper_bound failed");

	if (mymap['e'] != 100)
		return m_log->err("3: upper_bound failed");
	return true;
}
bool	test_map_equal_range() {
	ft::map<char, int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
	ret = mymap.equal_range('b');

	if (ret.first->second != 20)
		return m_log->err("1: equal_range failed");

	if (ret.second->second != 30)
		return m_log->err("2: equal_range failed");

	if (ret.first->first != 'b')
		return m_log->err("3: equal_range failed");

	if (ret.second->first != 'c')
		return m_log->err("4: equal_range failed");

	return true;
}

bool	test_map_allocator() {
	int psize;
	ft::map<char, int> mymap;
	ft::pair<char, int> *p;

	p = mymap.get_allocator().allocate(5);

	psize = sizeof(ft::map<char, int>::value_type) * 5;

	if (psize != 40)
		return m_log->err("1: allocator failed");

	mymap.get_allocator().deallocate(p, 5);

	return true;
}

bool	benchmark_map_constructor() {
	ft::map<int, int> ftrf;
	std::map<int, int> stdrf;

	for (int i = 0; i < 100000; ++i) {
		ftrf.insert(ft::make_pair(i, i));
		stdrf.insert(std::make_pair(i, i));
	}

	time_t start = clock();
	ft::map<int, int> *ftset = new ft::map<int, int>(ftrf.begin(), ftrf.end());
	time_t end = clock();

	time_t start2 = clock();
	std::map<int, int> *stdsets =
		new std::map<int, int>(stdrf.begin(), stdrf.end());
	time_t end2 = clock();

	delete ftset;
	delete stdsets;

	return m_log->benchmark(end-start, end2-start2);
}
bool	benchmark_map_destructor() {
	ft::map<int, int> *ftrf = new ft::map<int, int>();
	std::map<int, int> *stdrf = new std::map<int, int>();

	for (int i = 0; i < 50000; ++i) {
		ftrf->insert(ft::make_pair(i, i));
		stdrf->insert(std::make_pair(i, i));
	}

	time_t start = clock();
	delete ftrf;
	time_t end = clock();

	time_t start2 = clock();
	delete stdrf;
	time_t end2 = clock();

	return m_log->benchmark(end-start, end2-start2);
}
bool	benchmark_map_assignement_operator() {
	ft::map<int, int> ftrf;
	std::map<int, int> stdrf;

	for (int i = 0; i < 100000; ++i) {
		ftrf.insert(ft::make_pair(i, i));
		stdrf.insert(std::make_pair(i, i));
	}

	time_t start = clock();
	ft::map<int, int> ftmap = ftrf;
	time_t end = clock();

	time_t start2 = clock();
	std::map<int, int> stdmaps = stdrf;
	time_t end2 = clock();

	return m_log->benchmark(end-start, end2-start2);
}
bool	benchmark_map_insert() {
	ft::map<int, int> ftrf;
	std::map<int, int> stdrf;

	time_t start = clock();
	for (int i = 0; i < 10000; ++i)
		ftrf.insert(ft::make_pair(i, i));
	time_t end = clock();

	time_t start2 = clock();
	for (int i = 0; i < 10000; ++i)
		stdrf.insert(std::make_pair(i, i));
	time_t end2 = clock();

	return m_log->benchmark(end-start, end2-start2);
}
bool	benchmark_map_insert_iterator() {
	ft::map<int, int> ftrf;
	std::map<int, int> stdrf;

	ft::map<int, int> ftnums;
	std::map<int, int> stdnums;

	for (int i = 0; i < 1000000; ++i) {
		ftrf.insert(ft::make_pair(i, i));
		stdrf.insert(std::make_pair(i, i));
	}

	time_t start = clock();
	ftrf.insert(ftnums.begin(), ftnums.end());
	time_t end = clock();

	time_t start2 = clock();
	stdrf.insert(stdnums.begin(), stdnums.end());
	time_t end2 = clock();

	return m_log->benchmark(end-start, end2-start2);
}
bool	benchmark_map_erase() {
	ft::map<int, int> ftrf;
	std::map<int, int> stdrf;

	for (int i = 0; i < 1000000; ++i) {
		ftrf.insert(ft::make_pair(i, i));
		stdrf.insert(std::make_pair(i, i));
	}

	time_t start = clock();
	for (int i = 0; i < 1000000; ++i)
		ftrf.erase(i);
	time_t end = clock();

	time_t start2 = clock();
	for (int i = 0; i < 1000000; ++i)
		stdrf.erase(i);
	time_t end2 = clock();

	return m_log->benchmark(end-start, end2-start2);
}
bool	benchmark_map_erase_iterator() {
	ft::map<int, int> ftrf;
	std::map<int, int> stdrf;

	for (int i = 0; i < 100000; ++i) {
		ftrf.insert(ft::make_pair(i, i));
		stdrf.insert(std::make_pair(i, i));
	}

	time_t start = clock();
	ftrf.erase(ftrf.begin(), ftrf.end());
	time_t end = clock();

	time_t start2 = clock();
	stdrf.erase(stdrf.begin(), stdrf.end());
	time_t end2 = clock();

	return m_log->benchmark(end-start, end2-start2);
}
bool	benchmark_map_find() {
	ft::map<int, int> ftrf;
	std::map<int, int> stdrf;

	for (int i = 0; i < 100000; ++i) {
		ftrf.insert(ft::make_pair(i, i));
		stdrf.insert(std::make_pair(i, i));
	}

	time_t start = clock();
	for (int i = 0; i < 100000; ++i) {
		if (ftrf.find(i)->first != i)
			return m_log->err("1: find failed");
	}
	time_t end = clock();

	time_t start2 = clock();
	for (int i = 0; i < 100000; ++i)
		if (stdrf.find(i)->first != i)
			return m_log->err("2: find failed");
	time_t end2 = clock();

	return m_log->benchmark(end-start, end2-start2);
}
bool	benchmark_map_count() {
	ft::map<int, int> ftrf;
	std::map<int, int> stdrf;

	for (int i = 0; i < 100000; ++i) {
		ftrf.insert(ft::make_pair(i, i));
		stdrf.insert(std::make_pair(i, i));
	}

	time_t start = clock();
	for (int i = 0; i < 100000; ++i) {
		if (ftrf.count(i) != 1)
			return m_log->err("1: count failed");
	}
	time_t end = clock();

	time_t start2 = clock();
	for (int i = 0; i < 100000; ++i) {
		if (stdrf.count(i) != 1)
			return m_log->err("2: count failed");
	}
	time_t end2 = clock();

	return m_log->benchmark(end-start, end2-start2);
}

void	map() {
	m_log = new ft_test::Logger("map ");

	m_log->section("CONSTRUCTORS");
	ft_test::run(m_log, test_map_default_constructor, "default constructor");
	ft_test::run(m_log, test_map_range_constructor, "range constructor");
	ft_test::run(m_log, test_map_copy_constructor, "copy constructor");

	m_log->section("DESTRUCTORS");
	ft_test::run(m_log, test_map_destructor, "destructor");

	m_log->section("ASSIGNEMENT OPERATOR");
	ft_test::run(m_log, test_map_assignement_operator, "operator=");

	m_log->section("ITERATORS");
	ft_test::run(m_log, test_map_begin, "begin");
	ft_test::run(m_log, test_map_end, "end");
	ft_test::run(m_log, test_map_rbegin, "rbegin");
	ft_test::run(m_log, test_map_rend, "rend");

	m_log->section("CAPACITY");
	ft_test::run(m_log, test_map_empty, "empty");
	ft_test::run(m_log, test_map_size, "size");
	ft_test::run(m_log, test_map_max_size, "max_size");

	m_log->section("ELEMENTS ACCESS");
	ft_test::run(m_log, test_map_operator_access, "operator[]");

	m_log->section("MODIFIERS");
	ft_test::run(m_log, test_map_insert, "insert");
	ft_test::run(m_log, test_map_erase, "erase");
	ft_test::run(m_log, test_map_swap, "swap");
	ft_test::run(m_log, test_map_clear, "clear");

	m_log->section("OBSERVERS");
	ft_test::run(m_log, test_map_key_comp, "key_comp");
	ft_test::run(m_log, test_map_value_comp, "value_comp");

	m_log->section("OPERATIONS");
	ft_test::run(m_log, test_map_find, "find");
	ft_test::run(m_log, test_map_count, "count");
	ft_test::run(m_log, test_map_lower_bound, "lower_bound");
	ft_test::run(m_log, test_map_upper_bound, "upper_bound");
	ft_test::run(m_log, test_map_equal_range, "equal_range");

	m_log->section("ALLOCATOR");
	ft_test::run(m_log, test_map_allocator, "allocator");

	m_log->section("BENCHMARK");
	ft_test::run(m_log, &benchmark_map_constructor, "Benchmark Constructor\t");
	ft_test::run(m_log, &benchmark_map_destructor, "Benchmark Destructor\t");
	ft_test::run(m_log, &benchmark_map_assignement_operator,
		"Benchmark Assignement Operator");
	ft_test::run(m_log, &benchmark_map_insert, "Benchmark Insert\t\t");
	ft_test::run(m_log, &benchmark_map_insert_iterator,
		"Benchmark Insert Iterator");
	ft_test::run(m_log, &benchmark_map_erase, "Benchmark Erase\t\t");
	ft_test::run(m_log, &benchmark_map_erase_iterator,
		"Benchmark Erase Iterator\t");
	ft_test::run(m_log, &benchmark_map_find, "Benchmark Find\t\t");
	ft_test::run(m_log, &benchmark_map_count, "Benchmark Count\t\t");
	delete m_log;
}

} // namespace ft_test
