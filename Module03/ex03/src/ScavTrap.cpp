/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:34:03 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 18:49:05 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors & Destructors:

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_guardGate = false;
	
    std::cout << "\033[32m" << "ScavTrap Default Constructor called.\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->getHit() << std::endl;
	std::cout << "energy points =  " << this->getEnergy() << std::endl;
	std::cout << "attack damage =  " << this->getAttack() << std::endl;
	std::cout << "\033[0m" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_guardGate = false;

    std::cout << "\033[32m" << "ScavTrap Constructor called for " << name << ".\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->getHit() << std::endl;
	std::cout << "energy points =  " << this->getEnergy() << std::endl;
	std::cout << "attack damage =  " << this->getAttack() << std::endl;
	std::cout << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name, unsigned int hit, unsigned int energy,
	unsigned int attack) : ClapTrap(name, hit, energy, attack)
{
	this->_guardGate = false;

    std::cout << "\033[32m" << "ScavTrap Constructor called for " << name << ".\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->getHit() << std::endl;
	std::cout << "energy points =  " << this->getEnergy() << std::endl;
	std::cout << "attack damage =  " << this->getAttack() << std::endl;
	std::cout << "\033[0m" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    this->setHit(other.getHit());
    this->setEnergy(other.getEnergy());
    this->setAttack(other.getAttack());
	this->_guardGate = other._guardGate;

    std::cout << "\033[32m" << "ScavTrap Copy Constructor called for " << this->_name << ".\n";;
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->getHit() << std::endl;
	std::cout << "energy points =  " << this->getEnergy() << std::endl;
	std::cout << "attack damage =  " << this->getAttack() << std::endl;
	std::cout << this->_name << "\033[0m" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
		this->_name = other._name;
		this->setHit(other.getHit());
		this->setEnergy(other.getEnergy());
		this->setAttack(other.getAttack());
		this->_guardGate = other._guardGate;
		
        std::cout << "\033[32m" << "ScavTrap Assignment Operator called.";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->getHit() << std::endl;
		std::cout << "energy points =  " << this->getEnergy() << std::endl;
		std::cout << "attack damage =  " << this->getAttack() << std::endl;
		std::cout << "\033[0m" << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[32m" << "ScavTrap Destructor for " << this->_name;
	std::cout << " called." << "\033[0m" << std::endl;
}

//	Methods:

void ScavTrap::attack(const std::string &target)
{
	
	if (this->getHit() >= 1 && this->getEnergy() >= 1)
	{
		std::cout << "\033[32m" << "ScravTrap " << this->_name << " attacks ";
		std::cout << target << ", causing " << this->getAttack();
		std::cout << " points of damage!" << "\033[0m" << std::endl;
		this->setEnergy(this->getEnergy() - 1);
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->getHit() << std::endl;
		std::cout << "energy points =  " << this->getEnergy() << std::endl;
		std::cout << "attack damage =  " << this->getAttack() << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
	else if (this->getEnergy() == 0)
	{
		std::cout << "\033[32m" << "ScravTrap " << this->_name;
		std::cout << " is not able to attack to " << target;
		std::cout << ", because he has no energy points left.";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->getHit() << std::endl;
		std::cout << "energy points =  " << this->getEnergy() << std::endl;
		std::cout << "attack damage =  " << this->getAttack() << std::endl;
		std::cout << "\033[0m" << std::endl;
		std::cout << "\033[0m" << std::endl;		
	}
	else
	{
		std::cout << "\033[32m" << "ScravTrap " << this->_name;
		std::cout << " is not able to attack to " << target;
		std::cout << ", because he has no hit points left.";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->getHit() << std::endl;
		std::cout << "energy points =  " << this->getEnergy() << std::endl;
		std::cout << "attack damage =  " << this->getAttack() << std::endl;
		std::cout << "\033[0m" << std::endl;
		std::cout << "\033[0m" << std::endl;	
	}
	return ;
}

void ScavTrap::guardGate(void)
{
	if (this->_guardGate == false)
	{
		this->_guardGate = true;
		std::cout << "\033[32m" << "ScavTrap " << this->_name;
		std::cout << " is now guarding the gate." << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[32m" << "ScavTrap " << this->_name;
		std::cout << " was already guarding the gate." << "\033[0m" << std::endl;
	}
}
