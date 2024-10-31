/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:31:26 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 21:34:55 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// Default Constructor
		Ice();
		
		// Copy Constructor
		Ice(Ice const & other);
		
		// Assignment operator
		Ice & operator=(Ice const & other);
		
		// Destructor
		~Ice();
		
		// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};