/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:44:21 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/11 00:09:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

/*	Shifting nb to the left by a number of bits multiplies the integer value
	by 2 raised to that number. This places the integer value in the "integer"
	part of the fixed-point representation, leaving the fractional part as
	zeros. */
Fixed::Fixed(const int nb)
{
	std::cout << "Fixed int constructor called" << std::endl;
	this->_fixedPointValue = nb << this->_fractionalBits;
}

/*	The expression nb * (1 << _fractionalBits) multiplies the floating-point
	number nb by 2 raised to the power of _fractionalBits. This effectively
	shifts the decimal point to the right, preparing the number for fixed-point
	representation.
	For example, if _fractionalBits is 8, then 1 << _fractionalBits equals 256
	(since 2^ = 256). So, if nb is 3.75, the multiplication would be:
						3.75 × 256 = 960
	This shifts the decimal point two places to the right, converting 3.75
	into 960, which can be stored as an integer.
	The roundf() function is then used to round the result to the nearest integer.
	So, if nb were 3.751, multiplying by 256 would give approximately 960.256.
	roundf() would round this to 960, ensuring the stored value in 
	_fixedPointValue is as accurate as possible.	*/
Fixed::Fixed(const float nb)
{
    std::cout << "Fixed float constructor called" << std::endl;
    this->_fixedPointValue = roundf(nb * (1 << this->_fractionalBits));
}


Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)  // Protect against self-assignment
	{
		_fixedPointValue = other._fixedPointValue;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Returns the raw value of the fixed-point number
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

// Sets the raw value of the fixed-point number
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
    return ((float)(this->_fixedPointValue) / (float)(1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

/*	Function overloading in C++ is a feature that allows you to define multiple
	functions with the same name but with different parameters (number, type,
	or both). These functions are called overloaded functions and enable the same
	function name to perform different tasks depending on the context in which it
	is called.
	C++ also allows operator overloading, which lets you define how certain operators,
	like +, -, *, <<, and others, behave for custom data types.
	In this case, the overloaded operator<< function takes an output stream
	(std::ostream& os) and a Fixed object and returns the output stream after adding
	the desired representation of the Fixed object. This allows std::cout << d to
	work correctly.
			std::ostream &operator<<:
		This is an overloaded operator function for << that takes a std::ostream
		(like std::cout) and an object of type Fixed as parameters.
			const Fixed &fixed:
		This is a constant reference to an object of type Fixed. Using a constant
		reference avoids unnecessary copying of the object and ensures that the
		function does not modify the fixed object.		*/
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat(); // Assuming toFloat() returns a value that can be printed directly
    return os;
}
