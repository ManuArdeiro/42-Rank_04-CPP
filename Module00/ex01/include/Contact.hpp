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