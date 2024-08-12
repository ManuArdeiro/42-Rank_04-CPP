/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 09:44:44 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/10 11:37:16 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <iostream>

class Fixed {
	private:
		int 				_fixedPointValue;
		static const int 	_fractionalBits = 8;

	public:
		//	Default constructor
		Fixed();

		//	Copy constructor
		Fixed(const Fixed &other);

		//	Copy assignment operator
		Fixed &operator=(const Fixed &other);

		//	Destructor
		~Fixed();

		//	Methods
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

