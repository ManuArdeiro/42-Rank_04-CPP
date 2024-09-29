/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:27:36 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 13:17:10 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors & Destructors

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) :_type(type)
{
	std::cout << "WrongAnimal constructor with type called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignation operator called." << std::endl;
	_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

// Methods

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal: Gggggrrrrrr....." << std::endl;
}

// Getters
std::string	WrongAnimal::getType(void) const
{
	return _type;
}