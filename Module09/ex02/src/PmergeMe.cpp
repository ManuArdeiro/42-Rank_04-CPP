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
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>

// UTILS

static bool ft_contains(const std::vector<int> &vecObj, const int &el)
{
    std::vector<int>::const_iterator it = std::find(vecObj.begin(), vecObj.end(), el);
    return it != vecObj.end();
}

static void ft_display(const std::vector<int> &container)
{
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// CONSTRUCTORS

PmergeMe::PmergeMe(int argc, char *argv[])
{
    std::vector<int>	orderedVector;
    std::deque<int>		orderedDeque;

    for (int i = 1; i < argc; ++i)
    {
        if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
            throw InvalidException();
        int value = std::atoi(argv[i]);
        //  Check if elements already exists:
        if (ft_contains(this->_vector, value))
            throw InvalidException();
        // Add element:
        _vector.push_back(value);
        _deque.push_back(value);
    }

    std::cout << "Before: ";
    ft_display(this->_vector);

    clock_t start = clock();
    orderedVector = this->sortVector();
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "After:  ";
    ft_display(orderedVector);

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector (Ford-Johnson): " << time << std::endl;

    start = clock();
    orderedDeque = this->sortDeque();
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque (Ford-Johnson): " << time << std::endl;

    start = clock();
    std::sort(this->_vector.begin(), this->_vector.end());
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector (sort): " << time << std::endl;

    start = clock();
    std::sort(this->_deque.begin(), this->_deque.end());
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque (sort): " << time << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    std::cout << "PmergeMe copy constructor called." << std::endl;
    (void)other;
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

// METHODS

std::vector<int> PmergeMe::vectorMergeSort(std::vector<int> temp)
{
    if (temp.size() <= 1)
        return temp;

    int mid = temp.size() / 2;
    std::vector<int>    left(temp.begin(), temp.begin() + mid);
    std::vector<int>    right(temp.begin() + mid, temp.end());

    left = vectorMergeSort(left);
    right = vectorMergeSort(right);

    unsigned i = 0;
    unsigned j = 0;
    unsigned k = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            temp[k] = left[i];
            i++;
        }
        else
        {
            temp[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size())
    {
        temp[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size())
    {
        temp[k] = right[j];
        j++;
        k++;
    }

    return temp;
}

std::deque<int> PmergeMe::dequeMergeSort(std::deque<int> temp)
{
    if (temp.size() <= 1)
        return temp;

    int mid = temp.size() / 2;
    std::deque<int> left(temp.begin(), temp.begin() + mid);
    std::deque<int> right(temp.begin() + mid, temp.begin() + temp.size());

    left = dequeMergeSort(left);
    right = dequeMergeSort(right);

    unsigned i = 0;
    unsigned j = 0;
    unsigned k = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            temp[k] = left[i];
            i++;
        }
        else
        {
            temp[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size())
    {
        temp[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size())
    {
        temp[k] = right[j];
        j++;
        k++;
    }

    return temp;
}

std::vector<int>    PmergeMe::sortVector()
{
    std::vector<int> orderedVector = vectorMergeSort(this->_vector);

    return orderedVector;
}

std::deque<int>     PmergeMe::sortDeque()
{
    std::deque<int> orderedDeque = dequeMergeSort(this->_deque);

    return orderedDeque;
}

const char *PmergeMe::InvalidException::what() const throw()
{
    return "Error: invalid input";
}