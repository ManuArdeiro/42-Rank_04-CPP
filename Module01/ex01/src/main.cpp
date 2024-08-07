/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:30:59 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/03 22:35:36 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*hordeArray;
	int		N = 10;

	hordeArray = zombieHorde(N, "Zombie_");
	if (hordeArray == NULL)
		return (1);
	hordeTest(N, hordeArray);
	delete[] hordeArray;
	return (0);
}