#pragma once

namespace ft_test {
ft_test::Logger *st_log;

bool	test_set_constructor() {
	ft::set<int> first;
	if (first.size() != 0 || !first.empty())
		return st_log->err("1: size failed");

	int myints[]= {10, 20, 30, 40, 50};
	ft::set<int> second(myints, myints+5);        // range
	if (second.size() != 5 || second.empty())
		return st_log->err("2: size failed");

	ft::set<int> third(second);                  // a copy of second
	if (third.size() != 5 || third.empty())
		return st_log->err("3: size failed");

	ft::set<int> fourth(second.begin(), second.end());
	if (fourth.size() != 5 || fourth.empty())
		return st_log->err("4: size failed");

	ft::set<int, classcomp> fifth;
	if (fifth.size() != 0 || !fifth.empty())
		return st_log->err("5: size failed");

	bool(*fn_pt)(int, int) = fncomp;
	ft::set<int, bool(*)(int, int)> sixth(fn_pt);
	if (sixth.size() != 0 || !sixth.empty())
		return st_log->err("6: size failed");
	return true;
}

bool	test_set_copy_constructor() {
	int myints[] = {10, 20, 30, 40, 50};
	ft::set<int> first(myints, myints+5);
	ft::set<int> second(first);

	if (first.size() != 5 || first.empty())
		return st_log->err("1: size failed");

	if (second.size() != 5 || second.empty())
		return st_log->err("2: size failed");

	ft::set<int>::iterator it = first.begin();
	for (; it != first.end(); ++it) {
		if (second.find(*it) == second.end())
			return st_log->err("3: find failed");
	}

	int myints2[]= {65, 12, 1, 42, 120, 10, 20, 30, 40, 50};
	ft::set<int> third(myints2, myints2+10);
	ft::set<int> fourth(third);

	if (third.size() != 10 || third.empty())
		return st_log->err("4: size failed");

	if (fourth.size() != 10 || fourth.empty())
		return st_log->err("5: size failed");

	ft::set<int>::iterator it2 = third.begin();
	for (; it2 != third.end(); ++it2) {
		if (fourth.find(*it2) == fourth.end())
			return st_log->err("6: find failed");
	}
	return true;
}

bool	test_set_assignement_operator() {
	int myints[]= {12, 82, 37, 64, 15};
	ft::set<int> first(myints, myints+5);		// set with 5 ints
	ft::set<int> second;						// empty set

	second = first;								// now second contains the 5 ints
	if (second.size() != 5 || second.empty())
		return st_log->err("1: size failed");

	first = ft::set<int>();					// and first is empty
	if (first.size() != 0 || !first.empty())
		return st_log->err("2: size failed");

	first = second; 							// now first contains the 5 ints
	ft::set<int>::iterator it = second.begin();
	for (; it != second.end(); ++it) {
		if (first.find(*it) == first.end())
			return st_log->err("3: find failed");
	}
	return true;
}

bool	test_set_destructor() {
	ft::set<int>	*first = new ft::set<int>();

	first->insert(10);
	first->insert(20);
	first->insert(30);
	delete first;

	ft::set<int>	second;
	second.insert(10);
	second.insert(20);
	second.insert(30);

	return true;
}

bool	test_set_begin() {
	int myints[] = {75, 23, 65, 42, 13};
	ft::set<int> myset(myints, myints+5);
	std::set<int> stdset(myints, myints+5);

	ft::set<int>::iterator it = myset.begin();
	std::set<int>::iterator it2 = stdset.begin();
	for (; it != myset.end(); ++it, ++it2) {
		if (*it != *it2)
			return st_log->err("1: begin failed");
	}
	return true;
}
bool	test_set_end() {
	int myints[] = {75, 23, 65, 42, 13};
	ft::set<int> myset(myints, myints+5);
	std::set<int> stdset(myints, myints+5);

	ft::set<int>::iterator it = myset.end();
	std::set<int>::iterator it2 = stdset.end();

	--it;
	--it2;
	for (; it != myset.begin(); --it, --it2) {
		if (*it != *it2)
			return st_log->err("1: end failed");
	}
	return true;
}
bool	test_set_rbegin() {
	int myints[] = {75, 23, 65, 42, 13};
	ft::set<int> myset(myints, myints+5);
	std::set<int> stdset(myints, myints+5);

	ft::set<int>::reverse_iterator it = myset.rbegin();
	std::set<int>::reverse_iterator it2 = stdset.rbegin();
	for (; it != myset.rend(); ++it, ++it2) {
		if (*it != *it2)
			return st_log->err("1: rbegin failed");
	}
	return true;
}
bool	test_set_rend() {
	int myints[] = {75, 23, 65, 42, 13};
	ft::set<int> myset(myints, myints+5);
	std::set<int> stdset(myints, myints+5);

	ft::set<int>::reverse_iterator it = myset.rend();
	std::set<int>::reverse_iterator it2 = stdset.rend();
	--it;
	--it2;
	for (; it != myset.rbegin(); --it, --it2) {
		if (*it != *it2)
			return st_log->err("1: rend failed");
	}
	return true;
}

bool	test_set_empty() {
	ft::set<int> first;

	if (!first.empty())
		return st_log->err("1: empty failed");

	first.insert(10);

	if (first.empty())
		return st_log->err("2: empty failed");

	first.erase(10);

	if (!first.empty())
		return st_log->err("3: empty failed");

	first.insert(20);
	first.insert(30);
	first.insert(40);

	if (first.empty())
		return st_log->err("4: empty failed");

	while (!first.empty())
		first.erase(first.begin());

	if (!first.empty())
		return st_log->err("5: empty failed");

	return true;
}
bool	test_set_size() {
	ft::set<int> first;

	if (first.size() != 0)
		return st_log->err("1: size failed");

	first.insert(10);
	if (first.size() != 1)
		return st_log->err("2: size failed");

	first.insert(20);
	if (first.size() != 2)
		return st_log->err("3: size failed");

	for (int i = 0; i < 10; ++i)
		first.insert(i);

	if (first.size() != 12)
		return st_log->err("4: size failed");

	first.erase(first.begin());
	if (first.size() != 11)
		return st_log->err("5: size failed");

	while (!first.empty())
		first.erase(first.begin());

	if (first.size() != 0)
		return st_log->err("6: size failed");
	return true;
}
bool	test_max_size() {
	// ft::set<int> myset;
	// std::set<int> theirset;

	// std::cout << myset.max_size() << std::endl;
	// std::cout << theirset.max_size() << std::endl;
	// if (myset.max_size() != theirset.max_size())
	// 	return st_log->err("1: max_size failed");
	// https://discord.com/channels/774300457157918772/785407584608714802/913052503736737832

	return true;
}

bool	test_set_insert() {
	ft::set<int> myset;
	ft::set<int>::iterator it;
	ft::pair<ft::set<int>::iterator, bool> ret;

	for (int i = 0; i < 5; i++)
		myset.insert(i * 10);

	ret = myset.insert(20);  // no new element inserted
	if (ret.second != false)
		return st_log->err("1: insert failed");

	if (ret.second == false)
		it = ret.first;

	myset.insert(it, 25);
	myset.insert(it, 24);
	myset.insert(it, 26);

	int myints[] = { 75, 23, 65, 42, 13 };
	myset.insert(myints, myints + 5);

	int intsrefs[] = { 0, 10, 13, 20, 23, 24, 25, 26, 30, 40, 42, 65, 75 };
	it = myset.begin();
	for (int i = 0; it != myset.end(); ++it, i++) {
		if (*it != intsrefs[i])
			return st_log->err("2: insert failed");
	}
	return true;
}
bool	test_set_erase() {
	ft::set<int> myset;
	ft::set<int>::iterator it;

	for (int i = 0; i < 10; i++)
		myset.insert(i * 10);

	it = myset.begin();  // point to 10
	++it;

	myset.erase(it);

	myset.erase(40);

	it = myset.find(60);
	myset.erase(it, myset.end());

	if (myset.size() != 4)
		return st_log->err("1: erase failed");

	it = myset.begin();
	if (*it++ != 0)
		return st_log->err("2: erase failed");
	if (*it++ != 20)
		return st_log->err("3: erase failed");
	if (*it++ != 30)
		return st_log->err("4: erase failed");
	if (*it++ != 50)
		return st_log->err("5: erase failed");
	if (it++ != myset.end())
		return st_log->err("6: erase failed");
	return true;
}
bool	test_set_swap() {
	int myints[] = { 12, 75, 10, 32, 20, 25 };

	ft::set<int> first(myints, myints + 3);       // { 10, 12, 75 }
	ft::set<int> second(myints + 3, myints + 6);  // { 20, 25, 32 }

	first.swap(second);

	if (first.size() != 3)
		return st_log->err("1: swap failed");

	if (second.size() != 3)
		return st_log->err("2: swap failed");

	ft::set<int>::iterator it = first.begin();
	if (*it++ != 20)
		return st_log->err("3: swap failed");
	if (*it++ != 25)
		return st_log->err("4: swap failed");
	if (*it++ != 32)
		return st_log->err("5: swap failed");

	it = second.begin();
	if (*it++ != 10)
		return st_log->err("6: swap failed");
	if (*it++ != 12)
		return st_log->err("7: swap failed");
	if (*it++ != 75)
		return st_log->err("8: swap failed");
	return true;
}
bool	test_set_clear() {
	ft::set<int> myset;

	myset.insert(100);
	myset.insert(200);
	myset.insert(300);

	if (myset.size() != 3)
		return st_log->err("1: clear failed");

	myset.clear();
	if (myset.size() != 0 || !myset.empty())
		return st_log->err("2: clear failed");

	myset.insert(1101);
	myset.insert(2202);

	if (myset.size() != 2 || myset.empty())
		return st_log->err("3: clear failed");

	myset.clear();
	return true;
}

bool	test_set_key_comp() {
	ft::set<int> myset;

	int highest;

	ft::set<int>::key_compare mycomp = myset.key_comp();
	for (int i = 0; i < 10; ++i)
		myset.insert(i);

	highest = *myset.rbegin();
	ft::set<int>::iterator it = myset.begin();

	for (; it != myset.end(); ++it) {
		if (*it == highest) {
			if (mycomp(*it, highest) != 0)
				return st_log->err("1: key_comp failed");
		} else {
			if (mycomp(*it, highest) != 1)
				return st_log->err("2: key_comp failed");
		}
	}
	return true;
}
bool	test_set_value_comp() {
	ft::set<int> myset;

	int highest;

	ft::set<int>::value_compare mycomp = myset.value_comp();
	for (int i = 0; i < 10; ++i)
		myset.insert(i);

	highest = *myset.rbegin();
	ft::set<int>::iterator it = myset.begin();

	for (; it != myset.end(); ++it) {
		if (*it == highest) {
			if (mycomp(*it, highest) != 0)
				return st_log->err("1: key_comp failed");
		} else {
			if (mycomp(*it, highest) != 1)
				return st_log->err("2: key_comp failed");
		}
	}
	return true;
}

bool	test_set_find() {
	ft::set<int> myset;
	ft::set<int>::iterator it;

	for (int i = 0; i < 10; ++i)
		myset.insert(i);

	if (myset.size() != 10)
		return st_log->err("1: size failed");

	it = myset.find(5);
	if (*it != 5)
		return st_log->err("1: find failed");

	myset.erase(it);
	myset.erase(myset.find(8));

	if (myset.size() != 8)
		return st_log->err("2: find failed");

	it = myset.find(5);
	if (it != myset.end())
		return st_log->err("3: find failed");

	it = myset.find(8);
	if (it != myset.end())
		return st_log->err("4: find failed");

	it = myset.find(1);
	if (*it != 1)
		return st_log->err("5: find failed");
	return true;
}
bool	test_set_count() {
	ft::set<int> myset;

	for (int i = 0; i < 5; ++i)
		myset.insert(i * 3);

	for (int i = 0; i < 10; ++i) {
		if (myset.count(i) != (i % 3 == 0 ? 1 : 0))
			return st_log->err("1: count failed");
	}

	return true;
}
bool	test_set_lower_bound() {
	ft::set<int> myset;
	ft::set<int>::iterator itlow, itup;

	for (int i = 0; i < 10; ++i)
		myset.insert(i * 10);

	itlow = myset.lower_bound(30);
	if (*itlow != 30)
		return st_log->err("1: lower_bound failed");
	itup = myset.upper_bound(60);
	if (*itup != 70)
		return st_log->err("2: lower_bound failed");

	myset.erase(itlow, itup);

	if (myset.size() != 6)
		return st_log->err("3: lower_bound failed");
	ft::set<int>::iterator it = myset.begin();
	int myints[] = { 0, 10, 20, 70, 80, 90};
	for (int i = 0; it != myset.end(); ++it, i++) {
		if (*it != myints[i])
			return st_log->err("4: lower_bound failed");
	}

	itlow = myset.lower_bound(300);
	if (itlow != myset.end())
		return st_log->err("5: lower_bound failed");
	return true;
}
bool	test_set_upper_bound() {
	ft::set<int> myset;
	ft::set<int>::iterator it;

	for (int i = 0; i < 10; ++i)
		myset.insert(i * 10);

	it = myset.upper_bound(40);
	if (*it != 50)
		return st_log->err("1: upper_bound failed");

	it = myset.upper_bound(60);
	if (*it != 70)
		return st_log->err("2: upper_bound failed");

	myset.erase(it);

	it = myset.upper_bound(60);
	if (*it != 80)
		return st_log->err("3: upper_bound failed");

	it = myset.upper_bound(70);
	if (*it != 80)
		return st_log->err("4: upper_bound failed");

	it = myset.upper_bound(800);
	if (it != myset.end())
		return st_log->err("5: upper_bound failed");
	return true;
}
bool	test_set_equal_range() {
	ft::set<int> myset;
	ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ret;

	for (int i = 0; i < 10; ++i)
		myset.insert(i * 10);

	ret = myset.equal_range(40);
	if (*ret.first != 40)
		return st_log->err("1: equal_range failed");
	if (*ret.second != 50)
		return st_log->err("2: equal_range failed");

	ret = myset.equal_range(600);
	if (ret.first != myset.end())
		return st_log->err("3: equal_range failed");
	if (ret.second != myset.end())
		return st_log->err("4: equal_range failed");

	if (ret.first != ret.second)
		return st_log->err("5: equal_range failed");
	return true;
}

bool	test_set_allocator() {
	ft::set<int> myset;
	int * p;
	int i;

	// allocate an array of 5 elements using myset's allocator:
	p = myset.get_allocator().allocate(5);

	// assign some values to array
	for (i = 0; i < 5; i++)
		p[i] = (i + 1) * 10;

	for (i = 0; i < 5; i++)
		if (p[i] != (i + 1) * 10)
			return st_log->err("1: allocator failed");

	myset.get_allocator().deallocate(p, 5);
	return true;
}

bool	benchmark_set_constructor() {
	ft::set<int> ftrf;
	std::set<int> stdrf;

	for (int i = 0; i < 10000; ++i) {
		ftrf.insert(i);
		stdrf.insert(i);
	}

	time_t start = clock();
	ft::set<int> *ftset = new ft::set<int>(ftrf.begin(), ftrf.end());
	time_t end = clock();

	time_t start2 = clock();
	std::set<int> *stdsets = new std::set<int>(stdrf.begin(), stdrf.end());
	time_t end2 = clock();

	delete ftset;
	delete stdsets;

	return st_log->benchmark(end-start, end2-start2);
}
bool	benchmark_set_destructor() {
	ft::set<int> *ftrf = new ft::set<int>();
	std::set<int> *stdrf = new std::set<int>();

	for (int i = 0; i < 50000; ++i) {
		ftrf->insert(i);
		stdrf->insert(i);
	}

	time_t start = clock();
	delete ftrf;
	time_t end = clock();

	time_t start2 = clock();
	delete stdrf;
	time_t end2 = clock();

	return st_log->benchmark(end-start, end2-start2);
}
bool	benchmark_set_assignement_operator() {
	ft::set<int> ftrf;
	std::set<int> stdrf;

	for (int i = 0; i < 10000; ++i) {
		ftrf.insert(i);
		stdrf.insert(i);
	}

	time_t start = clock();
	ft::set<int> ftset = ftrf;
	time_t end = clock();

	time_t start2 = clock();
	std::set<int> stdsets = stdrf;
	time_t end2 = clock();

	return st_log->benchmark(end-start, end2-start2);
}
bool	benchmark_set_insert() {
	ft::set<int> ftrf;
	std::set<int> stdrf;

	time_t start = clock();
	for (int i = 0; i < 10000; ++i)
		ftrf.insert(i);
	time_t end = clock();

	time_t start2 = clock();
	for (int i = 0; i < 10000; ++i)
		stdrf.insert(i);
	time_t end2 = clock();

	return st_log->benchmark(end-start, end2-start2);
}
bool	benchmark_set_insert_iterator() {
	ft::set<int> ftrf;
	std::set<int> stdrf;

	ft::set<int> ftnums;
	std::set<int> stdnums;

	for (int i = 0; i < 10000; ++i) {
		ftnums.insert(i);
		stdnums.insert(i);
	}

	time_t start = clock();
	ftrf.insert(ftnums.begin(), ftnums.end());
	time_t end = clock();

	time_t start2 = clock();
	stdrf.insert(stdnums.begin(), stdnums.end());
	time_t end2 = clock();

	return st_log->benchmark(end-start, end2-start2);
}
bool	benchmark_set_erase() {
	ft::set<int> ftrf;
	std::set<int> stdrf;

	for (int i = 0; i < 100000; ++i) {
		ftrf.insert(i);
		stdrf.insert(i);
	}

	time_t start = clock();
	for (int i = 0; i < 100000; ++i)
		ftrf.erase(i);
	time_t end = clock();

	time_t start2 = clock();
	for (int i = 0; i < 100000; ++i)
		stdrf.erase(i);
	time_t end2 = clock();

	return st_log->benchmark(end-start, end2-start2);
}
bool	benchmark_set_erase_iterator() {
	ft::set<int> ftrf;
	std::set<int> stdrf;

	for (int i = 0; i < 100000; ++i) {
		ftrf.insert(i);
		stdrf.insert(i);
	}

	time_t start = clock();
	ftrf.erase(ftrf.begin(), ftrf.end());
	time_t end = clock();

	time_t start2 = clock();
	stdrf.erase(stdrf.begin(), stdrf.end());
	time_t end2 = clock();

	return st_log->benchmark(end-start, end2-start2);
}
bool	benchmark_set_find() {
	ft::set<int> ftrf;
	std::set<int> stdrf;

	for (int i = 0; i < 100000; ++i) {
		ftrf.insert(i);
		stdrf.insert(i);
	}

	time_t start = clock();
	for (int i = 0; i < 100000; ++i) {
		if (*ftrf.find(i) != i)
			return st_log->err("1: find failed");
	}
	time_t end = clock();

	time_t start2 = clock();
	for (int i = 0; i < 100000; ++i)
		if (*stdrf.find(i) != i)
			return st_log->err("2: find failed");
	time_t end2 = clock();

	return st_log->benchmark(end-start, end2-start2);
}
bool	benchmark_set_count() {
	ft::set<int> ftrf;
	std::set<int> stdrf;

	for (int i = 0; i < 100000; ++i) {
		ftrf.insert(i);
		stdrf.insert(i);
	}

	time_t start = clock();
	for (int i = 0; i < 100000; ++i) {
		if (ftrf.count(i) != 1)
			return st_log->err("1: count failed");
	}
	time_t end = clock();

	time_t start2 = clock();
	for (int i = 0; i < 100000; ++i) {
		if (stdrf.count(i) != 1)
			return st_log->err("2: count failed");
	}
	time_t end2 = clock();

	return st_log->benchmark(end-start, end2-start2);
}

void	set() {
	st_log = new ft_test::Logger("set ");

	st_log->section("CONSTRUCTORS");
	ft_test::run(st_log, test_set_constructor, "constructor");
	ft_test::run(st_log, test_set_copy_constructor, "copy constructor");
	ft_test::run(st_log, test_set_assignement_operator, "assignment operator");

	st_log->section("DESTRUCTOR");
	ft_test::run(st_log, test_set_destructor, "destructor");

	st_log->section("ITERATORS");
	ft_test::run(st_log, test_set_begin, "begin");
	ft_test::run(st_log, test_set_end, "end");
	ft_test::run(st_log, test_set_rbegin, "rbegin");
	ft_test::run(st_log, test_set_rend, "rend");

	st_log->section("CAPACITY");
	ft_test::run(st_log, test_set_empty, "empty");
	ft_test::run(st_log, test_set_size, "size");
	ft_test::run(st_log, test_max_size, "max_size");

	st_log->section("MODIFIERS");
	ft_test::run(st_log, test_set_insert, "insert");
	ft_test::run(st_log, test_set_erase, "erase");
	ft_test::run(st_log, test_set_swap, "swap");
	ft_test::run(st_log, test_set_clear, "clear");

	st_log->section("OBSERVERS");
	ft_test::run(st_log, test_set_key_comp, "key_comp");
	ft_test::run(st_log, test_set_value_comp, "value_comp");

	st_log->section("OPERATIONS");
	ft_test::run(st_log, test_set_find, "find");
	ft_test::run(st_log, test_set_count, "count");
	ft_test::run(st_log, test_set_lower_bound, "lower_bound");
	ft_test::run(st_log, test_set_upper_bound, "upper_bound");
	ft_test::run(st_log, test_set_equal_range, "equal_range");

	st_log->section("ALLOCATORS");
	ft_test::run(st_log, test_set_allocator, "allocator");

	#ifdef BENCHMARK
	st_log->section("BENCHMARK");
	ft_test::run(st_log, &benchmark_set_constructor, "Benchmark Constructor\t");
	ft_test::run(st_log, &benchmark_set_destructor, "Benchmark Destructor\t");
	ft_test::run(st_log, &benchmark_set_assignement_operator,
		"Benchmark Assignement Operator");
	ft_test::run(st_log, &benchmark_set_insert, "Benchmark Insert\t\t");
	ft_test::run(st_log, &benchmark_set_insert_iterator,
		"Benchmark Insert Iterator");
	ft_test::run(st_log, &benchmark_set_erase, "Benchmark Erase\t\t");
	ft_test::run(st_log, &benchmark_set_erase_iterator,
		"Benchmark Erase Iterator\t");
	ft_test::run(st_log, &benchmark_set_find, "Benchmark Find\t\t");
	ft_test::run(st_log, &benchmark_set_count, "Benchmark Count\t\t");
	#endif
	delete st_log;
}
} // namespace ft_test
