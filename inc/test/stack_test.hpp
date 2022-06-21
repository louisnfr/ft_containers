#pragma once

namespace test {
test::Logger *s_log;

bool	test_stack_constructor() {
	ft::vector<int> myvector(2, 200);

	ft::stack<int>	first;

	ft::stack<int, ft::vector<int> > third;
	ft::stack<int, ft::vector<int> > fourth(myvector);

	if (first.size() != 0 || !first.empty())
		return s_log->err("1: size failed");

	if (third.size() != 0 || !third.empty())
		return s_log->err("2: size failed");

	if (fourth.size() != 2 || fourth.empty())
		return s_log->err("3: size failed");

	return true;
}

bool	test_stack_copy_constructor() {
	ft::vector<int> myvector(2, 200);
	ft::stack<int> first(myvector);

	ft::stack<int, ft::vector<int> > third(first);

	if (first.size() != 2 || first.empty())
		return s_log->err("1: size failed");

	if (third.size() != 2 || third.empty())
		return s_log->err("2: size failed");

	if (first.top() != third.top())
		return s_log->err("3: top failed");
	return true;
}

bool	test_stack_assignment_operator() {
	ft::vector<int> myvector(2, 200);
	ft::stack<int> first(myvector);
	ft::stack<int> second = first;

	if (first.size() != 2 || first.empty())
		return s_log->err("1: size failed");

	if (second.size() != 2 || second.empty())
		return s_log->err("2: size failed");

	if (first.top() != second.top())
		return s_log->err("3: top failed");
	return true;
}

bool	test_stack_destructor() {
	ft::stack<int>	*first = new ft::stack<int>();

	delete first;
	return true;
}

bool	test_stack_empty() {
	ft::stack<int>	 first;

	if (!first.empty())
		return s_log->err("1: empty failed");

	first.push(1);

	if (first.empty())
		return s_log->err("2: empty failed");
	return true;
}

bool	test_stack_size() {
	ft::stack<int>	 first;

	if (first.size() != 0)
		return s_log->err("1: size failed");

	first.push(1);

	if (first.size() != 1)
		return s_log->err("2: size failed");

	first.push(2);

	if (first.size() != 2)
		return s_log->err("3: size failed");

	first.pop();

	if (first.size() != 1)
		return s_log->err("4: size failed");

	first.pop();

	if (first.size() != 0)
		return s_log->err("5: size failed");

	first.push(1);
	ft::stack<int>	 second(first);

	if (second.size() != 1)
		return s_log->err("6: size failed");

	ft::vector<int> myvector(42, 200);
	ft::stack<int>	 third(myvector);

	if (third.size() != 42)
		return s_log->err("7: size failed");
	return true;
}

bool	test_stack_top() {
	ft::stack<int>	 first;

	first.push(5);
	if (first.top() != 5)
		return s_log->err("1: top failed");

	first.push(1);
	if (first.top() != 1)
		return s_log->err("2: top failed");
	return true;
}

bool	test_stack_push() {
	ft::stack<int>	 first;

	first.push(1);

	if (first.top() != 1)
		return s_log->err("1: push failed");

	if (first.size() != 1)
		return s_log->err("2: push failed");

	first.push(2);

	if (first.top() != 2)
		return s_log->err("3: push failed");

	if (first.size() != 2)
		return s_log->err("4: push failed");
	return true;
}

bool	test_stack_pop() {
	ft::stack<int>	 first;

	first.push(1);
	first.push(2);

	if (first.top() != 2)
		return s_log->err("1: top failed");
	first.pop();
	if (first.top() != 1)
		return s_log->err("2: top failed");
	return true;
}

bool	test_stack_relationnal_operators() {
	ft::stack<int>	 first;
	ft::stack<int>	 second;

	if (first != second)
		return s_log->err("1: != failed");
	if (!(first == second))
		return s_log->err("2: == failed");

	first.push(1);
	if (second > first)
		return s_log->err("3: > failed");

	if (second >= first)
		return s_log->err("4: >= failed");

	if (first < second)
		return s_log->err("5: < failed");

	if (first <= second)
		return s_log->err("6: <= failed");
	return true;
}

bool	benchmark_stack_push() {
	ft::stack<int> mystack;
	time_t start = clock();
	for (int i = 0; i < 10000000; i++)
		mystack.push(i);
	time_t end = clock();

	std::stack<int> stdstack;
	time_t start2 = clock();
	for (int i = 0; i < 10000000; i++)
		stdstack.push(i);
	time_t end2 = clock();

	return s_log->benchmark(end - start, end2 - start2);
}

bool	benchmark_stack_pop() {
	ft::stack<int> mystack;
	for (int i = 0; i < 10000000; i++)
		mystack.push(i);
	time_t start = clock();
	for (int i = 0; i < 10000000; i++)
		mystack.pop();
	time_t end = clock();

	std::stack<int> stdstack;
	for (int i = 0; i < 10000000; i++)
		stdstack.push(i);
	time_t start2 = clock();
	for (int i = 0; i < 10000000; i++)
		stdstack.pop();
	time_t end2 = clock();

	return s_log->benchmark(end - start, end2 - start2);
}

void	stack() {
	s_log = new test::Logger("stack ");

	s_log->section("CONSTRUCTORS");
	test::run(s_log, &test_stack_constructor, "Constructor");
	test::run(s_log, &test_stack_copy_constructor, "Copy Constructor");
	test::run(s_log, &test_stack_assignment_operator, "Assignement Operator");

	s_log->section("DESTRUCTOR");
	test::run(s_log, &test_stack_destructor, "Destructor");

	s_log->section("METHODS");
	test::run(s_log, &test_stack_empty, "Empty");
	test::run(s_log, &test_stack_size, "Size");
	test::run(s_log, &test_stack_top, "Top");
	test::run(s_log, &test_stack_push, "Push");
	test::run(s_log, &test_stack_pop, "Pop");

	s_log->section("RELATIONAL OPERATORS");
	test::run(s_log, &test_stack_relationnal_operators,
		"Relationnal Operators");
	#ifdef BENCHMARK
	test::run(s_log, &benchmark_stack_push, "Benchmark Push");
	test::run(s_log, &benchmark_stack_pop, "Benchmark Pop");
	#endif
	delete s_log;
}
} // namespace test
