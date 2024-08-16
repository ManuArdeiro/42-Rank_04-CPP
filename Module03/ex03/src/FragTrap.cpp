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
    this->setHit(100);
    this->setEnergy(100);
    this->setAttack(30);
	this->_guardGate = false;
	
    std::cout << "\033[32m" << "FragTrap Default Constructor called.\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->getHit() << std::endl;
	std::cout << "energy points =  " << this->getEnergy() << std::endl;
	std::cout << "attack damage =  " << this->getAttack() << std::endl;
	std::cout << "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name, unsigned int hit, unsigned int energy,
	unsigned int attack) : ClapTrap(name, hit, energy, attack)
{
	this->_guardGate = false;

    std::cout << "\033[32m" << "FragTrap Constructor called for " << name << ".\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->getHit() << std::endl;
	std::cout << "energy points =  " << this->getEnergy() << std::endl;
	std::cout << "attack damage =  " << this->getAttack() << std::endl;
	std::cout << "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->setHit(100);
    this->setEnergy(100);
    this->setAttack(30);
	this->_guardGate = false;

    std::cout << "\033[32m" << "FragTrap Constructor called for " << name << ".\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->getHit() << std::endl;
	std::cout << "energy points =  " << this->getEnergy() << std::endl;
	std::cout << "attack damage =  " << this->getAttack() << std::endl;
	std::cout << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    this->setHit(other.getHit());
    this->setEnergy(other.getEnergy());
    this->setAttack(other.getAttack());

    std::cout << "\033[32m" << "FragTrap Copy Constructor called.\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->getHit() << std::endl;
	std::cout << "energy points =  " << this->getEnergy() << std::endl;
	std::cout << "attack damage =  " << this->getAttack() << std::endl;
	std::cout << this->_name << "\033[0m" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
		this->_name = other._name;
		this->setHit(other.getHit());
		this->setEnergy(other.getEnergy());
		this->setAttack(other.getAttack());
		this->_guardGate = other._guardGate;
		
        std::cout << "\033[32m" << "FragTrap Assignment Operator called.\n";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->getHit() << std::endl;
		std::cout << "energy points =  " << this->getEnergy() << std::endl;
		std::cout << "attack damage =  " << this->getAttack() << std::endl;
		std::cout << "\033[0m" << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[32m" << "FragTrap Destructor for " << this->_name;
	std::cout << " called." << "\033[0m" << std::endl;
}

//	Methods:

void FragTrap::attack(const std::string &target)
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": high five!! \n\t-CLAPP...-\nWell done!!" << std::endl;
}
