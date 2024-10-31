/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:25:25 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/28 19:00:05 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

// Constructors
BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string &dbFile)
{
	std::cout << "BitcoinExchange constructor with dbFile " << dbFile << " called." << std::endl;
    loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) :
	bitcoinPrices(other.bitcoinPrices)
{
	std::cout << "BitcoinExchange copy constructor called." << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange assignment operator called." << std::endl;
    if (this != &other)
	{
        bitcoinPrices = other.bitcoinPrices;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called." << std::endl;
}



// Loads the Bitcoin database from a CSV file
void BitcoinExchange::loadDatabase(const std::string &dbFile)
{
    std::string line;
	std::string date;
	std::string priceStr;
    std::ifstream file(dbFile.c_str()); // Open the file
	
	std::cout << "loadDatabase called." << std::endl;
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    while (std::getline(file, line))
	{
        std::istringstream ss(line);	// This is a stream class to operate on strings.
        if (std::getline(ss, date, ',') && std::getline(ss, priceStr))	// Extracts characters from ss and stores them a comma is found,
																		// and in priceStr unnitl the end of the line.
		{
            float price = std::strtof(priceStr.c_str(), NULL); // Convert string to float
            this->bitcoinPrices[date] = price;	// Insert the date and price into the map
        }
		else
			std::cerr << "Error: bad input format in line: " << line << std::endl;
    }
    file.close();
}



// Validates the date format (YYYY-MM-DD)
bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Expected input: YYYY-MM-DD" << std::endl;
        return false;
    }
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
		{
			std::cerr << "Expected input: YYYY-MM-DD" << std::endl;
			return false;
		}
	}
    return true;
}



// Finds the closest price for a given date
float BitcoinExchange::getClosestPrice(const std::string &date) const
{	
	// It calls the lower_bound function from std::map, which returns an iterator
	// pointing to the first element in bitcoinPrices whose key (in this case, a
	// std::string representing a date) is not less than date.
	// Then --it is used to decrement the iterator, so it points to the previous element
    std::map<std::string, float>::const_iterator it = bitcoinPrices.lower_bound(date);
    if (it == bitcoinPrices.end() || it->first != date)
	{
        if (it != bitcoinPrices.begin())
            --it;
    }
    return it->second;
}



// Validates that the value is a valid float or integer in range
bool BitcoinExchange::isValidValue(const std::string &valueStr) const
{
    try
	{
        float value = std::strtof(valueStr.c_str(), NULL);
        return value >= 0.0f && value <= 1000.0f;
    }
	catch (...)
	{
        return false;
    }
}



// Processes the input file and calculates the Bitcoin value for each date
void BitcoinExchange::processInputFile(const std::string &inputFile) const
{
    std::string line;
    std::string dateStr;
	std::string valueStr;
    std::ifstream file(inputFile.c_str());
	
    if (!file.is_open())
	{
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    while (std::getline(file, line))
	{
        std::istringstream ss(line);
        if (std::getline(ss, dateStr, '|') && std::getline(ss, valueStr))
		{
            dateStr.erase(dateStr.find_last_not_of(" \n\r\t") + 1);	// Trim whitespace
            valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));	// Trim whitespace
            if (!isValidDate(dateStr))
			{
                std::cerr << "Error: bad input => " << dateStr << std::endl;
                continue;
            }
            if (!isValidValue(valueStr))
			{
                std::cerr << "Error: invalid value => " << valueStr << std::endl;
                continue;
            }
            float value = std::strtof(valueStr.c_str(), NULL);
            float rate = getClosestPrice(dateStr);
            std::cout << dateStr << " => " << value << " = " << value * rate << std::endl;
        }
		else
		{
            std::cerr << "Error: bad input format in line: " << line << std::endl;
        }
    }

    file.close();
}
