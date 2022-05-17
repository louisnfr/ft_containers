#pragma once

/*
**	https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
*/

namespace ft {
template <class T>
class random_access_iterator {
	public:
		typedef std::random_access_iterator_tag		iterator_category;
		typedef T					value_type;
		typedef std:: ptrdiff_t		difference_type;
		typedef T*					pointer;
		typedef T&					reference;

	private:
		pointer	_ptr;

	public:
		// default constructible

		random_access_iterator(void) : _ptr(NULL) {}

		random_access_iterator(pointer ptr) : _ptr(ptr) {}

		// copy constructible

		random_access_iterator(const random_access_iterator &x) : _ptr(x._ptr) {}

		// copy assignable

		random_access_iterator &operator=(const random_access_iterator &x) {
			_ptr = x._ptr;
			return (*this);
		}

		// destructible

		~random_access_iterator(void) {}

		// equality operator

		bool	operator==(const random_access_iterator &rhs) const {
			return (_ptr == rhs._ptr);
		}

		// inequality operator

		bool	operator!=(const random_access_iterator &rhs) const {
			return (_ptr != rhs._ptr);
		}

		// inequality relationable iterators

		bool	operator<(const random_access_iterator &rhs) const {
			return (_ptr < rhs._ptr);
		}

		bool	operator>(const random_access_iterator &rhs) const {
			return (_ptr > rhs._ptr);
		}

		bool	operator<=(const random_access_iterator &rhs) const {
			return (_ptr <= rhs._ptr);
		}

		bool	operator>=(const random_access_iterator &rhs) const {
			return (_ptr >= rhs._ptr);
		}

		// dereferenceable

		reference	operator*(void) const {
			return (*_ptr);
		}

		pointer	operator->(void) const {
			return (_ptr);
		}

		// can be incremented

		random_access_iterator	&operator++(void) {
			return (++_ptr);
		}

		random_access_iterator	operator++(int) {
			random_access_iterator	tmp(*this);
			_ptr++;
			return (tmp);
		}

		// can be decremented

		random_access_iterator	&operator--(void) {
			return (--_ptr);
		}

		random_access_iterator	operator--(int) {
			random_access_iterator	tmp(_ptr);
			_ptr--;
			return (tmp);
		}

};
} // namespace ft
