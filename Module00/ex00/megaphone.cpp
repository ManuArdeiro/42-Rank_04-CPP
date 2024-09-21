/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:17:13 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 19:18:49 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cout, endl
#include <cstdlib> // EXIT_ macros

std::string string_to_upper(std::string arg)
{
    size_t i = 0;

    while (i < arg.length())
    {
        arg[i] = std::toupper(arg[i]);
        i++;
    }
    return arg;
}

int main(int argc, char **argv)
{
    int 		i = 1;
	std::string	str;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return EXIT_SUCCESS;
    }
    while (i < argc)
    {
		str = argv[i];
        std::cout << string_to_upper(str) << " ";
        i++;
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}