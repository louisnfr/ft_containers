/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:58:20 by lraffin           #+#    #+#             */
/*   Updated: 2022/05/02 22:39:21 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"

#include <vector>
// #include <memory>

int	main(void)
{
	ft::vector<int>	vect(5, 42);
	ft::vector<int>	copy(vect);

	vect[4] = 0;

	std::cout << copy << std::endl;
	std::cout << vect;

	return (0);
}
