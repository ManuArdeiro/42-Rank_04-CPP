/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:32:38 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/23 19:33:03 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    try
	{
        // Initialize BitcoinExchange with the historical Bitcoin database
        BitcoinExchange btcExchange("data.csv");
        
        // Process the input file provided as the command-line argument
        btcExchange.processInputFile(argv[1]);

    } catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
