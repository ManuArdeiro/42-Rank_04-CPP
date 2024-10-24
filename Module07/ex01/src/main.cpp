/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:09:50 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/18 19:23:37 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// 	A sample function to apply to each element in the array (it could be 2 different
//	functions instead a template function)
template <typename T>
void printElement(T const &elem)
{
    std::cout << elem << std::endl;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"one", "two", "three", "four", "five"};

	//	We need to use an explicit reference to the template to tell the compiler
	//	which version to use.
    std::cout << "Iterating over intArray:" << std::endl;
    ::iter(intArray, 5, printElement<int>);

    std::cout << "\nIterating over strArray:" << std::endl;
    ::iter(strArray, 5, printElement<std::string>);

    return 0;
}
