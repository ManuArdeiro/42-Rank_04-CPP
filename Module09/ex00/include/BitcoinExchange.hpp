/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:23:59 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/28 18:56:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>  // For std::strtod

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(const std::string &dbFile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		// Loads the Bitcoin database from a CSV file
		void	loadDatabase(const std::string &dbFile);

		// Processes the input file and outputs the results
		void	processInputFile(const std::string &inputFile) const;

	private:
		std::map<std::string, float> bitcoinPrices;

		// Helper functions
		bool	isValidDate(const std::string &date) const;
		float	getClosestPrice(const std::string &date) const;
		bool	isValidValue(const std::string &valueStr) const;
};
