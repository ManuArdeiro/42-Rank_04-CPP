/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:44:21 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/10 11:38:49 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default Constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &other) :
	_fixedPointValue(other.getRawBits())
{
	std::cout << "Copy constructor called." << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other)  // Protect against self-assignment
	{
		_fixedPointValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

// Returns the raw value of the fixed-point number
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return _fixedPointValue;
}

// Sets the raw value of the fixed-point number
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	_fixedPointValue = raw;
}