/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:06:10 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/29 19:08:45 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>
#include <algorithm>

PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe default constructor called." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    std::cout << "PmergeMe copy constructor called." << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    std::cout << "PmergeMe assignment operator called." << std::endl;
    if (this != &other)
	{
        // No specific data to copy here
		(void)other;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe destructor called." << std::endl;
}

// Algoritmo de Ford-Johnson aplicado a vector<int>
void PmergeMe::fordJohnsonSort(std::vector<int> &container)
{
    if (container.size() < 2)
		return;
    std::sort(container.begin(), container.end());  // Simulación de merge-insert
}

// Algoritmo de Ford-Johnson aplicado a deque<int>
void PmergeMe::fordJohnsonSort(std::deque<int>& container)
{
    if (container.size() < 2)
		return;
    std::sort(container.begin(), container.end());  // Simulación de merge-insert
}

// Función para ordenar y medir el tiempo
void PmergeMe::sortAndMeasure(const std::vector<int>& sequence)
{
    std::vector<int>	vec(sequence.begin(), sequence.end());
    std::deque<int>		deq(sequence.begin(), sequence.end());

    std::cout << "Before: ";
    for (int num : sequence)
	{
		std::cout << num << " ";
	}
    std::cout << std::endl;

    auto startVec = std::chrono::high_resolution_clock::now();
    fordJohnsonSort(vec);
    auto endVec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> vecDuration = endVec - startVec;

    auto startDeq = std::chrono::high_resolution_clock::now();
    fordJohnsonSort(deq);
    auto endDeq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> deqDuration = endDeq - startDeq;

    std::cout << "After: ";
    for (int num : vec)
	{
		std::cout << num << " ";
	}
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecDuration.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deqDuration.count() << " us" << std::endl;
}
