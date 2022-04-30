/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 02:08:08 by lraffin           #+#    #+#             */
/*   Updated: 2022/04/30 03:19:23 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		protected:
			container_type	under_ctr;

		public:
			explicit stack (const container_type &c = container_type()) : under_ctr(c) {}

	};
}

#endif
