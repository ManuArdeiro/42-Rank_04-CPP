/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:52:59 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/12 13:08:18 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void print_vertices_message(void)
{
    std::cout << "  jolopez-		BSP \n"<< std::endl;
	std::cout << "I need the 3 vertices of the triangle." << std::endl;
    std::cout << "For that, you will need to input 6" << std::endl;
    std::cout << "numbers between -1000 and 1000. Each" << std::endl;
    std::cout << "time you type one, press ENTER." << std::endl;
}

static void print_point_message(void)
{
    std::cout << "Very good!! Now enter the 2 coordinates" << std::endl;
    std::cout << "(between -1000 and 1000) of the point" << std::endl;
    std::cout << "you want to check if it's inside the" << std::endl;
    std::cout << "triangle or not." << std::endl;
}

int main(void)
{
	Point a, b, c, p;

	print_vertices_message();
	if (read_vertices(a, b, c))
		return (EXIT_FAILURE);
	print_point_message();
	if (read_point(p))
		return (EXIT_FAILURE);
	if (bsp(a, b, c, p) == true)
		std::cout << std::endl << "\033[32mThe point is INSIDE the triangle!!\033[0m" << std::endl;
	else
		std::cout << std::endl << "\033[31mThe point is OUTSIDE the triangle!!\033[0m" << std::endl;
	std::cout << std::endl;	
	return (EXIT_SUCCESS);
}