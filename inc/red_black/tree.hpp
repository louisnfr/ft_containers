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
		pointer			_nil;

		size_type		_size;

	public:
};
} // namespace ft
