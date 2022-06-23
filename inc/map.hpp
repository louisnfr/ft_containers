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
	class Alloc = std::allocator<ft::pair<Key, T> >
> class map {
	public:
		typedef Key		key_type;
		typedef T		mapped_type;
		typedef Compare	key_compare;
		typedef Alloc	allocator_type;
		typedef ft::pair<key_type, mapped_type> value_type;

		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		class value_compare {
		public:
			bool operator()(const value_type &a, const value_type &b) const {
				return (key_compare()(a.first, b.first));
			}

			// value_compare &operator=(const value_compare &) {
			// 	return *this;
			// }
		};

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
		allocator_type			_alloc;
		key_compare				_key_compare;
		value_compare			_value_compare;
		tree<value_type, value_compare>	_tree;

	public:
		// empty constructor
		explicit map(const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type())
			: _alloc(alloc),
			_key_compare(comp),
			_value_compare(value_compare()),
			_tree(_alloc) {}

		// range constructor
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>
			::value>::type* = NULL)
			:_alloc(alloc),
			_key_compare(comp),
			_value_compare(value_compare()),
			_tree(_alloc) {
			insert(first, last);
		}

		// copy constructor
		map(const map &x)
		: _alloc(x._alloc),
		_key_compare(x._key_compare),
		_value_compare(x._value_compare),
		_tree(x._tree) {}

		// destructor
		~map(void) {}

		// assignement operator
		map	&operator=(const map &x) {
			_alloc = x._alloc;
			_key_compare = x._key_compare;
			_value_compare = x._value_compare;
			_tree = x._tree;
			return *this;
		}

		// iterators
		iterator begin(void) {
			return _tree.begin();
		}
		iterator end(void) {
			return _tree.end();
		}
		const_iterator begin(void) const {
			return _tree.begin();
		}
		const_iterator end(void) const {
			return _tree.end();
		}
		reverse_iterator rbegin(void) {
			return _tree.rbegin();
		}
		reverse_iterator rend(void) {
			return _tree.rend();
		}
		const_reverse_iterator rbegin(void) const {
			return _tree.rbegin();
		}
		const_reverse_iterator rend(void) const {
			return _tree.rend();
		}

		// capacity
		bool empty(void) const {
			return _tree.empty();
		}

		size_type size(void) const {
			return _tree.size();
		}

		size_type max_size(void) const {
			return _tree.max_size();
		}

		// element access
		mapped_type &operator[](const key_type &key) {
			iterator	ret = _tree.find(ft::make_pair(key, mapped_type()));

			if (ret != end())
				return ret._ptr->value.second;
			ft::pair<iterator, bool> tmp = insert(ft::make_pair(key, mapped_type()));
			return tmp.first._ptr->value.second;
		}

		// modifiers
		ft::pair<iterator, bool> insert(const value_type &val) {
			return _tree.insert(val);
		}

		iterator insert(iterator position, const value_type &val) {
			return _tree.insert(position, val);
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last,
					typename ft::enable_if<
					!ft::is_integral<InputIterator>
					::value>::type* = NULL) {
			_tree.insert(first, last);
		}

		void	print_tree(void) {
			_tree.print_tree(_tree.get_root());
		}

		void erase(iterator position) {
			_tree.erase(position);
		}

		size_type erase(const key_type &k) {
			return _tree.erase(ft::make_pair(k, mapped_type()));
		}

		void erase(iterator first, iterator last) {
			_tree.erase(first, last);
		}

		void swap(map &x) {
			std::swap(_alloc, x._alloc);
			std::swap(_key_compare, x._key_compare);
			std::swap(_value_compare, x._value_compare);
			_tree.swap(x._tree);
		}

		void clear(void) {
			_tree.clear();
		}

		// observers
		key_compare key_comp(void) const {
			return _key_compare;
		}

		value_compare value_comp(void) const {
			return _value_compare;
		}

		// operations
		iterator	find(const key_type &k) {
			return _tree.find(ft::make_pair(k, mapped_type()));
		}

		const_iterator	find(const key_type &k) const {
			return _tree.find(ft::make_pair(k, mapped_type()));
		}

		size_type count(const key_type &k) const {
			iterator	it = find(k);
			return (it == end() ? 0 : 1);
		}

		iterator	lower_bound(const key_type &k) {
			return _tree.lower_bound(ft::make_pair(k, mapped_type()));
		}
		const_iterator	lower_bound(const key_type &k) const {
			return _tree.lower_bound(ft::make_pair(k, mapped_type()));
		}

		iterator	upper_bound(const key_type &k) {
			return _tree.upper_bound(ft::make_pair(k, mapped_type()));
		}
		const_iterator	upper_bound(const key_type &k) const {
			return _tree.upper_bound(ft::make_pair(k, mapped_type()));
		}

		ft::pair<const_iterator, const_iterator>
		equal_range(const key_type &k) const {
			return _tree.equal_range(ft::make_pair(k, mapped_type()));
		}
		ft::pair<iterator, iterator>	equal_range(const key_type &k) {
			return _tree.equal_range(ft::make_pair(k, mapped_type()));
		}

		allocator_type	get_allocator(void) const {
			return _alloc;
		}
};

template<class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
	const ft::map<Key, T, Compare, Alloc> &rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template<class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
	const ft::map<Key, T, Compare, Alloc> &rhs) {
	return !(lhs == rhs);
}

template<class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
	const ft::map<Key, T, Compare, Alloc> &rhs) {
	return ft::lexicographical_compare(
		lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
	const ft::map<Key, T, Compare, Alloc> &rhs) {
	return !(rhs < lhs);
}

template<class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
	const ft::map<Key, T, Compare, Alloc> &rhs) {
	return rhs < lhs;
}

template<class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
	const ft::map<Key, T, Compare, Alloc> &rhs) {
	return !(lhs < rhs);
}
} // namespace ft
