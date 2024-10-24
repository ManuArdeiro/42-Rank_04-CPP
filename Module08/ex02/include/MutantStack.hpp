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
