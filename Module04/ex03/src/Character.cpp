/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:52:28 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/29 12:49:06 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default Constructor
Character::Character() :
	name("undefined")
{
	std::cout << "\033[1;35mCharacter default constructor called.\033[0m" << std::endl;
    for (int i = 0; i < 4; ++i)
        this->inventory[i] = NULL;
}

// Constructo with name
Character::Character(std::string const & name) :
	name(name)
{
	std::cout << "\033[1;35mCharacter name constructor called.\033[0m" << std::endl;
    for (int i = 0; i < 4; ++i)
        this->inventory[i] = NULL;
}

// Copy Constructor
Character::Character(Character const & other) : name(other.name)
{
	std::cout << "\033[1;35mCharacter copy constructor called.\033[0m" << std::endl;
    for (int i = 0; i < 4; ++i)
	{
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
	}
}

// Assignment operator
Character & Character::operator=(Character const & other)
{
	std::cout << "\033[1;35mCharacter assignation operator called.\033[0m" << std::endl;
    if (this != &other)
	{
        name = other.name;
        for (int i = 0; i < 4; ++i)
		{
            delete inventory[i];
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

// Destructor
Character::~Character()
{
	std::cout << "\033[1;35mCharacter destructor called.\033[0m" << std::endl;
    for (int i = 0; i < 4; ++i)
        delete this->inventory[i];
}

// Methods
std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
	{
        if (!inventory[i])
		{
            this->inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        this->inventory[idx]->use(target);
}
