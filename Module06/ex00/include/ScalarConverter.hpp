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
	the class.	*/

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
