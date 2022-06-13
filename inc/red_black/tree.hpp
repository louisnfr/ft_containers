#pragma once

#include "inc/utility/libs.hpp"

#include "inc/red_black/node.hpp"
#include "inc/red_black/iterator.hpp"

namespace ft {
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
		pointer			NIL;
		size_type		_size;

	public:
		explicit tree(allocator_type alloc = allocator_type())
			: _alloc(alloc), _comp(key_compare()), _root(NULL), NIL(NULL), _size(0) {
			__alloc_null_node();
		}

		ft::pair<iterator, bool> insert(const value_type &val) {
			return __insert_node(val);
		}

		pointer	getNode(void) { return _root; }

	private:
		void	__alloc_null_node(void) {
			NIL = _alloc.allocate(1);

			NIL->parent = NULL;
			NIL->left = NULL;
			NIL->right = NULL;
			NIL->color = BLACK;

			_root = NIL;
		}

		pointer __alloc_node(const value_type &val) {
			pointer node = _alloc.allocate(1);

			node->key = val;
			node->color = RED;
			node->left = NIL;
			node->right = NIL;
			node->parent = NIL;
			++_size;
			return node;
		}

		ft::pair<iterator, bool> __insert_node(const value_type &val) {
			// create a node from pair value
			pointer node = __alloc_node(val);

			// looking for the place to insert the node
			pointer x = _root;
			pointer p = NIL;
			while (x != NIL) {
				p = x;
				if (_comp(val, x->key))
					x = x->left;
				else
					x = x->right;
			}

			node->parent = p;

			if (p == NIL) // first case scenario
				_root = node;
			else if (_comp(node->key, p->key))
				p->left = node;
			else
				p->right = node;

			if (node->parent == NIL) {
				node->color = BLACK;
				return ft::make_pair(iterator(_root), true);
			}

			if (node->parent->parent == NIL)
			{
				return ft::make_pair(iterator(_root), true);
			}

			// __insert_fixup(node);

			return ft::make_pair(iterator(_root), true);
		}

	public:
		#include "inc/red_black/visualizer.hpp"
};
} // namespace ft
