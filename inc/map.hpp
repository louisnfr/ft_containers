#pragma once

/*
**	https://m.cplusplus.com/reference/map/map
*/

#include "inc/utility/pair.hpp"

#include "inc/type_traits/enable_if.hpp"
#include "inc/type_traits/is_integral.hpp"

#include "inc/red_black/tree.hpp"

namespace ft {
template <class Key,
	class T,
	class Compare = std::less<Key>,
	class Alloc = std::allocator<ft::pair<const Key, T> >
> class map {
	public:
		typedef Key		key_type;
		typedef T		mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare	key_compare;
		typedef Alloc	allocator_type;

		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef ft::tree_iterator<T>			iterator;
		typedef ft::tree_iterator<const T>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t		size_type;

		class value_compare {
			protected:
				key_compare comp;
				explicit value_compare(Compare c) : comp(c) {}
			public:
				bool operator()(const value_type &x, const value_type &y) const {
					return comp(x.first, y.first);
				}
		};

	private:
		allocator_type	_alloc;
		key_compare		_key_compare;
		pointer			_root;
		size_type		_size;

	public:
		// empty constructor

		explicit map(const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _key_compare(comp), _root(NULL), _size(0) {}

		// range constructor

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value,
			InputIterator>::type* = NULL)
			: _alloc(alloc), _key_compare(comp), _root(NULL), _size(0) {
			insert(first, last);
		}

		// copy constructor

		map(const map &x)
		: _alloc(x._alloc), _key_compare(x._key_compare), _root(NULL), _size(0) {}

		// destructor

		virtual ~map(void) {
			// clear();
		}

		// map &operator=(const map &x) {
		// 	clear();
		// 	insert(x.begin(), x.end());
		// }

		// iterators

		// iterator begin() {}
		// const_iterator begin() const {}
		// iterator end() {}
		// const_iterator end() const {}
		// reverse_iterator rbegin() {}
		// const_reverse_iterator rbegin() const {}
		// reverse_iterator rend() {}
		// const_reverse_iterator rend() const {}

		// capacity

		// bool empty() const {}
		// size_type size() const {}
		// size_type max_size() const {}

		// element access

		T	&operator[](const key_type &x) {
			return (*((insert(make_pair(x, T()))).first)).second;
		}

		// modifiers

		// ft::pair<iterator, bool> insert(const value_type &x) {
		// 	std::cout << "debug" << std::endl;
		// 	(void)x;
		// 	return ;
		// }

		// iterator insert(iterator position, const value_type &x) {}

		// template <class InputIterator>
		// void insert(InputIterator first, InputIterator last) {}

		// void erase(iterator position) {}
		// size_type erase(const key_type &x) {}
		// void erase(iterator first, iterator last) {}
		// void swap(map<Key,T,Compare,Allocator>&) {}
		// void clear() {}

		// observers

		// key_compare key_comp() const {}
		// value_compare value_comp() const {}

		// operations

		// iterator find(const key_type &x) {}
		// const_iterator find(const key_type &x) const {}
		// size_type count(const key_type &x) const {}
		// iterator lower_bound(const key_type &x) {}
		// const_iterator lower_bound(const key_type &x) const {}
		// iterator upper_bound(const key_type &x) {}
		// const_iterator upper_bound(const key_type &x) const {}
		// ft::pair<iterator, iterator>
		// equal_range(const key_type &x) {}
		// ft::pair<const_iterator, const_iterator>
		// equal_range(const key_type &x) const {}
};

// template <class Key, class T, class Compare, class Allocator>
// bool operator==(const map<Key,T,Compare,Allocator>& x,
// 	const map<Key,T,Compare,Allocator>& y) {

// }

// template <class Key, class T, class Compare, class Allocator>
// bool operator< (const map<Key,T,Compare,Allocator>& x,
// 	const map<Key,T,Compare,Allocator>& y) {

// }

// template <class Key, class T, class Compare, class Allocator>
// bool operator!=(const map<Key,T,Compare,Allocator>& x,
// 	const map<Key,T,Compare,Allocator>& y) {

// }

// template <class Key, class T, class Compare, class Allocator>
// bool operator> (const map<Key,T,Compare,Allocator>& x,
// 	const map<Key,T,Compare,Allocator>& y) {

// }

// template <class Key, class T, class Compare, class Allocator>
// bool operator>=(const map<Key,T,Compare,Allocator>& x,
// 	const map<Key,T,Compare,Allocator>& y) {

// }

// template <class Key, class T, class Compare, class Allocator>
// bool operator<=(const map<Key,T,Compare,Allocator>& x,
// 	const map<Key,T,Compare,Allocator>& y) {

// }

// template <class Key, class T, class Compare, class Allocator>
// void swap(map<Key, T, Compare, Allocator> &x,
// 	map<Key, T, Compare, Allocator> &y) {

// }
} // namespace ft
