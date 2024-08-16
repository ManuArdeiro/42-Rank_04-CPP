/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:11:03 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 01:19:51 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors & Destructors:

FragTrap::FragTrap() : ClapTrap()
{
	
    std::cout << "\033[31m" << "FragTrap Default Constructor called.\n";
	std::cout << "name =  " << this->_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{

    std::cout << "\033[31m" << "FragTrap Constructor called for " << name << ".\n";
	std::cout << "name =  " << this->_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name, unsigned int hit, unsigned int energy,
	unsigned int attack) : ClapTrap(name, hit, energy, attack)
{

    std::cout << "\033[31m" << "FragTrap Constructor called for " << name << ".\n";
	std::cout << "name =  " << this->_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
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
    if (this != &other)
    {
        ClapTrap::operator=(other);
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
    }
    return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[31m" << "FragTrap Destructor for " << this->_name;
	std::cout << " called." << "\033[0m" << std::endl;
}

//	Methods:

void FragTrap::attack(const std::string &target)
{
	
	if (this->_hit >= 1 && this->_energy >= 1)
	{
		std::cout << "\033[31m" << "FragTrap " << this->_name << " attacks ";
		std::cout << target << ", causing " << this->_attack;
		std::cout << " points of damage!" << std::endl;
		this->_energy--;
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
	else if (this->_energy == 0)
	{
		std::cout << "\033[31m" << "ScravTrap " << this->_name;
		std::cout << " is not able to attack to " << target;
		std::cout << ", because he has no energy points left.";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;
		std::cout << "\033[0m" << std::endl;		
	}
	else
	{
		std::cout << "\033[31m" << "ScravTrap " << this->_name;
		std::cout << " is not able to attack to " << target;
		std::cout << ", because he has no hit points left.";
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
	std::cout << "\033[31mFragTrap " << this->_name << ": high five!!";
	std::cout << " \n-CLAPP...-\nWell done!!\033[0m" << std::endl;
}
