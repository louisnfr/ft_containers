/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:04:21 by lraffin           #+#    #+#             */
/*   Updated: 2022/05/01 03:30:26 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <iostream>

# include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		typedef T									value_type;
		typedef Allocator							allocator_type;
		typedef size_t								size_type;
		typedef typename allocator_type::pointer	pointer;

		private:
			allocator_type	_alloc;
			pointer			_array;
			size_type		_size;
			size_type		_capacity;

		public:
			// default
			explicit vector(const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _array(NULL), _size(0), _capacity(0) {}
			// fill
			explicit vector (size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _array(NULL), _size(n), _capacity(n)
			{
				_array = _alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
				{
					_alloc.construct(_array + i, val);
				}
			}
			// range
			// copy
			// destructor
			virtual ~vector(void)
			{
				_alloc.deallocate(_array, size());
				_size = 0;
				_capacity = 0;
			}
			allocator_type	get_allocator(void) const { return(this->_allocator); }
			pointer		get_data(void) const { return(this->_array); }
			size_t		size(void) const { return(this->_size); }
			size_t		capacity(void) const { return(this->_capacity); }
	};

}

template<typename T>
std::ostream	&operator<<(std::ostream &o, ft::vector<T> &rhs)
{
	for (size_t i = 0; i < rhs.size(); i++)
		std::cout << rhs.get_data()[i] << std::endl;
	return (o);
}

#endif
