/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:26:45 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 19:33:11 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors & Destructors

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout << "\033[1;31mDog default constructor called.\033[0m" << std::endl;
	this->_brain = new Brain();
	return;
}

Dog::Dog(const Dog &other) :
	Animal::Animal(other)
{
	std::cout << "\033[1;31mDog copy constructor called.\033[0m" << std::endl;
	this->_brain = new Brain();
	*this = other;
	return;
}

/*	Deep copy is important when classes have attributes that point to dynamic
	memory (for example, pointers that point to objects created with new). It
	could also be done like this:
		Animal::operator=(other);  // Copies the Animal part
		delete brain;              // Frees the current memory
		brain = new Brain(*other.brain);  // Deep copy of the Brain.	*/
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "\033[1;31mDog assignation operator called.\033[0m" << std::endl;
	this->_type = other._type;
	*(this->_brain) = *(other._brain);
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "\033[1;31mDog destructor called.\033[0m" << std::endl;
	delete this->_brain;
	return;
}

// Methods

void	Dog::makeSound(void) const
{
	std::cout << "\033[1;31m" << this->_type << ": Woof woof!\033[0m" << std::endl;
	return;
}

// Getters

Brain	*Dog::get_brain(void) const
{
	std::cout << "Dog get_brain called." << std::endl;
	return this->_brain;
}

std::string	Dog::get_Type(void) const
{
	return (this->_type);
}
