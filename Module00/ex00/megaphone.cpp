/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:24:34 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/04/24 16:31:10 by Ardeiro          ###   ########.fr       */
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
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return EXIT_SUCCESS;
    }
    while (i < argc)
    {
        cout << string_to_upper(argv[i]) << " ";
        i++;
    }
    cout << endl;
    return EXIT_SUCCESS;
}