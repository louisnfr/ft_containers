#pragma once

// #include "inc/utility/libs.hpp"

#include "inc/red_black/tree.hpp"

namespace ft {
template <class T>
class tree_iterator {
	public:
		typedef T	*node_ptr;
		typedef typename T::value_type	value_type;

		typedef value_type&		reference;
		typedef value_type*		pointer;
		typedef const value_type&	const_reference;
		typedef const value_type*	const_pointer;

		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t		difference_type;

		node_ptr	_ptr;
		node_ptr	_nil;

	private:
		node_ptr	_root;

	public:
		// default constructor
		tree_iterator(void) : _ptr(NULL), _nil(NULL), _root(NULL) {}

		// pointer constructor
		tree_iterator(node_ptr root, node_ptr ptr, node_ptr nil)
			: _ptr(ptr), _nil(nil), _root(root) {}

		// copy constructor
		tree_iterator(const tree_iterator &x) {
			_root = x._root;
			_ptr = x._ptr;
			_nil = x._nil;
		}

		// assignation operator
		tree_iterator &operator=(const tree_iterator &rhs) {
			if (this != &rhs) {
				_root = rhs._root;
				_ptr = rhs._ptr;
				_nil = rhs._nil;
			}
			return *this;
		}

		// destructor
		~tree_iterator(void) {}

		// const iterator cast
		operator tree_iterator<T const>(void) const {
			return tree_iterator<T const>(_root, _ptr, _nil);
		}

		// equality and inequality operators
		bool	operator==(const tree_iterator &rhs) const {
			return (_ptr == rhs._ptr);
		}

		bool	operator!=(const tree_iterator &rhs) const {
			return (_ptr != rhs._ptr);
		}

		// dereferenceable
		reference	operator*(void) {
			return _ptr->value;
		}

		const_reference	operator*(void) const {
			return _ptr->value;
		}

		pointer	operator->(void) {
			return &(operator*());
		}

		const_pointer	operator->(void) const {
			return &(operator*());
		}

		// increment and decrement operators
		tree_iterator&	operator++(void) {
			if (_ptr != _nil)
				_ptr = __next(_ptr);
			return *this;
		}

		tree_iterator	operator++(int) {
			tree_iterator tmp(*this);
			++(*this);
			return tmp;
		}

		tree_iterator&	operator--(void) {
			if (_ptr != _nil)
				_ptr = __prev(_ptr);
			else
				_ptr = __max_leaf(_root);
			return *this;
		}

		tree_iterator	operator--(int) {
			tree_iterator tmp(*this);
			--(*this);
			return tmp;
		}

	private:
		node_ptr	__prev(node_ptr node) const {
			if (node->left != _nil)
				return __max_leaf(node->left);

			while (node->parent != _nil && node == node->parent->left)
				node = node->parent;
			return node->parent;
		}

		node_ptr	__next(node_ptr node) const {
			if (node->right != _nil)
				return __min_leaf(node->right);

			while (node->parent != _nil && node == node->parent->right)
				node = node->parent;
			return node->parent;
		}

		node_ptr __max_leaf(node_ptr node) const {
			while (node->right != _nil)
				node = node->right;
			return node;
		}

		node_ptr	__min_leaf(node_ptr node) const {
			while (node->left != _nil)
				node = node->left;
			return node;
		}
};
} // namespace ft
