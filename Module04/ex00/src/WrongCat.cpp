/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:14:19 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 12:15:02 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
 
// Constructors & Destructors

WrongCat::WrongCat() : _type("WrongCat")
{
	std::cout << "\033[1;31mWrongCat default constructor called.\033[0m" << std::endl;
}

WrongCat::WrongCat(std::string type)	:
	WrongAnimal("WrongAnimal: " + type),
	_type(type)
{
	std::cout << "\033[1;31mWrongCat constructor with type called.\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal::WrongAnimal(other)
{
	std::cout << "\033[1;31mWrongCat copy constructor called.\033[0m" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "\033[1;31mWrongCat assignation operator called.\033[0m" << std::endl;
	_type = other._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "\033[1;31mWrongCat destructor called.\033[0m" << std::endl;
}

// Methods

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: Wrong meow wrong meow!" << std::endl;
}

// Getters
std::string	WrongCat::getType(void) const
{
	return _type;
}