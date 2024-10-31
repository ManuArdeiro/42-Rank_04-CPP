/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:09:00 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/29 19:09:17 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

int main(int argc, char** argv)
{
    if (argc < 2)
	{
        std::cerr << "Usage: ./PmergeMe <sequence_of_positive_integers>" << std::endl;
        return 1;
    }

    std::vector<int> sequence;
    for (int i = 1; i < argc; ++i)
	{
        try
		{
            int num = std::stoi(argv[i]);
            if (num < 0) throw std::runtime_error("Error: Negative integers are not allowed.");
            sequence.push_back(num);
        }
		catch (const std::exception& e)
		{
            std::cerr << "Error: Invalid input '" << argv[i] << "'. Only positive integers are allowed." << std::endl;
            return 1;
        }
    }

    PmergeMe sorter;
    sorter.sortAndMeasure(sequence);

    return 0;
}
