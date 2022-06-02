#pragma once

#include "inc/utility/libs.hpp"

#include "inc/red_black/node.hpp"
#include "inc/red_black/iterator.hpp"

namespace ft
{
template <class T,
	class Compare,
	class Alloc = std::allocator<node<T> >
> class tree {
	public:
		typedef T		value_type;
		typedef Compare	key_compare;
		typedef Alloc	allocator_type;

		typedef node<T>&			reference;
		typedef node<T>*			pointer;
		typedef const node<T>&		const_reference;
		typedef const node<T>*		const_pointer;

		typedef ft::tree_iterator<T>			iterator;
		typedef ft::tree_iterator<const T>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t		size_type;

	private:
		allocator_type	_alloc;
		key_compare		_comp;
		pointer			_root;
		size_type		_size;

	public:
		explicit tree(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _comp(key_compare()), _root(NULL), _size(0) {}

		ft::pair<iterator, bool> insert(const value_type &val) {
			return __insert_node(val);
		}

	private:
		pointer __alloc_node(const value_type &val) {
			pointer node = _alloc.allocate(1);

			node->key = val;
			node->color = RED;
			node->left = NULL;
			node->right = NULL;
			node->parent = NULL;
			++_size;
			return node;
		}

		ft::pair<iterator, bool> __insert_node(const value_type &val) {
			pointer node = __alloc_node(val);
			if (!_root)
				_root = node;
			return ft::make_pair(iterator(_root), true);
		}
};
} // namespace ft
