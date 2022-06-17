#pragma once

/*
**	https://www.cplusplus.com/reference/vector/vector/
*/

#include "inc/iterators/random_access_iterator.hpp"
#include "inc/iterators/reverse_iterator.hpp"
#include "inc/type_traits/enable_if.hpp"
#include "inc/type_traits/is_integral.hpp"
#include "inc/algorithm/equal.hpp"
#include "inc/algorithm/lexicographical_compare.hpp"

namespace ft {
template <class T, class Allocator = std::allocator<T> >
class vector {
	public:
		typedef T			value_type;
		typedef Allocator	allocator_type;

		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef ft::random_access_iterator<T>			iterator;
		typedef ft::random_access_iterator<const T>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t		size_type;

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

		template <class InputIterator>
		vector(
			InputIterator first,
			InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<
				InputIterator>::value>::type* = NULL)
			: _alloc(alloc), _data(NULL), _size(0), _capacity(0) {
			size_type n = last - first;
			reserve(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, *(first + i));
			_size = n;
		}

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
		}

	// operator overload

		vector	&operator=(const vector &x) {
			clear();
			if (_capacity < x._size)
				reserve(x._capacity);
			_size = x._size;
			for (size_t i = 0; i < x._size; i++)
				_alloc.construct(_data + i, x._data[i]);
			return *this;
		}

	// iterators

		iterator begin(void) {
			return iterator(_data);
		}

		const_iterator begin(void) const {
			return const_iterator(_data);
		}

		iterator end(void) {
			return iterator(_data + _size);
		}

		const_iterator end(void) const {
			return const_iterator(_data + _size);
		}

		reverse_iterator rbegin(void) {
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin(void) const {
			return const_reverse_iterator(end());
		}

		reverse_iterator rend(void) {
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend(void) const {
			return const_reverse_iterator(begin());
		}

	// capacity

		size_type	size(void) const {
			return this->_size;
		}

		size_type	max_size(void) const {
			return _alloc.max_size();
		}

		void	resize(size_type n, value_type val = value_type()) {
			if (n < _size) {
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(_data + i);
			} else if (n > _size) {
				reserve(n);
				for (size_type i = _size; i < n; i++)
					_alloc.construct(_data + i, val);
			}
			_size = n;
		}

		size_type	capacity(void) const {
			return this->_capacity;
		}

		bool	empty(void) const {
			return (_size == 0);
		}

		void	reserve(size_type n) {
			if (n > max_size())
				throw std::length_error("vector::reserve");
			if (n > _capacity) {
				pointer tmp = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++) {
					_alloc.construct(tmp + i, _data[i]);
					_alloc.destroy(_data + i);
				}
				_alloc.deallocate(_data, _capacity);
				_data = tmp;
				_capacity = n;
			}
		}

	// element access

		reference operator[](size_type n) {
			return _data[n];
		}

		const_reference operator[](size_type n) const {
			return _data[n];
		}

		reference at(size_type n) {
			__range_check(n);
			return _data[n];
		}
		const_reference at(size_type n) const {
			__range_check(n);
			return _data[n];
		}

		reference front() {
			return _data[0];
		}

		const_reference front() const {
			return _data[0];
		}

		reference back() {
			return _data[_size - 1];
		}

		const_reference back() const {
			return _data[_size - 1];
		}

	// modifiers

		template <class InputIterator>
		void assign(InputIterator first,
					InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value,
					InputIterator>::type* = NULL) {
			size_type n = last - first;

			reserve(n);
			for (size_type i = 0; i < n; i++, first++) {
				_alloc.destroy(_data + i);
				_alloc.construct(_data + i, *first);
			}
			_size = n;
		}

		void assign(size_type n, const value_type& val) {
			reserve(n);
			for (size_type i = 0; i < n; i++) {
				_alloc.destroy(_data + i);
				_alloc.construct(_data + i, val);
			}
			_size = n;
		}

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

		iterator insert(iterator position, const value_type &val) {
			size_type pos = position - begin();

			reserve(++_size);
			__shift_right(pos, 1);
			_alloc.construct(_data + pos, val);
			return iterator(_data);
		}

		void insert(iterator position, size_type n, const value_type &val) {
			size_type pos = position - begin();

			reserve(_size + n);
			__shift_right(pos, n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + pos + i, val);
			_size += n;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value,
					InputIterator>::type* = NULL) {
			size_type pos = position - begin();
			size_type n = last - first;

			reserve(_size + n);
			__shift_right(pos, n);
			for (size_type i = 0; i < n; i++, first++)
				_alloc.construct(_data + pos + i, *first);
			_size += n;
		}

		iterator erase(iterator position) {
			size_type pos = position - begin();

			_alloc.destroy(_data + pos);
			__shift_left(pos, 1);
			_size--;
			return iterator(_data + pos);
		}

		iterator erase(iterator first, iterator last) {
			size_type diff = last - first;
			size_type n = first - begin();
			size_type i = last - begin();

			while (*first != *last) {
				_alloc.destroy(&(*first));
				++first;
			}
			__shift_left(n, i - n);
			_size -= diff;
			return iterator(_data + n);
		}

		void swap(vector& x) {
			std::swap(_data, x._data);
			std::swap(_size, x._size);
			std::swap(_capacity, x._capacity);
			std::swap(_alloc, x._alloc);
		}

		void clear() {
			if (_data) {
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
			}
			_size = 0;
		}

	// allocator

		allocator_type	get_allocator(void) const {
			return this->_alloc;
		}

	private:
		void	__range_check(size_type n) {
			std::ostringstream c_n;
			std::ostringstream c_size;

			c_n << n;
			c_size << _size;
			if (n >= _size)
				throw std::out_of_range(
					std::string("vector::_M_range_check: __n ") + \
					std::string("(which is ") + c_n.str() + \
					std::string(") >= this->size() (which is ") + \
					c_size.str() + std::string(")"));
		}

		void	__shift_right(size_type pos, size_type n) {
			for (size_type i = _size - 1; i >= pos; i--) {
				_alloc.construct(_data + i + n, _data[i]);
				_alloc.destroy(_data + i);
				if (i == 0)
					break;
			}
		}

		void	__shift_left(size_type pos, size_type n) {
			for (; pos < _size; pos++) {
				_alloc.construct(_data + pos, _data[pos + n]);
				_alloc.destroy(_data + pos);
			}
		}
};
	// non-member function overloads

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return ft::lexicographical_compare(
				lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return !(lhs < rhs);
	}

} // namespace ft
