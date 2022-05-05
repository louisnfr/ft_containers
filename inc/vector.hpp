#ifndef INC_VECTOR_HPP_
#define INC_VECTOR_HPP_

#include <iostream>
#include <memory>

namespace ft {
template <class T, class Allocator = std::allocator<T> >
class vector {
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef size_t size_type;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::reference reference;

	private:
		allocator_type _alloc;
		pointer _data;
		size_type _size;
		size_type _capacity;

	public:
		// default
		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _data(NULL), _size(0), _capacity(0) {}
		// fill
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _data(NULL), _size(n), _capacity(n) {
			_data = _alloc.allocate(n);
			for (size_t i = 0; i < n; i++) _alloc.construct(_data + i, val);
		}
		// range
		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last,
		// 	const allocator_type &alloc = allocator_type())
		// {
		// 	while (first != last)
		// 	{
		// 		this
		// 	}
		// }
		// copy
		vector(const vector &src)
			: _alloc(src._alloc), _size(src._size), _capacity(src._capacity) {
			_capacity = src.capacity();
			_size = src.size();
			_alloc = src.get_allocator();
			_data = _alloc.allocate(src.capacity());
			for (size_type i = 0; i < src.size(); i++)
			_alloc.construct(_data + i, src.get_data()[i]);
		}
		// destructor
		virtual ~vector(void) {
			_alloc.deallocate(_data, size());
			_size = 0;
			_capacity = 0;
		}
		// operator overloads
		// vector	&operator=(const vector &rhs)
		// {

		// }
		reference operator[](size_type index) { return (this->_data[index]); }
		// accessors
		allocator_type get_allocator(void) const { return (this->_alloc); }
		pointer get_data(void) const { return (this->_data); }
		size_t size(void) const { return (this->_size); }
		size_t capacity(void) const { return (this->_capacity); }
};
}  // namespace ft

#endif  // INC_VECTOR_HPP_
