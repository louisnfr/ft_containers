#pragma once

/*
	https://www32.cplusplus.com/reference/type_traits/is_integral/
*/

namespace ft {
template <class T>
struct is_integral {
	static const bool value = false;
};

template<>
struct is_integral<bool> {
	static const bool value = true;
};

template<>
struct is_integral<char> {
	static const bool value = true;
};

template<>
struct is_integral<wchar_t> {
	static const bool value = true;
};

template<>
struct is_integral<signed char> {
	static const bool value = true;
};

template<>
struct is_integral<short int> {
	static const bool value = true;
};

template<>
struct is_integral<int> {
	static const bool value = true;
};

template<>
struct is_integral<long int> {
	static const bool value = true;
};

template<>
struct is_integral<long long int> {
	static const bool value = true;
};

template<>
struct is_integral<unsigned char> {
	static const bool value = true;
};

template<>
struct is_integral<unsigned short int> {
	static const bool value = true;
};

template<>
struct is_integral<unsigned int> {
	static const bool value = true;
};

template<>
struct is_integral<unsigned long int> {
	static const bool value = true;
};

template<>
struct is_integral<unsigned long long int> {
	static const bool value = true;
};


} // namespace ft
