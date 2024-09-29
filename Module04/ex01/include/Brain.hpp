/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:45:56 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/25 18:56:27 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
		
	public:
		std::string ideas[100];
		
		// Constructors & Destructors
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain(void);
};
