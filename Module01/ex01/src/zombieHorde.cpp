/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:47:10 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/03 22:29:28 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static std::string to_string(int value)
{
    std::ostringstream nbString;
    nbString << value;
    return nbString.str();
}

Zombie* zombieHorde(int N, std::string name)
{	
	if (N < 2)
	{
		std::cout << "A horde is at least 2 zombies..." << std::endl;
		return (NULL);
	}
	Zombie* hordeArray = new Zombie[N];
	if (hordeArray == NULL)
	{
		std::cout << "Error allocating the horde." << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
        hordeArray[i].set_name(name + to_string(i + 1));
	}
	return (hordeArray);
}

void deleteZombies(Zombie* zombieArray)
{
    delete[] zombieArray;
}
