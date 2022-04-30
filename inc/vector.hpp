/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:04:21 by lraffin           #+#    #+#             */
/*   Updated: 2022/04/30 03:46:52 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <iostream>

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
				// things to be done
			}
			virtual ~vector(void) {}
	};
}

#endif
