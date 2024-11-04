/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:13:00 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 12:14:11 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*	
	An exception is a signal that something has gone wrong during the execution
	of a program. In C++, when an exception is thrown, the normal flow of the
	program is interrupted, and control is transferred to an exception handling
	section where the error can be appropriately addressed.

	In C++, exceptions are handled using three main keywords:
		throw:	Used to throw an exception.
		try:	Defines a block of code where an exception might occur.
		catch:	Catches an exception thrown within a try block to handle it.
	
	what() method: The what() method in exceptions returns a message that describes
	the error. This method is overridden in custom exceptions. By calling e.what(),
	we can get a specific message about why the exception was thrown.
*/
int main(void)
{
    try
	{
		std::cout << "\033[1;34m\nCreating a Bureaucrat John with grade 2 -> Bureaucrat john(\"John\", 2);\033[0m" << std::endl;
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;

		std::cout << "\033[1;34m\nIncrementing John's grade -> john.incrementGrade();\033[0m" << std::endl;
        john.incrementGrade(); // Goes to 1
        std::cout << john << std::endl;

        // This should throw an exception because it tries to go below 1
		std::cout << "\033[1;34m\nTrying to increment John's grade -> john.incrementGrade();\033[0m" << std::endl;
        std::cout << "An exception will be thrown, so we are leaving the scope (destructor called)," << std::endl;
        std::cout << "then the exception message is typed, and the last line in this scope is not executed!!" << std::endl;
        john.incrementGrade();

        std::cout << "\033[1;34m\nDecrementing John's grade -> john.decrementGrade();\033[0m" << std::endl;
        john.decrementGrade(); // Goes to 2
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
		std::cout << "\033[1;34m\nCreating a Bureaucrat Mike with grade 149 -> Bureaucrat mike(\"Mike\", 149);\033[0m" << std::endl;
        Bureaucrat mike("Mike", 149);
        std::cout << mike << std::endl;

        mike.decrementGrade(); // Lowers to 150
		std::cout << "\033[1;34m\nDecrementing Mike's grade -> mike.decrementGrade();\033[0m" << std::endl;
        std::cout << mike << std::endl;

        //This should throw an exception because it tries to go above 150
		std::cout << "\033[1;34m\nTrying to increment Mike's grade -> mike.decrementGrade();\033[0m" << std::endl;
        mike.decrementGrade();
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
        // Try to create a Bureaucrat with an invalid grade
		std::cout << "\033[1;34m\nTrying to create a Bureaucrat with an invalid grade -> Bureaucrat invalidBureaucrat(\"Invalid\", 151);\033[0m" << std::endl;
        Bureaucrat invalidBureaucrat("Invalid", 151);
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
        // Try to create a Bureaucrat with an invalid grade
		std::cout << "\033[1;34m\nTrying to create a Bureaucrat with an invalid grade -> Bureaucrat invalidBureaucrat(\"Invalid\", 0);\033[0m" << std::endl;
        Bureaucrat invalidBureaucrat("Invalid", 0);
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
