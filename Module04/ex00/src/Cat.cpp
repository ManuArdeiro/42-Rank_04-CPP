/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:44:22 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 13:17:23 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors & Destructors

Cat::Cat() : _type("Cat")
{
	std::cout << "\033[1;31mCat default constructor called.\033[0m" << std::endl;
}

Cat::Cat(std::string type)	:
	Animal("Animal: " + type),
	_type(type)
{
	std::cout << "\033[1;31mCat constructor with type called.\033[0m" << std::endl;
}

Cat::Cat(const Cat &other) : Animal::Animal(other)
{
	std::cout << "\033[1;31mCat copy constructor called.\033[0m" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "\033[1;31mCat assignation operator called.\033[0m" << std::endl;
	_type = other._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "\033[1;31mCat destructor called.\033[0m" << std::endl;
}

// Methods

void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meow meow!" << std::endl;
}

// Getters
std::string	Cat::getType(void) const
{
	return _type;
}