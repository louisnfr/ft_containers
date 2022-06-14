#pragma once

#include "inc/utility/libs.hpp"

#include "inc/red_black/tree.hpp"

namespace ft {
template <class T>
class tree_iterator {
	public:
		typedef T	*node_pointer;
		typedef typename T::value_type	value_type;

		typedef value_type&		reference;
		typedef value_type*		pointer;
		// typedef const value_type&	const_reference;
		// typedef const value_type*	const_pointer;

		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef std::ptrdiff_t		difference_type;

	private:
		node_pointer	_ptr;

	public:
		// default constructor
		tree_iterator(void) : _ptr(NULL) {}

		// pointer constructor
		explicit tree_iterator(node_pointer ptr) : _ptr(ptr) {}

		// copy constructor
		tree_iterator(const tree_iterator &x) : _ptr(x._ptr) {}

		// copy assignable
		tree_iterator &operator=(const tree_iterator &x) {
			_ptr = x._ptr;
			return *this;
		}

		// destructor
		virtual ~tree_iterator(void) {}

		// const iterator cast
		operator tree_iterator<T const>(void) const {
			return tree_iterator<T const>(_ptr);
		}

		// equality and inequality operators
		// bool	operator==(const tree_iterator &rhs) const {
		// 	return (_ptr == rhs._ptr);
		// }

		// bool	operator!=(const tree_iterator &rhs) const {
		// 	return (_ptr != rhs._ptr);
		// }

		// dereferenceable
		reference	operator*(void) const {
			return _ptr->value;
		}

		pointer	operator->(void) const {
			return &(operator*());
		}

		// increment and decrement operators
		// tree_iterator	&operator++(void) {
		// 	++_ptr;
		// 	return *this;
		// }

		// tree_iterator	operator++(int) {
		// 	tree_iterator	tmp = *this;
		// 	++_ptr;
		// 	return tmp;
		// }

		// tree_iterator	&operator--(void) {
		// 	--_ptr;
		// 	return *this;
		// }

		// tree_iterator	operator--(int) {
		// 	tree_iterator	tmp = *this;
		// 	--_ptr;
		// 	return tmp;
		// }

		// arithmetic operators
		// tree_iterator	operator+(const difference_type &n) const {
		// 	return tree_iterator(_ptr + n);
		// }

		// difference_type	operator+(const tree_iterator &rhs) const {
		// 	return (_ptr + rhs._ptr);
		// }

		// tree_iterator	operator-(const difference_type &n) const {
		// 	return tree_iterator(_ptr - n);
		// }

		// difference_type	operator-(const tree_iterator &rhs) const {
		// 	return (_ptr - rhs._ptr);
		// }

		// relational operators
		// bool	operator<(const tree_iterator &rhs) const {
		// 	return (_ptr < rhs._ptr);
		// }

		// bool	operator>(const tree_iterator &rhs) const {
		// 	return (_ptr > rhs._ptr);
		// }

		// bool	operator<=(const tree_iterator &rhs) const {
		// 	return (_ptr <= rhs._ptr);
		// }

		// bool	operator>=(const tree_iterator &rhs) const {
		// 	return (_ptr >= rhs._ptr);
		// }

		// assignement operators
		// tree_iterator	&operator+=(const difference_type &n) const {
		// 	_ptr += n;
		// 	return *this;
		// }

		// tree_iterator	&operator-=(const difference_type &n) const {
		// 	_ptr -= n;
		// 	return *this;
		// }
};
} // namespace ft
