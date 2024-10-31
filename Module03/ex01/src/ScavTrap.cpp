/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:34:03 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/17 21:04:23 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors & Destructors:

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_guardGate = false;
	
    std::cout << "\033[32m" << "ScavTrap Default Constructor called.\n";
	std::cout << "name =  " << this->_name<< std::endl;
	this->_hit = 100;
	std::cout << "hit points =  " << this->_hit << std::endl;
	this->_energy = 50;
	std::cout << "energy points =  " << this->_energy << std::endl;
	this->_attack = 20;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_guardGate = false;

    std::cout << "\033[32m" << "ScavTrap Constructor with name called.\n";
	this->_name = name;
	std::cout << "name =  " << this->_name << std::endl;
	this->_hit = 100;
	std::cout << "hit points =  " << this->_hit << std::endl;
	this->_energy = 50;
	std::cout << "energy points =  " << this->_energy << std::endl;
	this->_attack = 20;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	this->_hit = other._hit;
	this->_energy = other._energy;
	this->_attack = other._attack;
	this->_guardGate = other._guardGate;

    std::cout << "\033[32m" << "ScavTrap Copy Constructor called for " << this->_name << ".\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->_name = other._name;
	this->_hit = other._hit;
	this->_energy = other._energy;
	this->_attack = other._attack;
	this->_guardGate = other._guardGate;
		
	std::cout << "\033[32m" << "ScavTrap Assignment Operator called.";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[32m" << "ScavTrap Destructor for " << this->_name;
	std::cout << " called." << "\033[0m" << std::endl;
}

//	Methods:

void ScavTrap::attack(ScavTrap &target)
{
	
	if (this->_hit >= 1 && this->_energy >= 1)
	{
		std::cout << "\033[32m" << "ScravTrap " << this->_name << " attacks ";
		std::cout << target._name << ", causing " << this->_attack;
		std::cout << " points of damage!" << "\033[0m" << std::endl;
		this->_energy--;
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;
		target.takeDamage(this->_attack);
	}
	else if (this->_energy == 0)
	{
		std::cout << "\033[32m" << "ScravTrap " << this->_name;
		std::cout << " is not able to attack to " << target._name;
		std::cout << ", because he has no energy points left.\n" << "\033[0m";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;	
	}
	else
	{
		std::cout << "\033[32m" << "ScravTrap " << this->_name;
		std::cout << " is not able to attack to " << target._name;
		std::cout << ", because he has no hit points left.\n" << "\033[0m";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
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
