/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:58:20 by lraffin           #+#    #+#             */
/*   Updated: 2022/05/05 17:41:01 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if STD
 #define NS std
 #define NSd "std"
 #include <iostream>
 #include <vector>
 #include <stack>
 #include <map>
#else
 #define NS ft
 #define NSd "ft"
 #include "vector.hpp"
 #include "stack.hpp"
//  #include "map.hpp"
#endif

int	main(void)
{
	// std::cout << NSd << std::endl;
	NS::vector<int>	vect(5, 42);
	NS::vector<int>	copy(vect);

	vect[4] = 0;

	std::cout << copy[4] << std::endl;
	std::cout << vect[4] << std::endl;

	return (0);
}
