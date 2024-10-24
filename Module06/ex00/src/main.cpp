/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:20:34 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/16 00:21:27 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    std::string literal = argv[1];
    ScalarConverter::convert(literal);

    return 0;
}
