/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:13:20 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/20 19:57:56 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

/*	std::vector<int>::iterator result = easyfind(myVector, 3);
	->	std::vector<int>::iterator: This defines a variable named result of type
		iterator for a vector of integers (std::vector<int>). Iterators are objects
		that allow you to traverse the elements of a container (such as a vector)
		similarly to pointers. The type of the iterator depends on the container type;
		in this case, since myVector is a std::vector<int>, the iterator type is
		std::vector<int>::iterator.
	->	result = easyfind(myVector, 3): This calls the easyfind function, passing
		myVector (a vector of integers) as the first parameter, and 3 as the second
		parameter (the integer we want to find in the vector).
	->	easyfind(myVector, 3) searches for the first occurrence of the number 3
		in myVector. If it finds the number, it returns an iterator that points to
		the location of the number in the vector. If it doesn't find the number,
		it throws an exception. If the search is successful, the returned iterator
		is assigned to the variable result, which can then be used to access the
		found element (similarly to a pointer).	*/
int main()
{
    try
	{
        std::vector<int> myVector;
        myVector.push_back(1);
        myVector.push_back(2);
        myVector.push_back(3);
        myVector.push_back(4);
        myVector.push_back(5);

        // Test with an element that exists
        std::cout << "Searching for 3 in the vector..." << std::endl;
        std::vector<int>::iterator result = easyfind(myVector, 3);
        std::cout << "Found: " << *result << std::endl;

        // Test with an element that does not exist
        std::cout << "Searching for 10 in the vector..." << std::endl;
        result = easyfind(myVector, 10);
        std::cout << "Found: " << *result << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
