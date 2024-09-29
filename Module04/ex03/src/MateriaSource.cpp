/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:04:16 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/29 12:41:16 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default Constructor
MateriaSource::MateriaSource()
{
	std::cout << "\033[1;30mMateriaSource default constructor called.\033[0m" << std::endl;
    for (int i = 0; i < 4; ++i)
        materias[i] = NULL;
}

// Copy Constructor
MateriaSource::MateriaSource(MateriaSource const & other)
{
	std::cout << "\033[1;30mMateriaSource copy constructor called.\033[0m" << std::endl;
    for (int i = 0; i < 4; ++i)
	{
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = NULL;
	}
}

// Assignment operator
MateriaSource & MateriaSource::operator=(MateriaSource const & other)
{
	std::cout << "\033[1;30mMateriaSource assignation operator called.\033[0m" << std::endl;
    if (this != &other)
	{
        for (int i = 0; i < 4; ++i)
		{
            delete materias[i];
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = NULL;
        }
    }
    return *this;
}

// Destructor
MateriaSource::~MateriaSource()
{
	std::cout << "\033[1;30mMateriaSource destructor called.\033[0m" << std::endl;
    for (int i = 0; i < 4; ++i)
        delete materias[i];
}

// Learn Materia
void MateriaSource::learnMateria(AMateria *m)
{
	std::cout << "\033[1;30mLearnMateria called from MateriaSource.\033[0m" << std::endl;
    for (int i = 0; i < 4; ++i)
	{
        if (!materias[i])
		{
            materias[i] = m;
            break;
        }
    }
}

// Crear Materia
AMateria* MateriaSource::createMateria(std::string const &type)
{
	std::cout << "\033[1;30mCreateMateria called from MateriaSource.\033[0m" << std::endl;
    for (int i = 0; i < 4; ++i)
	{
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
	}
    return NULL;
}
