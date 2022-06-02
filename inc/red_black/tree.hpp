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

		typedef	node<T>				node_type;
		typedef const node<T>		const_node_type;

		typedef node<T>&			reference;
		typedef node<T>*			pointer;

		typedef const node<T>&		const_reference;
		typedef const node<T>*		const_pointer;

		typedef ft::tree_iterator<node_type>			iterator;
		typedef ft::tree_iterator<const_node_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t		size_type;

	private:
		allocator_type	_alloc;
		key_compare		_comp;
		pointer			_root;
		pointer			nil;
		size_type		_size;

	public:
		explicit tree(allocator_type alloc = allocator_type())
			: _alloc(alloc), _comp(key_compare()), _root(NULL), nil(NULL), _size(0) {
			__alloc_null_node();
		}

		ft::pair<iterator, bool> insert(const value_type &val) {
			return __insert_node(val);
		}

	private:
		void	__alloc_null_node(void) {
			nil = _alloc.allocate(1);

			nil->parent = NULL;
			nil->left = NULL;
			nil->right = NULL;
			nil->color = BLACK;

			_root = nil;
		}

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
			// first case scenario
			if (_root == nil)
				_root = node;
			return ft::make_pair(iterator(_root), true);
		}
};
} // namespace ft
