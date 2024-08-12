/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:11:25 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/12 13:06:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/****CONSTRUCTORS**************************************************************/

Point::Point(void) : _x(0), _y(0)
{
	// std::cout << "Point created at (0, 0)" << std::endl;
}

Point::Point(const Fixed x, const Fixed y)
{
	this->_x = x;
	this->_y = y;
	// std::cout << "Point created at (" << this->_x.toFloat() << ", ";
	std::cout << this->_y.toFloat() << ")" << std::endl;
}

Point::Point(const Point &other)
{
	this->_x = other._x;
	this->_y = other._y;
	// std::cout << "Point created at (" << this->_x.toFloat() << ", ";
	// std::cout << this->_y.toFloat() << ")" << std::endl;
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	// std::cout << "Point created at (" << this->_x.toFloat() << ", ";
	// std::cout << this->_y.toFloat() << ")" << std::endl;
	return *this;
}

/****DESTRUCTOR****************************************************************/

Point::~Point()
{
	// std::cout << "Point deleted." << std::endl;
}

/****METHODS*******************************************************************/

int		*Point::getCoordinates(void) const
{
	int* coordinates = new int[2];
    coordinates[0] = this->_x.toInt();
    coordinates[1] = this->_y.toInt();
    
    return coordinates;
}

void	Point::setCoordinates(const Fixed x, const Fixed y)
{
	this->_x = x;
	this->_y = y;
}

/****ARIMETHIC OPERATORS*******************************************************/
Point	Point::operator-(const Point &other) const
{
	Point	result;
	
	result._x = this->_x - other._x;
	result._y = this->_y - other._y;
	return (result); 
}

/****OPERATORS*****************************************************************/

bool 	Point::operator==(const Point &other) const
{
	    return (this->_x.getRawBits() == other._x.getRawBits()
			&& this->_y.getRawBits() == other._y.getRawBits());
}