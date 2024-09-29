/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:21:54 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 13:16:53 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors & Destructors

Animal::Animal()
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor with type called." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignation operator called." << std::endl;
	_type = other._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

// Methods

void	Animal::makeSound(void) const
{
	std::cout << "Animal: Zzzzzzz....." << std::endl;
}

// Getters
std::string	Animal::getType(void) const
{
	return _type;
}
