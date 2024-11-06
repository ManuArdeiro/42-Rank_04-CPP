/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:40:28 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/23 18:58:57 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MutantStack.hpp"

// Constructors
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack default constructor called." << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) :
	std::stack<T>(other)
{
	std::cout << "MutantStack copy constructor called." << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	std::cout << "MutantStack assignment operator called." << std::endl;
    if (this != &other)
	{
        std::stack<T>::operator=(other);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called." << std::endl;
}

// Begin iterator
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	std::cout << "Begin iterator called." << std::endl;
    return this->c.begin();
	/*	In the context this->c refers to the underlying container
		used by MutantStack, which is based on the structure of std::stack.
		In std::stack, the elements are stored in an underlying container
		called c, which is generally a std::deque (double-ended queue) by
		default. This c container is a protected part of std::stack, so it
		can be accessed in a derived class, like MutantStack.*/
}

// End iterator
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	std::cout << "End iterator called." << std::endl;
    return this->c.end();
}

// Const begin iterator
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	std::cout << "Const begin iterator called." << std::endl;
    return this->c.begin();
}

// Const end iterator
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	std::cout << "Const end iterator called." << std::endl;
    return this->c.end();
}

// Reverse begin iterator
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	std::cout << "Reverse begin iterator called." << std::endl;
    return this->c.rbegin();
}

// Reverse end iterator
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	std::cout << "Reverse end iterator called." << std::endl;
    return this->c.rend();
}

// Const reverse begin iterator
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	std::cout << "Const reverse begin iterator called." << std::endl;
    return this->c.rbegin();
}

// Const reverse end iterator
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	std::cout << "Const reverse end iterator called." << std::endl;
    return this->c.rend();
}
