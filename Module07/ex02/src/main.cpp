/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:12:04 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/18 20:15:48 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
	{
        // Create an array of 5 integers
        Array<int>	intArray(5);
        std::cout << "Array size: " << intArray.size() << std::endl;

        // Assign values to the array elements
        for (unsigned int i = 0; i < intArray.size(); ++i)
		{
			std::cout << "Assigning value " << i * 10 << " to element " << i << std::endl;
            intArray[i] = i * 10;
		}

        // Print the array elements
        std::cout << "Array elements: ";
        for (unsigned int i = 0; i < intArray.size(); ++i)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        // Copy the array using copy constructor
        Array<int> copyArray(intArray);
        std::cout << "Copy Array elements: ";
        for (unsigned int i = 0; i < copyArray.size(); ++i)
            std::cout << copyArray[i] << " ";
        std::cout << std::endl;

        // Test assignment operator
        Array<int> assignArray;
        assignArray = intArray;
        std::cout << "Assigned Array elements: ";
        for (unsigned int i = 0; i < assignArray.size(); ++i)
            std::cout << assignArray[i] << " ";
        std::cout << std::endl;

        // Attempt to access out-of-bounds element
        std::cout << "Accessing out-of-bounds element: " << std::endl;
        std::cout << intArray[10] << std::endl;

    }
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
