/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:38:31 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/01 12:23:03 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream> // cin, cout, endl
# include <string> // string class

class Zombie
{
	public:
		void announce(void) const;
		
		Zombie(std::string name);
		~Zombie(void);
		
	private:
		std::string name;
		
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif