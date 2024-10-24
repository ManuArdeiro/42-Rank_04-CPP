/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:13:00 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 15:49:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


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
        john.incrementGrade();
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
		std::cout << "\033[1;34m\nTrying to decrement Mike's grade -> mike.decrementGrade();\033[0m" << std::endl;
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
	
	try
	{
		std::cout << "\033[1;34m\nCreating a Bureaucrat John with grade 5 -> Bureaucrat john(\"John\", 5);\033[0m" << std::endl;
		Bureaucrat john("John", 5);
		std::cout << john << std::endl;

		std::cout << "\033[1;34m\nCreating a Tax Form with gradeToSign 3 and gradeToExecute 50 -> Form taxForm(\"Tax Form\", 3, 50);\033[0m" << std::endl;
		Form taxForm("Tax Form", 3, 50);
		std::cout << taxForm << std::endl;

		std::cout << "\033[1;34m\nTrying to sign the form with John -> john.signForm(taxForm);\033[0m" << std::endl;
		john.signForm(taxForm);  // Try to sign the form, should throw an exception

		std::cout << "\033[1;34m\nCreating a Bureaucrat Boss with grade 2 -> Bureaucrat boss(\"Boss\", 2);\033[0m" << std::endl;
		Bureaucrat boss("Boss", 2);
		std::cout << boss << std::endl;
		std::cout << "\033[1;34m\nTrying to sign the form with Boss -> boss.signForm(taxForm);\033[0m" << std::endl;
		boss.signForm(taxForm);  // Now the form should be signed

		std::cout << taxForm << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
    return 0;
}
