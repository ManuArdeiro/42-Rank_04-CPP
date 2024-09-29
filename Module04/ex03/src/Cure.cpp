/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:42:55 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 21:44:44 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Default Constructor
Cure::Cure() : AMateria("cure")
{
	std::cout << "\033[1;31mCure default constructor called.\033[0m" << std::endl;
}

// Constructor de copia
Cure::Cure(Cure const & other) : AMateria(other)
{
	std::cout << "\033[1;31mCure copy constructor called.\033[0m" << std::endl;
    *this = other;
}

// Operador de asignación
Cure & Cure::operator=(Cure const & other)
{
	std::cout << "\033[1;31mCure assignation operator called.\033[0m" << std::endl;
    if (this != &other)
	{
        AMateria::operator=(other);
    }
    return *this;
}

// Destructor
Cure::~Cure()
{
	std::cout << "\033[1;31mCure destructor called.\033[0m" << std::endl;
}

// Clonar
AMateria* Cure::clone() const
{
	std::cout << "\033[1;31mClone() called from Cure.\033[0m" << std::endl;
    return new Cure(*this);
}

// Uso de Materia
void Cure::use(ICharacter& target) {
    std::cout << "\033[1;31m* heals " << target.getName() << "'s wounds *\033[0m" << std::endl;
}
