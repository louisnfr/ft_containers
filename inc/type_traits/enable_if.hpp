#pragma once

/*
	https://en.cppreference.com/w/cpp/types/enable_if
*/

namespace ft {
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
} // namespace ft
