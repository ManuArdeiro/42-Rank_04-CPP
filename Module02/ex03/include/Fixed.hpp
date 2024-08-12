/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:44:44 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/12 02:42:15 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int 				_fixedPointValue;
		static const int 	_fractionalBits = 8;

	public:
		//	Default constructor
		Fixed();
		Fixed(const int nb);
		Fixed(const float nb);

		//	Copy constructor
		Fixed(const Fixed &other);

		//	Copy assignment operator
		Fixed &operator=(const Fixed &other);

		//	Destructor
		~Fixed();

		//	Methods
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		//	Comparison operator overloading
		bool 	operator>(const Fixed &other) const;
		bool 	operator<(const Fixed &other) const;
		bool 	operator>=(const Fixed &other) const;
		bool 	operator<=(const Fixed &other) const;
		bool 	operator==(const Fixed &other) const;
		bool 	operator!=(const Fixed &other) const;

		//	Arithmetic operators
		Fixed	operator+(const Fixed &other)const;
		Fixed 	operator-(const Fixed &other) const;
		Fixed 	operator*(const Fixed &other) const;
		Fixed 	operator/(const Fixed &other) const;

		//	Increments / decrements operators
		Fixed 	&operator++();
		Fixed 	operator++(int);
		Fixed 	&operator--();
		Fixed 	operator--(int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);
