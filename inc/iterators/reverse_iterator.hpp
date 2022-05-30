#pragma once

/*
**	http://m.cplusplus.com/reference/iterator/reverse_iterator/
*/

#include "inc/iterators/iterator_traits.hpp"

namespace ft {
template <class It>
class reverse_iterator {
	public:
		typedef It	iterator_type;
		typedef typename ft::iterator_traits<It>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<It>::value_type value_type;
		typedef typename ft::iterator_traits<It>::difference_type difference_type;
		typedef typename ft::iterator_traits<It>::pointer pointer;
		typedef typename ft::iterator_traits<It>::reference reference;

	private:
		iterator_type	_ptr;

	public:
		// default constructor

		reverse_iterator(void) : _ptr(NULL) {}

		// initialization constructor

		explicit reverse_iterator(iterator_type it) : _ptr(it) {}

		// copy constructor

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) {
			_ptr = rev_it.base();
		}

		// destructor

		virtual ~reverse_iterator(void) {}

		// getter

		iterator_type	base(void) const {
			return _ptr;
		}

		// dereferenceable

		reference	operator*(void) const {
			return *_ptr;
		}

		pointer	operator->(void) const {
			return &(operator*());
		}

		// increment and decrement operators

		reverse_iterator	&operator++(void) {
			--_ptr;
			return *this;
		}

		reverse_iterator	operator++(int) {
			reverse_iterator tmp = *this;
			++(*this);
			return tmp;
		}

		reverse_iterator	&operator--(void) {
			_ptr--;
			return *this;
		}

		reverse_iterator	operator--(int) {
			reverse_iterator tmp = *this;
			_ptr--;
			return tmp;
		}

		// arithmetic operators

		reverse_iterator	operator+(difference_type n) const {
			return reverse_iterator(_ptr - n);
		}

		reverse_iterator	operator-(difference_type n) const {
			return reverse_iterator(_ptr + n);
		}

		reverse_iterator	&operator+=(difference_type n) {
			_ptr -= n;
			return *this;
		}

		reverse_iterator	&operator-=(difference_type n) {
			_ptr += n;
			return *this;
		}

		reference	operator[](difference_type n) const {
			return base()[-n-1];
		}
};
} // namespace ft
