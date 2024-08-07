/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:17:13 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/31 23:01:24 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // cout, endl
#include <cstdlib> // EXIT_ macros

using std::cout;
using std::endl;

std::string string_to_upper(std::string arg)
{
    size_t i = 0;

    while (i < arg.length())
    {
        arg[i] = toupper(arg[i]);
        i++;
    }
    return arg;
}

int main(int argc, char **argv)
{
    int i = 1;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return EXIT_SUCCESS;
    }
    while (i < argc)
    {
        std::cout << string_to_upper(argv[i]) << " ";
        i++;
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}