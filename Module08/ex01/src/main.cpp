/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:10:11 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/23 18:26:29 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Span.hpp"

int main()
{
    try
	{
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << "---------------------------------" << std::endl;

		// Test 2: Trying to add more numbers than allowed
        std::cout << "Test 2: Exceeding the span capacity" << std::endl;
        try
		{
            sp.addNumber(20);  // This should throw an exception
        }
		catch (const std::exception &e)
		{
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
		
		// Test 3: Only one number, span calculation should fail
        std::cout << "Test 3: Only one number, span should fail" << std::endl;
        Span spSingle(1);
        spSingle.addNumber(42);
        try
		{
            std::cout << "Shortest span: " << spSingle.shortestSpan() << std::endl;
        }
		catch (const std::exception &e)
		{
            std::cerr << "Error: " << e.what() << std::endl;
        }
		
        try
		{
            std::cout << "Longest span: " << spSingle.longestSpan() << std::endl;
        }
		catch (const std::exception &e)
		{
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;

		// Test 4: Adding a range of numbers using iterators
        std::cout << "Test 4: Adding range of numbers using iterators" << std::endl;
        std::vector<int> numbers;
        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);
        numbers.push_back(40);
        numbers.push_back(50);
        Span spRange(10);

        spRange.addNumbers(numbers.begin(), numbers.end());
        spRange.addNumber(100);
        spRange.addNumber(200);

        std::cout << "Shortest span: " << spRange.shortestSpan() << std::endl;
        std::cout << "Longest span: " << spRange.longestSpan() << std::endl;
        std::cout << "---------------------------------" << std::endl;

        // Test 5: Large span with 10,000 numbers
        std::cout << "Test 5: Large span with 10,000 numbers" << std::endl;
        Span spLarge(10000);
        for (int i = 0; i < 10000; ++i)
            spLarge.addNumber(i);

        std::cout << "Shortest span (large): " << spLarge.shortestSpan() << std::endl;
        std::cout << "Longest span (large): " << spLarge.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
