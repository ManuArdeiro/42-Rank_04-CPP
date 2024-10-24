/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:10:55 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/18 01:25:34 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

/*	Serialize method: Converts a pointer of type Data* into a uintptr_t value
	using reinterpret_cast. This is useful for serializing a pointer into a
	representation that can be transmitted or stored.

	Deserialize method: Takes a uintptr_t value and converts it back into a
	pointer of type Data* using reinterpret_cast. This allows deserializing
	the value back to the original pointer.
*/
class Serializer
{
	public:
		// Method to serialize a pointer to Data into an uintptr_t
		static uintptr_t	serialize(Data *ptr);

		// Method to deserialize an uintptr_t back into a pointer to Data
		static Data			*deserialize(uintptr_t raw);

	private:
		// Canonical form (private to prevent instantiation)
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
};
