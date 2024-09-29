/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:50:58 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 22:18:14 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*inventory[4];

	public:
		// Default Constructor
		Character();
		
		// Constructor with name
		Character(std::string const & name);
		
		// Copy Constructor
		Character(Character const & other);
		
		// Assignment operator
		Character & operator=(Character const & other);
		
		// Destructor
		~Character();

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};
