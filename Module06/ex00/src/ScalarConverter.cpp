/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:12:41 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/17 20:58:30 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// private Constructors to become the class as a static class

ScalarConverter::ScalarConverter()
{
	std::cout << "Error: ScalarConverter is a static class and cannot be instantiated." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Error: ScalarConverter is a static class and cannot be instantiated." << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "Error: ScalarConverter is a static class and cannot be instantiated." << std::endl;
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Error: ScalarConverter is a static class and cannot be instantiated." << std::endl;
}

// Special literals and handlers

void ScalarConverter::handleNan()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void ScalarConverter::handlePosInf()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
}

void ScalarConverter::handleNegInf()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
}

void ScalarConverter::handleNanF()
{
    handleNan();
}

void ScalarConverter::handlePosInfF()
{
    handlePosInf();
}

void ScalarConverter::handleNegInfF()
{
    handleNegInf();
}

// Special literals and handlers definitions

const std::string ScalarConverter::specialLiterals[] = { "nan", "+inf", "-inf", "nanf", "+inff", "-inff" };
void (*ScalarConverter::handlers[])(void) = { handleNan, handlePosInf, handleNegInf, handleNanF, handlePosInfF, handleNegInfF };


// Static function to convert a literal to char, int, float and double

void ScalarConverter::convert(const std::string &literal)
{
    for (int i = 0; i < 6; ++i) 
	{
        if (literal == specialLiterals[i])
		{
            handlers[i]();  // Call the corresponding handler
            return;
        }
    }

    // Manage the rest of the literals (char, int, float, double)
    if (isChar(literal))
	{
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));  // Explicit conversion from char to int
        printFloat(static_cast<float>(c));  // Explicit conversion from char to int
        printDouble(static_cast<double>(c));  // Explicit conversion from char to int
    }
	else if (isInt(literal))
	{
        long	n = std::strtol(literal.c_str(), NULL, 10);
        if (errno == ERANGE || n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
		else
		{
            printInt(n);
            if (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
                std::cout << "char: impossible" << std::endl;
            else
			{
                printChar(static_cast<char>(n));
				printFloat(static_cast<float>(n));
				printDouble(static_cast<double>(n));
			}
        }
    }
	else if (isFloat(literal))
	{
        float f = std::strtof(literal.c_str(), NULL);
        if (errno == ERANGE)
            std::cout << "float: impossible" << std::endl;
		else
		{
            printFloat(f);
            if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max() || std::isnan(f))
                std::cout << "char: impossible" << std::endl;
            else
                printChar(static_cast<char>(f));
            if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max() || std::isnan(f))
                std::cout << "int: impossible" << std::endl;
            else
                printInt(static_cast<int>(f));
            printDouble(static_cast<double>(f));
        }
    }
	else if (isDouble(literal))
	{
        double d = std::strtod(literal.c_str(), NULL);
        if (errno == ERANGE)
            std::cout << "double: impossible" << std::endl;
		else
		{
            printDouble(d);
            if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || std::isnan(d))
                std::cout << "char: impossible" << std::endl;
            else
                printChar(static_cast<char>(d));
            if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
                std::cout << "int: impossible" << std::endl;
            else
                printInt(static_cast<int>(d));
            if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max() || std::isnan(d))
                std::cout << "float: impossible" << std::endl;
            else
                printFloat(static_cast<float>(d));
        }
    }
	else
        std::cout << "Error: Literal not recognized." << std::endl;
}


// CHECKERS

bool ScalarConverter::isChar(const std::string &literal)
{
    return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string &literal)
{
    char *end;
    long val = std::strtol(literal.c_str(), &end, 10);
    return *end == '\0' && errno != ERANGE && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    char *end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    char *end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}

// PRINTERS

void ScalarConverter::printChar(char c)
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
	else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int n)
{
    std::cout << "int: " << n << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
