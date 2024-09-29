/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:26:45 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 13:17:47 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors & Destructors

Dog::Dog() : _type("Dog")
{
	std::cout << "\033[1;31mDog default constructor called.\033[0m" << std::endl;
}

Dog::Dog(std::string type)	:
	Animal("Animal: " + type),
	_type(type)
{
	std::cout << "\033[1;31mDog constructor with type called.\033[0m" << std::endl;
}

Dog::Dog(const Dog &other) : Animal::Animal(other)
{
	std::cout << "\033[1;31mDog copy constructor called.\033[0m" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "\033[1;31mDog assignation operator called.\033[0m" << std::endl;
	_type = other._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "\033[1;31mDog destructor called.\033[0m" << std::endl;
}

// Methods

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Woof woof!" << std::endl;
}

// Getters
std::string	Dog::getType(void) const
{
	return _type;
}