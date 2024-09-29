/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:46:38 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/26 12:45:25 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors & Destructors

Brain::Brain(void) :
	ideas()
{
	std::cout << "\033[1;33mBrain default constructor called.\033[0m" << std::endl;
	return;
}

Brain::Brain(const Brain &other)
{
	std::cout << "\033[1;33mBrain copy constructor called.\033[0m" << std::endl;
	*this = other;
	return;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "\033[1;33mBrain assignation operator called.\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "\033[1;33mBrain destructor called.\033[0m" << std::endl;
	return;
}
