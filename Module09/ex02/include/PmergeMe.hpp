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
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	sortAndMeasure(const std::vector<int> &sequence);
		
	private:
		void	fordJohnsonSort(std::vector<int> &container);
		void	fordJohnsonSort(std::deque<int> &container);
};
