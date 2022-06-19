#pragma once

/*
 **	https://m.cplusplus.com/reference/set/set
 */

#include "inc/red_black/tree.hpp"

namespace ft {
template < class T,
	class Compare = std::less<T>,
	class Alloc = std::allocator<T>
> class set {
	public:
		typedef T	key_type;
		typedef T	value_type;

		typedef Compare	key_compare;
		typedef Compare	value_compare;
		typedef Alloc	allocator_type;

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef typename
			ft::tree<value_type, value_compare>::iterator iterator;
		typedef typename
			ft::tree<value_type, value_compare>::const_iterator const_iterator;
		typedef typename
			ft::tree<value_type, value_compare>::reverse_iterator reverse_iterator;
		typedef typename
			ft::tree<value_type, value_compare>::const_reverse_iterator
			const_reverse_iterator;

		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t		size_type;

	private:
		allocator_type	_alloc;
		key_compare		_key_compare;
		value_compare	_value_compare;
		ft::tree<value_type, value_compare>	_tree;

	public:
		explicit set(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		:	_alloc(alloc),
			_key_compare(comp),
			_value_compare(comp),
			_tree(_alloc) {}

		template <class InputIterator>
		set(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value,
			InputIterator>::type* = NULL)
		:	_alloc(alloc),
			_key_compare(comp),
			_value_compare(comp),
			_tree(_alloc) {
			insert(first, last);
		}

		set(const set &x)
		:	_alloc(x._alloc),
			_key_compare(x._key_compare),
			_value_compare(x._value_compare),
			_tree(x._tree) {}

		set &operator=(const set &x) {
			if (this != &x) {
				_alloc = x._alloc;
				_key_compare = x._key_compare;
				_value_compare = x._value_compare;
				_tree = x._tree;
			}
			return *this;
		}

		~set(void) {}

		// iterators
		iterator begin(void) { return _tree.begin(); }
		iterator end(void) { return _tree.end(); }
		const_iterator begin(void) const { return _tree.begin(); }
		const_iterator end(void) const { return _tree.end(); }
		reverse_iterator rbegin(void) { return _tree.rbegin(); }
		reverse_iterator rend(void) { return _tree.rend(); }
		const_reverse_iterator rbegin(void) const { return _tree.rbegin(); }
		const_reverse_iterator rend(void) const { return _tree.rend(); }

		bool empty(void) const { return _tree.empty(); }
		size_type size(void) const { return _tree.size(); }
		size_type max_size(void) const { return _tree.max_size(); }

		ft::pair<iterator, bool> insert(const value_type& val) {
			return _tree.insert(val);
		}

		iterator insert(iterator position, const value_type& val) {
			return _tree.insert(position, val);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last,
			typename ft::enable_if<
			!ft::is_integral<InputIterator>::value
			>::type * = NULL) {
			return _tree.insert(first, last);
		}

		void erase(iterator position) {
			return _tree.erase(position);
		}
		size_type erase(const key_type& k) {
			return _tree.erase(k);
		}
		void erase(iterator first, iterator last) {
			return _tree.erase(first, last);
		}

		void swap(set &x) {
			std::swap(_alloc, x._alloc);
			std::swap(_key_compare, x._key_compare);
			std::swap(_value_compare, x._value_compare);
			_tree.swap(x._tree);
		}

		void clear(void) {
			return _tree.clear();
		}


		key_compare key_comp(void) const {
			return _key_compare;
		}

		value_compare value_comp(void) const {
			return _value_compare;
		}

		iterator find(const value_type &val) {
			return _tree.find(val);
		}
		const_iterator find(const value_type &val) const {
			return _tree.find(val);
		}

		size_type count(const value_type& val) const {
			const_iterator it = find(val);

			return it == end() ? 0 : 1;
		}

		iterator lower_bound(const value_type& val) const {
			return _tree.lower_bound(val);
		}

		iterator upper_bound(const value_type& val) const {
			return _tree.upper_bound(val);
		}

		ft::pair<iterator, iterator> equal_range(const value_type& val) const {
			return _tree.equal_range(val);
		}

		allocator_type get_allocator(void) const {
			return _alloc;
		}
};
}//namespace ft
