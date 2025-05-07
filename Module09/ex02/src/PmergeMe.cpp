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
#include <algorithm>

static void insertRemaining(std::vector<int> &sorted, const std::vector<int> &full, size_t pairCount)
{
	for (size_t i = 0; i < pairCount; ++i)
	{
		sorted.push_back(full[i * 2 + 1]);
		std::inplace_merge(sorted.begin(), sorted.end() - 1, sorted.end());
	}
	if (full.size() % 2 != 0)
	{
		sorted.push_back(full.back());
		std::inplace_merge(sorted.begin(), sorted.end() - 1, sorted.end());
	}
}

static void insertRemaining(std::deque<int> &sorted, const std::deque<int> &full, size_t pairCount)
{
	for (size_t i = 0; i < pairCount; ++i)
	{
		sorted.push_back(full[i * 2 + 1]);
		std::inplace_merge(sorted.begin(), sorted.end() - 1, sorted.end());
	}
	if (full.size() % 2 != 0)
	{
		sorted.push_back(full.back());
		std::inplace_merge(sorted.begin(), sorted.end() - 1, sorted.end());
	}
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	(void)src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	(void)rhs;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

std::vector<int> PmergeMe::sort(const std::vector<int> &input) const
{
	std::vector<int> container = input;
	if (container.size() < 2)
		return container;

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
		else
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
	}
	std::sort(pairs.begin(), pairs.end());

	std::vector<int> sorted;
	for (size_t i = 0; i < pairs.size(); ++i)
		sorted.push_back(pairs[i].first);

	insertRemaining(sorted, container, pairs.size());
	return sorted;
}

std::deque<int> PmergeMe::sort(const std::deque<int> &input) const
{
	std::deque<int> container = input;
	if (container.size() < 2)
		return container;

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
		else
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
	}
	std::sort(pairs.begin(), pairs.end());

	std::deque<int> sorted;
	for (size_t i = 0; i < pairs.size(); ++i)
		sorted.push_back(pairs[i].first);

	insertRemaining(sorted, container, pairs.size());
	return sorted;
}