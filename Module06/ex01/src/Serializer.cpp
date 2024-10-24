/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:12:25 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/18 01:21:46 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*	Serialize method: Converts a pointer of type Data* into a uintptr_t value
	using reinterpret_cast. This is useful for serializing a pointer into a
	representation that can be transmitted or stored.	*/
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

/*	Deserialize method: Takes a uintptr_t value and converts it back into a
	pointer of type Data* using reinterpret_cast. This allows deserializing
	the value back to the original pointer.	*/
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

// Private constructors to prevent instantiation
Serializer::Serializer()
{
    std::cout << "Serializer default constructor called." << std::endl;
}

// Private copy constructor
Serializer::Serializer(const Serializer &other)
{
    std::cout << "Serializer copy constructor called." << std::endl;
    (void)other;
}

// Private assignment operator
Serializer &Serializer::operator=(const Serializer &other)
{
    std::cout << "Serializer assignment operator called." << std::endl;
    (void)other;
    return *this;
}

// Destructor
Serializer::~Serializer()
{
    std::cout << "Serializer destructor called." << std::endl;
}
