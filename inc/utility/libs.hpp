#pragma once

#if STD
 #define NS std
#else
 #define NS ft
#endif

#include <iostream> // standard library
#include <sstream> // use to convert int to string

// stl containers
#include <vector>
#include <stack>
#include <map>
#include <set>

// ft containers
#include "inc/vector.hpp"
#include "inc/stack.hpp"
#include "inc/map.hpp"
#include "inc/set.hpp"

// tests
#include "inc/test/logger.hpp"
#include "inc/test/run_test.hpp"
#include "inc/test/vector_test.hpp"
#include "inc/test/stack_test.hpp"
#include "inc/test/map_test.hpp"
#include "inc/test/set_test.hpp"

// vector
void	iterator_comparison(void);
void	reallocation(void);
void	vector_swap(void);

// stack

// map
void	pair_test(void);
void	unique_keys(void);

// set
