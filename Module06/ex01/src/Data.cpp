/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:10:03 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/17 21:10:25 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Default constructor
Data::Data() : number(0), text("")
{
    std::cout << "Data default constructor called." << std::endl;
}

// Copy constructor
Data::Data(const Data &other) : number(other.number), text(other.text)
{
    std::cout << "Data copy constructor called." << std::endl;
}

// Assignment operator
Data &Data::operator=(const Data &other)
{
    std::cout << "Data assignment operator called." << std::endl;
    if (this != &other)
	{
        this->number = other.number;
        this->text = other.text;
    }
    return *this;
}

// Destructor
Data::~Data()
{
    std::cout << "Data destructor called." << std::endl;
}
