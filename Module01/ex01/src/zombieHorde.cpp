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

/*	ostringstream  is a variant of std::ostream that writes its output to an
	object of type std::string instead of writing to standard output like
	std::cout or a file.
	
	Purpose of std::ostringstream:
    	1.-	It allows formatting data and storing it in a std::string object,
			instead of writing to the console or a file.
    	2.-	It is useful when you want to build or generate a string by inserting
			multiple pieces of data of different types and then obtain the result
			as a std::string.	*/
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
