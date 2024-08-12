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

#include "Fixed.hpp"
#include "Point.hpp"

static void print_vertices_message(void)
{
    std::cout << "		jolopez-				BSP \n"<< std::endl;
	std::cout << "I need the 3 vertices of the triangle." << std::endl;
    std::cout << "For that, you will need to input 6" << std::endl;
    std::cout << "integer numbers between -1000 and 1000." << std::endl;
    std::cout << "Each time you type one, press ENTER.|" << std::endl;
}

static void print_point_message(void)
{
    std::cout << "Very good!! Now enter the 2 coordinates" << std::endl;
    std::cout << "(between -1000 and 1000) of the point" << std::endl;
    std::cout << "you want to check if it's inside the" << std::endl;
    std::cout << "triangle or not." << std::endl;
}

static void print_inside_message(void)
{
    std::cout << "Perfect!!" << std::endl;
    std::cout << "The point is INSIDE the triangle!!" << std::endl;
	std::cout << "Have a nice day..." << std::endl;
}

static void print_outside_message(void)
{
	std::cout << "Perfect!!               |" << std::endl;
	std::cout << "The point is OUTSIDE the triangle!!" << std::endl;
	std::cout << "Have a nice day..." << std::endl;
}

int main(void)
{
	Point	A, B, C, P;
	Point	D, E;
	int		*a, *b, *c, *p;
	int		*d, *e;
	float	w1, w2;

	print_vertices_message();
	if (read_vertices(A, B, C))
		return (EXIT_FAILURE);
	a = A.getCoordinates();
	b = B.getCoordinates();
	c = C.getCoordinates();
	D = B - A;
	E = C - A;
	d = D.getCoordinates();
	e = E.getCoordinates();
	if ((d[0] * e[1] - d[1] * e[0]) == 0)
	{
		std::cout << "The 3 vertices are in the same line!!" << std::endl;
		delete[] a;
		delete[] b;
		delete[] c;
		delete[] d;
		delete[] e;
		return (EXIT_SUCCESS);
	}
	print_point_message();
	if (read_point(P))
		return (EXIT_FAILURE);
	p = P.getCoordinates();
	w1 = (e[0] * (a[1] - p[1]) + e[1] * (p[0] - a[0])) / (d[0] * e[1] - d[1] * e[0]);
	w2 = (p[1] - a[1] - w1 * d[1]) / e[1];
	if (w1 >= 0.0 && w2 >= 0.0 && (w1 + w2) <= 1.0)
		print_inside_message();
	else
		print_outside_message();
	delete[] a;
	delete[] b;
	delete[] c;
	delete[] p;
	delete[] d;
	delete[] e;
	return (EXIT_SUCCESS);

}
