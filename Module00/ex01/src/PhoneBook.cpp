/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:17:50 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/31 23:07:50 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

// Default constructor
PhoneBook::PhoneBook() : count(0) {};

void PhoneBook::addContact(void)
{
    Contact     new_contact;
    std::string str;

	std::cout << "First name: ";
	getline(std::cin, str);
	new_contact.setFirstName(str);
	std::cout << "Last name: ";
	getline(std::cin, str);
	new_contact.setLastName(str);
	std::cout << "Nickname: ";
	getline(std::cin, str);
	new_contact.setNickName(str);
    while (1)
    {
        std::cout << "Phone number: ";
		getline(std::cin, str);
		if (str.empty() || str.find_first_not_of("0123456789") != std::string::npos) 
		{
            std::cin.clear();
            clearerr(stdin);
			std::cout << "Phone number accepts only numbers." << std::endl;
			continue;
		}
		new_contact.setPhoneNumber(str);
		break;
    }
    std::cout << "Darkest Secret: ";
	getline(std::cin, str);
	new_contact.setDarkestSecret(str);
	if (count > CONTACTS - 1)
		this->contacts[count - 1] = new_contact;
	else
	{
		this->count++;
		this->contacts[count - 1] = new_contact;
	}
    std::cout << std::endl;
	std::cout << "Contact saved!" << std::endl;
    std::cout << std::endl;
}

void display_contact(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

std::string field_format(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}

void PhoneBook::searchContact(void)
{
    int         i;
	int         index_nb;
	std::string index_str;

    if (this->count == 0)
    {
        std::cout << "No contacts to show!!" << std::endl;
        return ;
    }
    std::cout << "\n|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (i = 0; i < this->count; i++)
    {
    	std::cout << std::endl;
        std::cout << std::right << std::setw(10) << i + 1 << "|"; 
        std::cout << std::right << std::setw(10) << field_format(this->contacts[i].getFirstName()) << "|"; 
        std::cout << std::right << std::setw(10) << field_format(this->contacts[i].getLastName()) << "|"; 
        std::cout << std::right << std::setw(10) << field_format(this->contacts[i].getNickname()) << "|"; 
        
    }
    while (1)
    {
        std::cout << std::endl << "Please select a Contact by typing next just its index number: ";
	    getline(std::cin, index_str);
		if (index_str.empty() || index_str.find_first_not_of("01234567") != std::string::npos) 
		{
            std::cin.clear();
            clearerr(stdin);
			std::cout << "PhoneBook accepts only the Contact index." << std::endl;
			continue;
		}
        index_nb = atoi(index_str.c_str());
        if (index_nb > 7)
        {
            std::cout << "Please introduce a valid option or I'll kill you!!" << std::endl;
            std::cout << std::endl;
            continue;
        }
        display_contact(this->contacts[index_nb - 1]);
        break;
    }
    
    
}