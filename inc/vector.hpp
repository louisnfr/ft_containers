#pragma once

#include <iostream>
#include <memory>
#include <limits>

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
		typedef typename allocator_type::const_reference const_reference;

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

		explicit vector(
			size_type n,
			const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _data(NULL), _size(n), _capacity(n) {
			_data = _alloc.allocate(n);
			for (size_t i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
		}

	// range constructor

		// template <class InputIterator>
		// vector(
		// 	InputIterator first,
		// 	InputIterator last,
		// 	const allocator_type& alloc = allocator_type()
		// ) {
		// 	std::cout << "debug" << std::endl;
		// }

	// copy constructor

		vector(const vector &x)
			: _alloc(x._alloc)
			, _size(x._size)
			, _capacity(x._capacity) {
			_data = _alloc.allocate(x.capacity());
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, x._data[i]);
		}

	// destructor

		virtual ~vector(void) {
			_alloc.deallocate(_data, size());
		}

	// operator overload

		vector	&operator=(const vector &x) {
			clear();
			if (_capacity < x._size)
				reserve(x._capacity);
			_size = x._size;
			for (size_t i = 0; i < x._size; i++)
				_alloc.construct(_data + i, x._data[i]);
			return (*this);
		}

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

		size_type	max_size() const { return (_alloc.max_size()); }

		// void	resize(size_type n, value_type val = value_type()) {

		// }

		size_type	capacity(void) const { return (this->_capacity); }

		bool	empty(void) const {
			return (_size == 0);
		}

		void	reserve(size_type n) {
			if (n > max_size())
				throw std::length_error("vector::reserve");
			pointer tmp = _alloc.allocate(n);
			for (size_t i = 0; i < _size; i++) {
				_alloc.construct(tmp + i, _data[i]);
				_alloc.destroy(_data + i);
			}
			_alloc.deallocate(_data, _capacity);
			_data = tmp;
			_capacity = n;
		}

	// element access

		reference operator[](size_type n) { return (_data[n]); }
		const_reference operator[](size_type n) const { return (_data[n]); }

		reference at(size_type n) {
			if (n >= _size)
				throw std::out_of_range("vector::_M_range_check: __n " + \
				"(which is " + n + ") >= this->size() (which is " + _size + ")");
			return (_data[n]);
		}
		const_reference at (size_type n) const { return (_data[n]); }

		// reference front() {}
		// const_reference front() const {}

		// reference back() {}
		// const_reference back() const {}

	// modifiers

		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last) {}
		// void assign(size_type n, const value_type& val) {}

		void push_back(const value_type& val) {
			size_type new_cap;

			if (_size == 0)
				new_cap = 1;
			else
				new_cap = _size * 2;
			if (_size == _capacity)
				reserve(new_cap);
			_alloc.construct(_data + _size++, val);
		}

		void pop_back() {
			_alloc.destroy(_data + _size--);
		}

		// iterator insert(iterator position, const value_type& val) {}
		// void insert(iterator position, size_type n, const value_type& val) {}
		// template <class InputIterator>
		// void insert(iterator position, InputIterator first,
		// 	InputIterator last) {}

		// iterator erase(iterator position) {}
		// iterator erase(iterator first, iterator last) {}

		// void swap (vector& x) {}
		void clear() {
			if (_data)
			{
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
			}
			_size = 0;
		}

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
