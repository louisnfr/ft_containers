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

		typedef typename ft::tree<value_type, value_compare>::iterator iterator;
		typedef typename ft::tree
			<value_type, value_compare>::const_iterator const_iterator;
		typedef typename ft::tree
			<value_type, value_compare>::reverse_iterator reverse_iterator;
		typedef typename ft::tree
			<value_type, value_compare>::const_reverse_iterator const_reverse_iterator;

		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t		size_type;

	private:
		allocator_type	_alloc;
		key_compare		_key_compare;
		value_compare	_value_compare;
		ft::tree<value_type, value_compare>	_tree;
};
}//namespace ft
