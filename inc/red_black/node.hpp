#pragma once

namespace ft
{
typedef enum color {
	RED,
	BLACK
} e_color;

template <class T>
class node {
	public:
		typedef T	value_type;

		T		key;

		node	*parent;
		node	*left;
		node	*right;

		e_color	color;

		explicit node(T const &val) : key(val) {}
};
} // namespace ft
