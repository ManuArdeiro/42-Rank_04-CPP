/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:16:42 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 19:19:37 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream> // cin, cout, endl
#include <string> // string class
#include <cstdlib> // exit() && EXIT_* macros
#include <stdio.h> // clearerr()

class Contact
{
    public:
        // Setters:
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setNickName(std::string str);
        void setPhoneNumber(std::string str);
        void setDarkestSecret(std::string str);

        // Getters:
        std::string getFirstName(void) const;
        std::string	getNickname(void) const;
        std::string	getLastName(void) const;
        std::string	getPhoneNumber(void) const;
        std::string	getDarkestSecret(void) const;

        // Constructor
        Contact();

        // Destructor
        ~Contact();

    private:
        // Attributes
        std::string	first_name;
        std::string	last_name;
        std::string	nickname;
        std::string	phone_number;
        std::string	darkest_secret;
};
