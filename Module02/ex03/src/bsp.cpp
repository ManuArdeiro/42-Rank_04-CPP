/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:14:23 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/12 13:01:33 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2

static float area (const Point p1, const Point p2, const Point p3)
{
	float	area;

	area =	(
			( p1.get_X().toFloat() * ( p2.get_Y().toFloat() - p3.get_Y().toFloat() ) )
			+ ( p2.get_X().toFloat() * ( p3.get_Y().toFloat() - p1.get_Y().toFloat() ) )
			+ ( p3.get_X().toFloat() * ( p1.get_Y().toFloat() - p2.get_Y().toFloat() ) )
			)
			/ 2;

	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

bool bsp(const Point a, const Point b, const Point c, const Point p)
{
	float d0, d1, d2, d3;
	bool ret_val = false;

	d0 = area(a, b, c);
	d1 = area(p, a, b);
	d2 = area(p, b, c);
	d3 = area(p, a, c);

	if ( d1 == 0 || d2 == 0 || d3 == 0)
		ret_val = false;
	else if ( d1 + d2 + d3 == d0 )
		ret_val = true;

	return (ret_val);
}

int is_valid_number(const std::string &option)
{
	size_t i = 0;
	
    if (option.empty())
        return false;
    if (option[0] == '-')
	{
        if (option.size() == 1)
            return false;
        i = 1;
    }
    for (; i < option.size(); ++i)
	{
        if (!std::isdigit(option[i]))
            return false;
    }
    int num = atoi(option.c_str());
    if (num >= -1000 && num <= 1000)
		return (num);
	return (-5000);
}

int get_number(void)
{
	int			num;
    std::string option;

    while (1)
    {
        std::cout << "BSP> ";
        getline(std::cin, option);
        if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
        }
		num = is_valid_number(option);
        if (!option.empty() && num != -5000)
            break;
        std::cin.clear();
        std::cout << "Please insert a valid number!" << std::endl;
    }
    return (num);
}

int	read_vertices(Point &A, Point &B, Point &C)
{
	Fixed	A_x(get_number()), A_y(get_number());
	Fixed	B_x(get_number()), B_y(get_number());
	Fixed	C_x(get_number()), C_y(get_number());

	A.setCoordinates(A_x, A_y);
	B.setCoordinates(B_x, B_y);
	if (A == B)
	{
		std::cout << "You have cheated!! You've defined two vertices at the";
		std::cout << "same point." << std::endl;
		std::cout << "I don't play with cheaters. Goodbye." << std::endl;
		return (EXIT_FAILURE);
	}
	C.setCoordinates(C_x, C_y);
	if (A == C || B == C)
	{
		std::cout << "You have cheated!! You've defined two vertices at the";
		std::cout << "same point." << std::endl;
		std::cout << "I don't play with cheaters. Goodbye." << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	read_point(Point &P)
{
	Fixed	P_x(get_number()), P_y(get_number());

	P.setCoordinates(P_x, P_y);
	return (EXIT_SUCCESS);
}