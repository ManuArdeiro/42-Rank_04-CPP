/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:22:21 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 22:13:43 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default Constructor
AMateria::AMateria() :
	_type("undefined")
{
	std::cout << "\033[1;33mAMateria default constructor called.\033[0m" << std::endl;
}

// Constructor with type
AMateria::AMateria(std::string const &type) :
	_type(type)
{
	std::cout << "\033[1;33mAMateria type constructor called.\033[0m" << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria &other)
{
	std::cout << "\033[1;33mAMateria copy constructor called.\033[0m" << std::endl;
    *this = other;
}

// Assignment operator
AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "\033[1;33mAMateria assignation operator called.\033[0m" << std::endl;
    if (this != &other)
	{
        this->_type = other._type;
    }
    return *this;
}

// Destructor
AMateria::~AMateria()
{
	std::cout << "\033[1;33mAMateria destructor called.\033[0m" << std::endl;
}

// Getters
std::string const &AMateria::getType() const
{
	std::cout << "\033[1;33mAMateria getType called.\033[0m" << std::endl;
    return _type;
}

// Materia use
void AMateria::use(ICharacter &target)
{
    std::cout << "\033[1;33m* uses an " << this->_type << " materia on " << target.getName() << " *\033[0m" << std::endl;
}
