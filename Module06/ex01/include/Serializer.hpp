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
	/*	uintptr_t is an unsigned integer data type defined in C and C++ that
		is used to store memory addresses (pointers) as integer values. It is
		defined in the <cstdint> header in C++ and <stdint.h> in C, and its
		size is sufficient to hold any pointer value.
		
		Main Characteristics

		Size		->	uintptr_t has the same size as a pointer (e.g., void*).
						This means it can store any memory address without losing
						precision, which is useful in situations where you need to
						convert a pointer to an integer for manipulation.
		Portability	->	As part of the standard library, it ensures that the type
						has the appropriate size on any platform. This helps to
						avoid portability issues when handling pointers as integers.
    	Usage		->	Its primary use is in low-level operations, such as memory
						address manipulation, pointer serialization, or interpreting
						pointers as integers for pointer arithmetic operations.
		
		Example:

		#include <iostream>
		#include <cstdint> // For uintptr_t

		int main()
		{
			int x = 42;
			int* ptr = &x;

			// Convert the pointer to uintptr_t
			uintptr_t intPtr = reinterpret_cast<uintptr_t>(ptr);
			std::cout << "Pointer as integer: " << intPtr << std::endl;

			// Convert the integer back to a pointer
			int* ptr2 = reinterpret_cast<int*>(intPtr);
			std::cout << "Dereferenced value: " << *ptr2 << std::endl;

			return 0;
		}
	*/
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
