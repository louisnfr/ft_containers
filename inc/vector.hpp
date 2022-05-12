#ifndef INC_VECTOR_HPP_
#define INC_VECTOR_HPP_

#include <iostream>
#include <memory>

namespace ft {
template <class T, class Allocator = std::allocator<T> >
class vector {
	public:
		typedef T				value_type;
		typedef Allocator		allocator_type;

		typedef std::size_t		size_type;
		typedef std::ptrdiff_t	difference_type;

		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::reference reference;

	private:
		allocator_type _alloc;

		pointer _data;

		size_type _size;
		size_type _capacity;

	public:
	// default constructor

		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _data(NULL), _size(0), _capacity(0) {}

	// fill constructor

		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _data(NULL), _size(n), _capacity(n) {
			_data = _alloc.allocate(n);
			for (size_t i = 0; i < n; i++) _alloc.construct(_data + i, val);
		}

	// range constructor

		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last,
			// const allocator_type& alloc = allocator_type()) {}

	// copy constructor

		vector(const vector &x)
			: _alloc(x._alloc), _size(x._size), _capacity(x._capacity) {
			_data = _alloc.allocate(x.capacity());
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, x._data[i]);
		}

	// destructor

		virtual ~vector(void) {
			_alloc.deallocate(_data, size());
			_size = 0;
			_capacity = 0;
		}

	// operator overload

		// vector	&operator=(const vector &x) {}

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

		size_type	size(void) const { return (this->_size); }
		// size_type	max_size() const {}
		// void		resize(size_type n, value_type val = value_type()) {}
		size_type	capacity(void) const { return (this->_capacity); }
		// bool		empty(void) const {}
		// void		reserve(size_type n) {}

	// element access

		reference operator[](size_type n) { return (this->_data[n]); }
		// const_reference operator[](size_type n) const {}

		// reference at(size_type n) {}
		// const_reference at (size_type n) const {}

		// reference front() {}
		// const_reference front() const {}

		// reference back() {}
		// const_reference back() const {}

	// modifiers

		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last) {}
		// void assign(size_type n, const value_type& val) {}

		// void push_back(const value_type& val) {}
		// void pop_back() {}

		// iterator insert(iterator position, const value_type& val) {}
		// void insert(iterator position, size_type n, const value_type& val) {}
		// template <class InputIterator>
		// void insert(iterator position, InputIterator first,
		// 	InputIterator last) {}

		// iterator erase(iterator position) {}
		// iterator erase(iterator first, iterator last) {}

		// void swap (vector& x) {}
		// void clear() {}

	// allocator

		allocator_type	get_allocator(void) const { return (this->_alloc); }

	// non-member function overloads

	// template <class T, class Alloc>
	// void swap (vector<T,Alloc> &x, vector<T,Alloc> &y) {}

	// template <class T, class Alloc>
	// bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	// template <class T, class Alloc>
	// bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	// template <class T, class Alloc>
	// bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	// template <class T, class Alloc>
	// bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	// template <class T, class Alloc>
	// bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}

	// template <class T, class Alloc>
	// bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {}
};
}  // namespace ft

#endif  // INC_VECTOR_HPP_
