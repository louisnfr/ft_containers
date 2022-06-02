#pragma once

namespace ft
{

enum color {
	RED,
	BLACK
};

template <typename T>
class node {
	public:
		T		key;

		node	*left;
		node	*right;
		node	*parent;

		color	color;

		explicit node(T const &val) : key()
};
} // namespace ft
