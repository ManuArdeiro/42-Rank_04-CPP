/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:13:17 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/29 12:40:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"


// Forward declaration
class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		// Constructors
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria& other);
		AMateria &operator=(const AMateria &other);
		
		// Destructor
		virtual ~AMateria();

		// Métodos
		std::string const &getType() const; // Returns the materia type
		virtual AMateria *clone() const = 0; // Pure virtual
		virtual void use(ICharacter &target);
};
