/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:17:43 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/31 23:05:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

static bool ft_valid_option(const std::string option) 
{
    return (option == "ADD" || option == "SEARCH" || option == "EXIT"
        || option == "1" || option == "2" || option == "3");
}

static void ft_print_menu(void)
{
    std::cout << "*------------------------------------------*\n"
            "|                                          |\n"
            "|      jolopez-    Phone Book              |\n"
            "|                                          |\n"
            "|  Write the action or the option number   |\n"
            "|                                          |\n"
            "|      (1) ADD - Add a new contact         |\n"
            "|      (2) SEARCH - Display a contact      |\n"
            "|      (3) EXIT - Exit PhoneBook           |\n"
            "|                                          |\n"
            "*------------------------------------------*" << std::endl;
}

/*  The if (cin.eof() == true) condition is used to check if the end of
    the file (EOF) has been reached during the reading of the line with
    getline(cin, option). This kind of check is more relevant when working
    with files than when interacting with user input in the console, or if
    the users are pressing Ctrl+D (on Unix systems) or Ctrl+Z (on Windows
    systems) to indicate the end of the standard input (typical in some
    kind of people). When the end of the file is reached in standard input,
    cin.eof() is set to true.   */

std::string ft_get_option(void)
{
    std::string option;

    while (1)
    {
        std::cout << "phonebook> ";
        getline(std::cin, option);
        if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
        }
        if (!option.empty() && ft_valid_option(option))
            break;
        std::cin.clear();
        std::cout << "Please insert a valid option!" << std::endl;
    }
    return option;
}

int main(void)
{
    PhoneBook phonebook;
    std::string option;

    while (1)
    {
        ft_print_menu();
        option = ft_get_option();
        if (option == "ADD" || option == "1")
            phonebook.addContact();
        else if (option == "SEARCH" || option == "2")
            phonebook.searchContact();
        else if (option == "EXIT" || option == "3")
        {
            std::cout << "Service cost: 5€" << std::endl;
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}