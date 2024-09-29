/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:21:54 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 19:25:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors & Destructors

Animal::Animal(void) :
	_type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
	return;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = other;
	return;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignation operator called." << std::endl;
    if ((this->_type == "Cat" || this->_type == "Dog")
		&& (other._type == "Cat" || other._type == "Dog"))
    {
		*get_brain() = *other.get_brain();
	}
	this->_type = other._type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." << std::endl;
	return;
}

// Methods

void	Animal::makeSound(void) const
{
	std::cout << "Animal: Zzzzzzz....." << std::endl;
}

// Getters
std::string	Animal::get_Type(void) const
{
	std::cout << "Animal getType called." << std::endl;
	return this->_type;
}

Brain	*Animal::get_brain(void) const
{
	std::cout << "Animal get_brain called." << std::endl;
	return NULL;
}
