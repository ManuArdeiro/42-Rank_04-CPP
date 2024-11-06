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
    this->_elements = new T[_size];
    for (unsigned int i = 0; i < _size; ++i)
        this->_elements[i] = other._elements[i];
}

// Assignment operator: performs a deep copy of the array
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	std::cout << "Array Assignment operator called." << std::endl;
    if (this != &other)
	{
        delete[] this->_elements;

        this->_size = other._size;
        this->_elements = new T[_size];
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
T &Array<T>::operator[](unsigned int index)
{
	std::cout << "Array Non-const subscript operator called." << std::endl;
    if (index >= this->_size)
        throw std::out_of_range("Index out of bounds");
    return this->_elements[index];
}

// Subscript operator with bounds checking (const version)
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
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

/*  The reason for having two [] operators, one const and one non-const, is to
    allow safe and flexible access to the array elements in different contexts
    (constant and non-constant). Each version serves a specific purpose:

    Non-const [] operator (T &operator[](unsigned int index)):
        This operator allows access to and modification of the array elements.
        It’s used when there’s a non-const Array instance, and you want to obtain
        a modifiable reference to an element.

    const [] operator (const T &operator[](unsigned int index) const):
        This operator allows read-only access to the array elements.
        It’s used when there’s an Array instance declared as const, ensuring that
        elements cannot be accidentally modified.

    Main reason for having both versions:
        Safety: It allows differentiation between read and write access. When
            accessing a const instance of Array, only the const [] operator can
            be used, ensuring that the data isn’t modified.
        Flexibility: It allows the [] operator to be used in any context. Even if
            the array is const, you can access its elements without violating
            immutability.

    Example:
        Array<int> arr(5);
        arr[0] = 10;  // Accesses the non-const operator to modify the element

        const Array<int> constArr(5);
        int value = constArr[0];  // Accesses the const operator for read-only access
*/
