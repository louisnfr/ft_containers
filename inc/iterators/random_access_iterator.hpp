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
		typedef std::ptrdiff_t		difference_type;
		typedef T*					pointer;
		typedef T&					reference;

	private:
		pointer	_ptr;

	public:
		// default constructor
		random_access_iterator(void) : _ptr(NULL) {}

		// copy constructor
		explicit random_access_iterator(pointer ptr) : _ptr(ptr) {}

		// operator
		random_access_iterator(const random_access_iterator &x) : _ptr(x._ptr) {}

		// copy assignable
		random_access_iterator &operator=(const random_access_iterator &x) {
			_ptr = x._ptr;
			return *this;
		}

		// destructor
		virtual ~random_access_iterator(void) {}

		// getter
		pointer	getPtr(void) {
			return _ptr;
		}

		// const iterator cast
		operator random_access_iterator<T const>(void) const {
			return random_access_iterator<T const>(_ptr);
		}

		// equality and inequality operators
		bool	operator==(const random_access_iterator &rhs) const {
			return (_ptr == rhs._ptr);
		}

		bool	operator!=(const random_access_iterator &rhs) const {
			return (_ptr != rhs._ptr);
		}

		// dereferenceable
		reference	operator*(void) const {
			return *_ptr;
		}

		pointer	operator->(void) const {
			return _ptr;
		}

		// increment and decrement operators
		random_access_iterator	&operator++(void) {
			++_ptr;
			return *this;
		}

		random_access_iterator	operator++(int) {
			random_access_iterator	tmp = *this;
			++_ptr;
			return tmp;
		}

		random_access_iterator	&operator--(void) {
			--_ptr;
			return *this;
		}

		random_access_iterator	operator--(int) {
			random_access_iterator	tmp = *this;
			--_ptr;
			return tmp;
		}

		// arithmetic operators
		random_access_iterator	operator+(const difference_type &n) const {
			return random_access_iterator(_ptr + n);
		}

		difference_type	operator+(const random_access_iterator &rhs) const {
			return (_ptr + rhs._ptr);
		}

		random_access_iterator	operator-(const difference_type &n) const {
			return random_access_iterator(_ptr - n);
		}

		difference_type	operator-(const random_access_iterator &rhs) const {
			return (_ptr - rhs._ptr);
		}

		// relational operators
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

		// assignement operators
		random_access_iterator	&operator+=(const difference_type &n) const {
			_ptr += n;
			return *this;
		}

		random_access_iterator	&operator-=(const difference_type &n) const {
			_ptr -= n;
			return *this;
		}

		// offset dereference operator
		value_type	&operator[](size_t n) const {
			return *(_ptr + n);
		}
};
} // namespace ft
