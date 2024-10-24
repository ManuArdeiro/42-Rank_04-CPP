/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:25:25 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/23 19:40:31 by jolopez-         ###   ########.fr       */
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

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
	std::cout << "BitcoinExchange constructor with dbFile " << dbFile << " called." << std::endl;
    loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) :
	bitcoinPrices(other.bitcoinPrices)
{
	std::cout << "BitcoinExchange copy constructor called." << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
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
void BitcoinExchange::loadDatabase(const std::string& dbFile)
{
	std::cout << "loadDatabase called." << std::endl;
    std::ifstream file(dbFile.c_str());
    if (!file.is_open())
	{
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line))
	{
        std::istringstream ss(line);
        std::string date;
        std::string priceStr;
        if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
		{
            float price = std::strtof(priceStr.c_str(), NULL);
            bitcoinPrices[date] = price;
        }
    }
    file.close();
}

// Validates the date format (YYYY-MM-DD)
bool BitcoinExchange::isValidDate(const std::string& date) const
{
	std::cout << "isValidDate called." << std::endl;
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Expected input: YYYY-MM-DD" << std::endl;
        return false;
    }
    return true;
}

// Finds the closest price for a given date
float BitcoinExchange::getClosestPrice(const std::string& date) const
{
	std::cout << "getClosestPrice called." << std::endl;
    auto it = bitcoinPrices.lower_bound(date);
    if (it == bitcoinPrices.end() || it->first != date)
	{
        if (it != bitcoinPrices.begin())
            --it;
    }
    return it->second;
}

// Validates that the value is a valid float or integer in range
bool BitcoinExchange::isValidValue(const std::string& valueStr) const
{
	std::cout << "isValidValue called." << std::endl;
    try
	{
        float value = std::stof(valueStr);
        return value >= 0.0f && value <= 1000.0f;
    }
	catch (...)
	{
        return false;
    }
}

// Processes the input file and calculates the Bitcoin value for each date
void BitcoinExchange::processInputFile(const std::string& inputFile) const
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
	{
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
	{
        std::istringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
		{
            // Trim whitespace
            date.erase(date.find_last_not_of(" \n\r\t") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));
            if (!isValidDate(date))
			{
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (!isValidValue(valueStr))
			{
                std::cerr << "Error: invalid value => " << valueStr << std::endl;
                continue;
            }
            float value = std::strtof(valueStr.c_str(), NULL);
            float rate = getClosestPrice(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
		else
		{
            std::cerr << "Error: bad input format in line: " << line << std::endl;
        }
    }

    file.close();
}
