/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:04:21 by lraffin           #+#    #+#             */
/*   Updated: 2022/04/29 02:43:35 by lraffin          ###   ########.fr       */
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

		public:
			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _array(NULL) {}
			~vector(void) {}
		private:
			allocator_type	_alloc;
			pointer			_array;
	};
}

#endif
