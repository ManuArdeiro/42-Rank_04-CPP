/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:24:51 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 18:47:17 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors & Destructors:

ClapTrap::ClapTrap() :
		_name("no one"),
		_hit(10),
		_energy(10),
		_attack(0)

{
	std::cout << "ClapTrap Default Constructor called without values." << std::endl;
	std::cout << "name =  " << this->_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
		_name(name),
		_hit(10),
		_energy(10),
		_attack(0)
{
	std::cout << "ClapTrap Constructor called for " << name <<  " with:" << std::endl;
	std::cout << "name =  " << this->_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) :
	_name(other._name),
	_hit(other._hit),
	_energy(other._energy),
	_attack(other._attack)
{
	std::cout << "ClapTrap Copy Constructor called with:" << std::endl;
	std::cout << "name =  " << this->_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		std::cout << "ClapTrap Copy Constructor called from " << other._name;
		std::cout << " to " << this->_name << std::endl;
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_attack = other._attack;
		std::cout << "name =  " << this->_name << std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor for " << this->_name << " called" << std::endl;
}

// Methods:


void ClapTrap::attack(ClapTrap &target)
{
	if (this->_hit >= 1 && this->_energy >= 1)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target._name;
		std::cout << ", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy--;
		target.takeDamage(this->_attack);
		std::cout << "ClapTrap " << target._name << " has " << target._hit << " hit points left!" << std::endl;
	}
	else if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is not able to attack to " << target._name;
		std::cout << ", because he has no energy points left." << std::endl;		
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is not able to attack to " << target._name;
		std::cout << ", because he has no hit points left." << std::endl;	
	}
	return ;		
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->_hit)
	{
		this->_hit = 0;
		std::cout << "ClapTrap " << this->_name << " took " << amount;
		std::cout << " points of damage and it has no hit points left!" << std::endl;
	}
	else
	{
		this->_hit -= amount;
		std::cout << "ClapTrap " << this->_name << " took " << amount;
		std::cout << " points of damage and it has " << this->_hit;
		std::cout << " hit points left!" << std::endl;
	}
	std::cout << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit >= 1 && this->_energy >= 1)
	{
		this->_hit += amount;
		this->_energy--;
		std::cout << "ClapTrap " << this->_name << " repairs " << amount;
		std::cout << " points of damage and it has " << this->_hit;
		std::cout << " hit points left!" << std::endl;
	}
	else if(this->_hit == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't repair " << amount;
		std::cout << " any points of damage because it hasn't any hit points." << std::endl;
	}
	else if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't repair " << amount;
		std::cout << " any points of damage because it hasn't any energy points." << std::endl;
	}
	return ;
}
