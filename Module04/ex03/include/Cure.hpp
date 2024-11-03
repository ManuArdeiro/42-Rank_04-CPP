/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:41:32 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 21:41:57 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Constructors
		Cure();
		Cure(Cure const & other);
		Cure & operator=(Cure const & other);
		
		// Destructor
		~Cure();
		
		// Methods
		AMateria* clone() const;
		void use(ICharacter& target);
};
