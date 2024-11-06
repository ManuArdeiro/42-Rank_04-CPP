/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:37:07 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/23 18:58:52 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>
#include <iostream>

/*	std::stack is an adapter container in the C++ Standard Library (STL) that
	implements a LIFO (Last-In, First-Out) data structure, meaning that the last
	element added is the first to be removed. This container does not allow
	random access or iteration through its elements, as it is specifically
	designed to manage data in a “stack” mode.

	Characteristics of std::stack

	->	Adapter Container:
        std::stack is a container adapter, meaning that it is not an autonomous
		container but depends on an underlying container to store its elements.
        The default underlying container is std::deque, but it can also be adapted
		to use other containers like std::vector or std::list, as long as they
		provide the necessary functions (push_back, pop_back, back).

    ->	LIFO Operations (Last-In, First-Out):
        In a stack, only the top element (the last one added) can be accessed.
        Elements are added and removed only from the top of the stack, following
		the LIFO principle.

    ->	Simplified Interface:
        std::stack provides a limited interface that includes only the fundamental
		operations needed to manage a stack:
            push(): 	Adds an element to the top of the stack.
            pop():		Removes the top element from the stack.
            top():		Returns a reference to the top element, allowing you to view
						or modify its value.
            empty(): 	Returns true if the stack is empty.
            size(): 	Returns the number of elements in the stack.
        It does not allow iterators or access to elements in the middle of the stack.

    ->	Underlying Container:
        As mentioned, the default underlying container is std::deque because of its
		efficiency for operations on both ends.
        You can specify a different underlying container when declaring std::stack,
		for example:
			std::stack<int, std::vector<int>> myStack;
*/

/*	In C++, iterators (iterator, const_iterator, reverse_iterator, and const_reverse_iterator)
	are classes that allow traversal of the elements in a standard library container
	(such as std::vector, std::list, etc.). Each has specific characteristics that
	affect how container elements can be accessed and manipulated.
	
	->	iterator: This is the basic iterator and allows access and modification of
		the container's elements.

    ->	const_iterator: Similar to iterator, but it only allows read-only access to
		the container's elements, so they cannot be modified.

    ->	reverse_iterator: Allows traversal of the container in reverse order (from
		end to start) and permits modification of the elements.

    ->	const_reverse_iterator: Similar to reverse_iterator, but only allows read-only
		access while traversing in reverse order.
*/

// Templated MutantStack class that extends std::stack and adds iterator functionality
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Type definitions for iterators
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		// Constructors
		MutantStack();
		MutantStack(const MutantStack<T> &other);
		MutantStack<T> &operator=(const MutantStack<T> &other);
		~MutantStack();

		// Iterator methods
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

#include "../src/MutantStack.tpp"
