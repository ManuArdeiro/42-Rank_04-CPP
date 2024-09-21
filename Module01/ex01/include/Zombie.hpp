/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:38:31 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/03 22:24:04 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream> // cin, cout, endl
#include <string> // string class
#include <sstream>

class Zombie
{
	public:
		void	announce(void) const;
		void	set_name(std::string name);
		
        Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		
	private:
		std::string name;
		
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
Zombie*	zombieHorde(int N, std::string name);
void	deleteZombies(Zombie* zombieArray);
void	hordeTest(int N, Zombie* zombieArray);
