/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:32:58 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 21:44:11 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Default Constructor
Ice::Ice() : AMateria("ice")
{
	std::cout << "\033[1;32mIce default constructor called.\033[0m" << std::endl;
}

// Copy Constructor
Ice::Ice(Ice const & other) : AMateria(other)
{
	std::cout << "\033[1;32mIce copy constructor called.\033[0m" << std::endl;
    *this = other;
}

// Assignment operator
Ice & Ice::operator=(Ice const & other)
{
	std::cout << "\033[1;32mIce assignation operator called.\033[0m" << std::endl;
    if (this != &other)
	{
        AMateria::operator=(other);
    }
    return *this;
}

// Destructor
Ice::~Ice()
{
	std::cout << "\033[1;32mIce destructor called.\033[0m" << std::endl;
}

// Clonar
AMateria* Ice::clone() const
{
	std::cout << "\033[1;32mClone() called from Ice.\033[0m" << std::endl;
    return new Ice(*this);
}

// Uso de Materia
void Ice::use(ICharacter& target)
{
    std::cout << "\033[1;32m* shoots an ice bolt at " << target.getName() << " *\033[0m" << std::endl;
}
