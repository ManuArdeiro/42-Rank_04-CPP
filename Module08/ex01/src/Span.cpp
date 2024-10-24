/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:03:47 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/23 18:30:44 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors and destructor
Span::Span(unsigned int N) :
	_maxSize(N)
{
	std::cout << "Span constructor called with max size." << std::endl;
}

Span::Span(const Span& other) :
	_numbers(other._numbers),
	_maxSize(other._maxSize)
{
	std::cout << "Span copy constructor called." << std::endl;
}

Span& Span::operator=(const Span& other)
{
	std::cout << "Span assignment operator called." << std::endl;
    if (this != &other)
	{
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span()
{
	std::cout << "Span Destructor called." << std::endl;
}

// Methods
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::overflow_error("Span is full, cannot add more numbers.");
    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
	int shortest = 0;
	
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
	shortest = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 1; i < sortedNumbers.size() - 1; ++i)
        shortest = std::min(shortest, sortedNumbers[i + 1] - sortedNumbers[i]);
    return shortest;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");
    int minElement = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElement = *std::max_element(_numbers.begin(), _numbers.end());
    return maxElement - minElement;
}

// Get the current size of the numbers stored
unsigned int Span::size() const {
    return _numbers.size();
}
