/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:58:20 by lraffin           #+#    #+#             */
/*   Updated: 2022/05/01 03:23:21 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"

// #include <vector>
// #include <memory>

int	main(void)
{
	ft::vector<int>	vect(5, 12);

	std::cout << vect;

	return (0);
}
