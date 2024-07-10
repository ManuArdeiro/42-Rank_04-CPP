/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:22:57 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/02/09 13:08:25 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream> // cin, cout, endl
# include <string> // string class
# include <cstdlib> // exit() && EXIT_* macros
# include <stdio.h> // clearerr()
# include <iomanip> // setw()
# include "Contact.hpp"

# define CONTACTS 8

class PhoneBook
{
    public:
        PhoneBook();

        void    addContact();
        void    searchContact();

    private:
        int     count;
		Contact contacts[CONTACTS];
};

#endif // PHONEBOOK_HPP
