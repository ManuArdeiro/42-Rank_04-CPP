/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:17:01 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/10 16:17:04 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream> // cin, cout, endl
#include <string> // string class
#include <cstdlib> // exit() && EXIT_* macros
#include <stdio.h> // clearerr()
#include <iomanip> // setw()
#include "Contact.hpp"

# define CONTACTS 8

class PhoneBook
{
    public:
        // Methods
        void    addContact();
        void    searchContact() const;

        // Constructor
        PhoneBook();

        // Destructor
        ~PhoneBook();

    private:
        // Attributes
        int     count;
		Contact contacts[CONTACTS];
};
