/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:00:36 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/17 21:02:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <limits>

/*	Reminder: Static methods do not require an instance of the class to be called.
	This means that you can call a static method directly using the class name,
	without the need to create an object of that class.	
	
	Constructors are private; there will be no instances!
	
	Remember static methods are not associated to an instance, they are called by
	the class.


	
	A static_cast in C++ is a type of cast used for converting one data type to another
	in a safe way at compile time. It performs explicit type conversion and is commonly
	used when we want to:
		Convert between related types (like from float to int).
		Call specific overloaded functions by specifying the exact type.
		Convert pointers or references between types in an inheritance hierarchy (as long
			as they’re compatible).

	Syntax:
		static_cast<new_type>(expression);
	For example:
		int a = 10;
		double b = static_cast<double>(a); -> Convert 'a' to 'double'

	TYPES OF CASTS IN C++
		static_cast:
			Converts between compatible types at compile time.
			Can be used for implicit conversions (like int to double) or between pointers
				within an inheritance hierarchy (from Derived* to Base*).
			It is not as "strong" as other casts because it doesn’t allow casting unrelated
				types, ensuring a degree of safety.
		dynamic_cast:
			Used primarily for casting pointers or references in a polymorphic class hierarchy
				(i.e., when at least one class has a virtual function).
			Performs a runtime check to ensure that the cast is safe. If the cast fails, it
				returns nullptr for pointers or throws an exception for references.
			This makes dynamic_cast suitable for downcasting in inheritance (casting from Base*
				to Derived*).
		const_cast:
			Used to add or remove the const qualifier from a variable.
			Can only be applied to pointers or references.
			This cast is used cautiously because removing const can lead to undefined behavior
				if you modify a value that was initially const.
		reinterpret_cast:
			The most powerful and potentially dangerous cast, used for low-level casting between
				unrelated types.
			Typically used when you need to interpret the bit pattern of a value as a different
				type, like casting a pointer to an int or vice versa.
			This cast does not perform any checks or conversions and is compiler-dependent. Use
				reinterpret_cast with caution as it can lead to undefined behavior.

	Summary of Differences

		static_cast: Safe for conversions between compatible types and within an inheritance hierarchy.
		dynamic_cast: Used in inheritance hierarchies with runtime type-checking; useful for downcasting.
		const_cast: Alters const or volatile qualifiers, useful for removing const.
		reinterpret_cast: Allows for low-level reinterpretation of a type, very risky, and often platform-specific.	*/
		
class ScalarConverter
{
	private:
		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);
		
		static void printChar(char c);
		static void printInt(int n);
		static void printFloat(float f);
		static void printDouble(double d);
		
		static const std::string specialLiterals[];  // String array of special literals
    	static void (*handlers[])(void);  // Static array of function pointers

		static void	handleNan();
		static void	handlePosInf();
		static void	handleNegInf();
		static void	handleNanF();
		static void	handlePosInfF();
		static void	handleNegInfF();
		
		// Private Constructor to avoid instantiation
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void convert(const std::string &literal);
};
