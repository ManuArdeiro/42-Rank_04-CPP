/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:04:38 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/29 19:05:31 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>

class PmergeMe
{
	public:
		// Constructors
		PmergeMe(int argc, char *argv[]);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		// Methods
		std::vector<int>	sortVector();
		std::deque<int>		sortDeque();

		// Exceptions
		class InvalidException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		// Methods
		std::vector<int>	vectorMergeSort(std::vector<int> temp);gcvt
		std::deque<int>		dequeMergeSort(std::deque<int> temp);
};
