/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:57:19 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/03 22:29:57 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	hordeTest(int N, Zombie* hordeArray)
{
	for (int i = 0; i < N; i++)
	{
		hordeArray[i].announce();
	}
}