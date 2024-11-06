/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:59:38 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/18 19:03:38 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*	What are templates in C++?

	A template is a generic definition of a function or class that can accept
	one or more type parameters. These type parameters act as "placeholders,"
	allowing the compiler to automatically generate specific versions of
	functions or classes based on the actual data types used in the code.
	There are two main types of templates in C++:
	->	Function templates: Allow you to define functions that work with any data
		type.
	->	Class templates: Allow you to create generic classes that can handle any
		type of data.
		
	What are templates used for in C++?

	Templates are used to write code that can work with any data type without
	duplicating code for each type. This improves code reuse and simplifies
	maintenance.

	Benefits:
	->	Code reuse: Avoid having to write the same function or class for different
		data types.
	->	Generalization: Enables you to create algorithms or data structures that
		are independent of the data types they handle.
	->	Less code duplication: Instead of writing multiple versions of a function
		to handle different types, you can write a single template that works for
		all.
	->	Flexibility: The compiler generates type-specific code based on the types
		used, ensuring efficiency while maintaining type safety.
	
	Conclusion:
	Templates in C++ are fundamental to developing generic libraries like the
	STL (Standard Template Library), which contains data structures and algorithms
	that can be used with any data type.	*/

// Function template for swap: Swaps the values of two arguments
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Function template for min: Returns the smaller of the two arguments
template <typename T>
T min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

// Function template for max: Returns the greater of the two arguments
template <typename T>
T max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}
