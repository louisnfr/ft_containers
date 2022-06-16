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
		pointer			_nil;
		size_type		_size;

	public:
		// default constructor
		explicit tree(allocator_type alloc = allocator_type())
			: _alloc(alloc), _comp(key_compare()), _root(NULL), _nil(NULL), _size(0) {
			__alloc_null_node();
		}

		// copy constructor
		tree(const tree &x)
		:	_alloc(x._alloc), _root(NULL), _nil(NULL), _size(0) {
			__alloc_null_node();
			__copy_tree(x._root, x._nil);
		}

		// assignation operator
		tree	&operator=(const tree &rhs) {
			if (this != &rhs) {
				clear();
				__destroy_null_node();
				_alloc = rhs._alloc;
				__alloc_null_node();
				__copy_tree(rhs._root, rhs._nil);
			}
			return *this;
		}

		// destructor
		~tree(void) {
				clear();
				__destroy_null_node();
		}

		// getter
		pointer	get_root(void) {
			return _root;
		}

		// iterators
		iterator	begin(void) {
			return iterator(_root, __min_node(_root), _nil);
		}
		iterator	end(void) {
			return iterator(_root, _nil, _nil);
		}
		const_iterator	begin(void) const {
			return const_iterator(_root, __min_node(_root), _nil);
		}
		const_iterator	end(void) const {
			return const_iterator(_root, _nil, _nil);
		}
		reverse_iterator	rbegin(void) {
			return reverse_iterator(end());
		}
		reverse_iterator	rend(void) {
			return reverse_iterator(begin());
		}
		const_reverse_iterator	rbegin(void) const {
			return const_reverse_iterator(end());
		}
		const_reverse_iterator	rend(void) const {
			return const_reverse_iterator(begin());
		}

		// capacity
		bool	empty(void) const {
			return (_size == 0);
		}

		size_type	size(void) const {
			return _size;
		}

		size_type	max_size(void) const {
			return _alloc.max_size();
		}

		// insert (1)
		ft::pair<iterator, bool> insert(const value_type &val) {
			return __insert_node(val);
		}

		// insert (2)
		iterator insert(iterator pos, const value_type &val) {
			(void)pos;
			return insert(val).first;
		}

		// insert (3)
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last,
					typename ft::enable_if<
						!ft::is_integral<InputIterator>::value
					>::type * = NULL) {
			for (; first != last; ++first)
				__insert_node(*first);
		}



		void	clear(void) {
			__destroy_nodes(_root);
			_root = _nil;
			_size = 0;
		}


	private:
		void	__alloc_null_node(void) {
			_nil = _alloc.allocate(1);

			_nil->parent = NULL;
			_nil->left = NULL;
			_nil->right = NULL;
			_nil->color = BLACK;

			_root = _nil;
		}

		void	__destroy_null_node(void) {
			if (_nil == NULL)
				return;
			_alloc.destroy(_nil);
			_alloc.deallocate(_nil, 1);
			_nil = NULL;
		}

		pointer __alloc_node(const value_type &val) {
			pointer node = _alloc.allocate(1);

			node->value = val;
			node->color = RED;
			node->left = _nil;
			node->right = _nil;
			node->parent = _nil;
			++_size;
			return node;
		}

		void	__destroy_node(pointer node) {
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			--_size;
		}

		void	__destroy_nodes(pointer node) {
			if (node == NULL || node == _nil)
				return;
			__destroy_nodes(node->left);
			__destroy_nodes(node->right);
			__destroy_node(node);
		}

		ft::pair<iterator, bool> __insert_node(const value_type &val) {
			// create a node from pair value
			pointer node = __alloc_node(val);

			pointer x = _root;
			pointer p = _nil;

			// navigate the tree to find the parent
			while (x != _nil) {
				p = x;
				if (_comp(val, x->value))
					x = x->left;
				else
					x = x->right;
			}
			node->parent = p;

			if (p == _nil) // first insert
				_root = node;
			else if (_comp(node->value, p->value)) // greater than parent
				p->left = node;
			else // less than parent
				p->right = node;

			if (node->parent == _nil) {
				node->color = BLACK;
				return ft::make_pair(iterator(_root, node, _nil), true);
			}

			if (node->parent->parent == _nil)
				return ft::make_pair(iterator(_root, node, _nil), true);

			__balance_tree(node);

			return ft::make_pair(iterator(_root, node, _nil), true);
		}

		void	__balance_tree(pointer node) {
			pointer u;

			while (node->parent->color == RED) {
				if (node->parent == node->parent->parent->right) {
					u = node->parent->parent->left;
					if (u->color == RED) {
						u->color = BLACK;
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->left) {
							node = node->parent;
							__rotate_right(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						__rotate_left(node->parent->parent);
					}
				} else {
					u = node->parent->parent->right;
					if (u->color == RED) {
						u->color = BLACK;
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->right) {
							node = node->parent;
							__rotate_left(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						__rotate_right(node->parent->parent);
					}
				}
				if (node == _root)
					break;
			}
			_root->color = BLACK;
		}

		void	__rotate_left(pointer node) {
			pointer tmp = node->right;

			node->right = tmp->left;
			if (tmp->left != _nil)
				tmp->left->parent = node;

			tmp->parent = node->parent;
			if (node->parent == _nil)
				_root = tmp;
			else if (node == node->parent->left)
				node->parent->left = tmp;
			else
				node->parent->right = tmp;
			tmp->left = node;
			node->parent = tmp;
		}

		void	__rotate_right(pointer node) {
			pointer tmp = node->left;

			node->left = tmp->right;
			if (tmp->right != _nil)
				tmp->right->parent = node;

			tmp->parent = node->parent;
			if (node->parent == _nil)
				_root = tmp;
			else if (node == node->parent->right)
				node->parent->right = tmp;
			else
				node->parent->left = tmp;
			tmp->right = node;
			node->parent = tmp;
		}

		pointer	__min_node(pointer node) const {
			while (node->left != _nil)
				node = node->left;
			return node;
		}

		void	__copy_tree(pointer node, pointer null) {
			if (node == _nil || node == null)
				return;
			__copy_tree(node->left, null);
			__insert_node(node->value);
			__copy_tree(node->right, null);
		}

		#include "inc/red_black/visualizer.hpp"
};
} // namespace ft
