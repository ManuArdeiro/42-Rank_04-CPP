/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:11:27 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/04/24 17:33:25 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream> // cin, cout, endl
# include <string> // string class
# include <cstdlib> // exit() && EXIT_* macros
# include <stdio.h> // clearerr()

class Contact
{
    public:
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setNickName(std::string str);
        void setPhoneNumber(std::string str);
        void setDarkestSecret(std::string str);

        std::string getFirstName(void);
        std::string	getNickname(void);
        std::string	getLastName(void);
        std::string	getPhoneNumber(void);
        std::string	getDarkestSecret(void);

    private:
        std::string	first_name;
        std::string	last_name;
        std::string	nickname;
        std::string	phone_number;
        std::string	darkest_secret;
};

#endif // CONTACT_HPP