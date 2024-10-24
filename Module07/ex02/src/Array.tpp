/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:25:40 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/18 20:17:55 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Default constructor: creates an empty array
template <typename T>
Array<T>::Array() :
	_elements(NULL),
	_size(0)
{
	std::cout << "Array Default constructor called (nullptr, 0)." << std::endl;
}

// Constructor with size: creates an array of n elements initialized by default
template <typename T>
Array<T>::Array(unsigned int n) :
	_size(n)
{
	std::cout << "Array Constructor with size " << n << " called." << std::endl;
    _elements = new T[n];
}

// Copy constructor: performs a deep copy of the array
template <typename T>
Array<T>::Array(const Array<T> &other) :
	_size(other._size)
{
	std::cout << "Array Copy constructor called." << std::endl;
    _elements = new T[_size];
    for (unsigned int i = 0; i < _size; ++i)
        this->_elements[i] = other._elements[i];
}

// Assignment operator: performs a deep copy of the array
template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	std::cout << "Array Assignment operator called." << std::endl;
    if (this != &other)
	{
        delete[] _elements;

        _size = other._size;
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
            this->_elements[i] = other._elements[i];
    }
    return *this;
}

// Destructor: deallocates the array memory
template <typename T>
Array<T>::~Array()
{
	std::cout << "Array Destructor called." << std::endl;
    delete[] this->_elements;
}

// Subscript operator with bounds checking (non-const version)
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	std::cout << "Array Non-const subscript operator called." << std::endl;
    if (index >= this->_size)
        throw std::out_of_range("Index out of bounds");
    return this->_elements[index];
}

// Subscript operator with bounds checking (const version)
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	std::cout << "Array Const subscript operator called." << std::endl;
    if (index >= this->_size)
        throw std::out_of_range("Index out of bounds");
    return this->_elements[index];
}

// Function to return the size of the array
template <typename T>
unsigned int Array<T>::size() const
{
	std::cout << "Array Size function called." << std::endl;
    return this->_size;
}
