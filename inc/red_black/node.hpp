#pragma once

namespace ft
{
typedef enum color {
	RED,
	BLACK
} e_color;

template <typename T>
class node {
	public:
		T		key;

		node	*left;
		node	*right;
		node	*parent;

		e_color	color;

		explicit node(T const &val) : key(val) {}

		virtual ~node(void) {}
};
} // namespace ft
