/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:44:22 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 19:18:37 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors & Destructors

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "\033[1;32mCat default constructor called.\033[0m" << std::endl;
	this->_brain = new Brain();
	return;
}
Cat::Cat(const Cat &other) :
	Animal(other)
{
	std::cout << "\033[1;32mCat copy constructor called.\033[0m" << std::endl;
	this->_brain = new Brain();
	*this = other;
	return;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "\033[1;32mCat assignation operator called.\033[0m" << std::endl;
	this->_type = other._type;
	*(this->_brain) = *(other._brain);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "\033[1;32mCat destructor called.\033[0m" << std::endl;
	delete this->_brain;
	return;
}

// Methods

void	Cat::makeSound(void) const
{
	std::cout << "\033[1;32m" << this->_type << ": Meaow Meaow!\033[0m" << std::endl;
	return;
}

// Getters

std::string	Cat::getType(void) const
{
	return (this->_type);
}

Brain	*Cat::getBrain(void) const
{
	std::cout << "Cat getBrain called." << std::endl;
	return this->_brain;
}
