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
    (void)argv;
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe <sequence_of_positive_integers>" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe result(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

