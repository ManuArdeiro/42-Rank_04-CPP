/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:09:36 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/12 13:01:27 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include "Fixed.hpp"
#include <cstdio>

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	public:
		//	Constructors
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &other);

		// Copy assignment operator overload
		Point &operator=(const Point &other);
		
		//	Destructor
		~Point();
		
		//	Methods
		int		*getCoordinates(void) const;
		void	setCoordinates(const Fixed x, const Fixed y);
		
		//	Arithmetic operators
		Point 	operator-(const Point &other) const;
		
		//	Comparison operator overloading
		bool 	operator==(const Point &other) const;
};

//	bsp.cpp
int is_valid_number(const std::string &option);
int get_number(void);
int	read_vertices(Point &A, Point &B, Point &C);
int	read_point(Point &P);
