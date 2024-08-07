/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:40:27 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/01 12:26:36 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Function to create a Zombie on the stack and make it announce itself
void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}
