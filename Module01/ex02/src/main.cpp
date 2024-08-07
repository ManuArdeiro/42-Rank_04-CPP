/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:36:51 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/06 13:46:28 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/*	REFERENCES:
		Syntax:		Declared with the & symbol.
		Semantics:	An alias for another variable; must be initialized when
					declared and cannot be changed to refer to another variable
					afterward.
		Usage:		Simpler and safer than pointers, ideal for passing arguments
					to functions and returning values without copying data.
					CANNOT BE NULL!!
		Safety:		Less prone to memory manipulation errors, always points to
					a valid object, and cannot be reassigned.
	POINTERS:
		Syntax:		Declared with the * symbol.
		Semantics:	Stores the memory address of another object. Can be
					reassigned to different objects at any time and can be null.
		Usage:		More flexible than references, necessary for operations
					requiring explicit memory address manipulation. Must be
					explicitly dereferenced.
		Safety:		More prone to errors such as dangling pointers and null
					dereferencing. Requires careful memory management.
	COMPARISON:
		References:	Must be initialized and cannot be reassigned. Safer and
					easier to use when the object must always be present.
					Ideal for function parameters and return values when the
					reference object does not need to change.
		Pointers:	Can be initialized and reassigned at any time. Can be null
					and require careful handling to avoid memory errors. Ideal
					for dynamic data structures where reassignment flexibility
					is needed.	*/
int	main(void)
{
	std::string	string="HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory address of the string variable: " << &string << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	return (0);	
}