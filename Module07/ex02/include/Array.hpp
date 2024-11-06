/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:25:24 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/18 20:17:12 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>  // For std::exception
#include <stdexcept>  // For std::exception

// Template class Array
template <typename T>
class Array
{
	private:
		T				*_elements;	// Pointer to dynamically allocated array
		unsigned int	_size;		// Number of elements in the array

	public:
		// Constructors and destructor
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		// Subscript operator with bounds checking (non-const)
		T &operator[](unsigned int index);

		// Subscript operator with bounds checking (const)
		const T &operator[](unsigned int index) const;

		// Method to return the size of the array
		unsigned int size() const;
};

/*	Templates need to be fully visible to the compiler at the time they are used.
	Unlike non-template functions, where you can separate the declaration in the
	header file (.hpp) and the definition in a source file (.cpp), templates require
	that their code be available in the header file or included directly.

	->	Template compilation: Templates are not instantiated until the compiler 
		encounters a specific instance of them. Therefore, when a template is declared
		in a header file, the template definition must also be available in the same
		file or in an included file (like a .tpp file). If you only include the
		declaration and not the definition in the header, the compiler won’t be able
		to instantiate the template when it is used in other files.

	->	Using the .tpp file: To keep the code organized and avoid cluttering the
		header file, you can separate the template class implementation into a .tpp
		file (or a .cpp file specific for templates). This file is then included at
		the end of the header file, ensuring that both the declaration and definition
		are available to the compiler at the same time.

	->	Why include it at the end: The .tpp file is included at the end of the header
		to ensure that the declarations are present before the definitions. The
		compiler needs to know the interfaces (declarations) before processing the
		implementations (definitions).	*/

#include "../src/Array.tpp"  // Implementation file for template class
