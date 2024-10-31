/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:00:43 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 22:07:06 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materias[4];

	public:
		// Default Constructor
		MateriaSource();
		
		// Copy Constructor
		MateriaSource(MateriaSource const & other);
		
		// Assignment operator
		MateriaSource & operator=(MateriaSource const &other);
		
		// Destructor
		~MateriaSource();

		// Methods
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);
};