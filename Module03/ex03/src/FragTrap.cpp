/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:11:03 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 01:45:15 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors & Destructors:

FragTrap::FragTrap() : ClapTrap()
{
    this->_hit = 100;
    this->_energy = 100;
    this->_attack = 30;
	
    std::cout << "\033[32m" << "FragTrap Default Constructor called.\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->_hit<< std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
    this->_hit = 100;
    this->_energy = 100;
    this->_attack = 30;

    std::cout << "\033[32m" << "FragTrap Constructor called for " << name << ".\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->_hit<< std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    this->_name = other._name;
    this->_hit = other._hit;
    this->_energy = other._energy;
    this->_attack = other._attack;

    std::cout << "\033[31m" << "FragTrap Copy Constructor from a FragTrap called.\n";
	std::cout << "name =  " << this->_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << this->_name << "\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	this->_name = other._name;
	this->_hit = other._hit;
	this->_energy = other._energy;
	this->_attack = other._attack;
	
	std::cout << "\033[31m" << "FragTrap Assignment Operator called.\n";
	std::cout << "name =  " << this->_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
    return *this;
}


FragTrap::~FragTrap()
{
	std::cout << "\033[32m" << "FragTrap Destructor for " << this->_name;
	std::cout << " called." << "\033[0m" << std::endl;
}

//	Methods:

void FragTrap::attack(FragTrap &target)
{
	
	if (this->_hit >= 1 && this->_energy >= 1)
	{
		std::cout << "\033[31m" << "FragTrap " << this->_name << " attacks ";
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
		std::cout << "\033[31m" << "FragTrap " << this->_name;
		std::cout << " is not able to attack to " << target._name;
		std::cout << ", because he has no energy points left." << std::endl;
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;
		std::cout << "\033[0m" << std::endl;		
	}
	else
	{
		std::cout << "\033[31m" << "FragTrap " << this->_name;
		std::cout << " is not able to attack to " << target._name;
		std::cout << ", because he has no hit points left." << std::endl;
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;
		std::cout << "\033[0m" << std::endl;	
	}
	return ;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": high five!! \n\t-CLAPP...-\nWell done!!" << std::endl;
}
