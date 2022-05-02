/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:58:20 by lraffin           #+#    #+#             */
/*   Updated: 2022/05/02 23:35:51 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
// #include "map.hpp"

#include <vector>
#include <stack>
#include <map>

#if STD
 #define NS std
 #define test "STD"
#else
 #define NS ft
 #define test "FT"
#endif

int	main(void)
{
	NS::vector<int>	vect(5, 42);
	NS::vector<int>	copy(vect);

	vect[4] = 0;

	std::cout << copy[4] << std::endl;
	std::cout << vect[4] << std::endl;

	std::cout << test << std::endl;

	return (0);
}
