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

// Static functions
static void	display_contact(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

static std::string	field_format(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}

static std::string	read_str(void)
{
    std::string str;

	while (1)
	{
		getline(std::cin, str);
		if (str.empty())
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << "Please type a valid value!!" << std::endl;
			continue;
		}
		break;
	}
	return str;
}

// Constructor
PhoneBook::PhoneBook() : count(0)
{
}

// Destructor
PhoneBook::~PhoneBook()
{
}

//Methods
void PhoneBook::searchContact(void) const
{
    int         i;
	int         index_nb;
	std::string index_str;

    if (this->count == 0)
    {
        std::cout << "No contacts to show!!" << std::endl << std::endl;
        return ;
    }
    std::cout << "\n|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (i = 0; i < this->count; i++)
    {
    	std::cout << "|";
        std::cout << std::right << std::setw(10) << i + 1 << "|"; 
        std::cout << std::right << std::setw(10) << field_format(this->contacts[i].getFirstName()) << "|"; 
        std::cout << std::right << std::setw(10) << field_format(this->contacts[i].getLastName()) << "|"; 
        std::cout << std::right << std::setw(10) << field_format(this->contacts[i].getNickname()) << "|";
		std::cout << std::endl;
        
    }
    while (1)
    {
        std::cout << std::endl << "Please select a Contact by typing next just its index number: ";
	    getline(std::cin, index_str);
		if (index_str.empty() || index_str.find_first_not_of("01234567") != std::string::npos) 
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl << "PhoneBook accepts only the Contact index." << std::endl;
			continue;
		}
        index_nb = atoi(index_str.c_str());
        if (index_nb > 7)
        {
            std::cout << "Please introduce a valid option or I'll kill you!!" << std::endl;
            std::cout << std::endl;
            continue;
        }
		if (index_nb > count)
        {
            std::cout << "Are you kidding me? Do you know to count...??" << std::endl;
            std::cout << std::endl;
            continue;
        }
        display_contact(this->contacts[index_nb - 1]);
        break;
    }
}

/*	Note: if we write:
	std::cin >> str
	It only reads until the firs space or \n!!	*/
void PhoneBook::addContact(void)
{
    Contact     new_contact;
    std::string str;

	std::cout << "First name:\n";
	new_contact.setFirstName(read_str());
	std::cout << "Last name:\n";
	new_contact.setLastName(read_str());
	std::cout << "Nickname:\n";
	new_contact.setNickName(read_str());


	std::cout << "Phone number:\n";
	while (1)
		{
			str = read_str();
			if (str.find_first_not_of("0123456789") != std::string::npos) 
			{
				std::cout << "Phone number accepts only numbers." << std::endl;
				continue;
			}
			new_contact.setPhoneNumber(str);
			break;
		}

	std::cout << "Darkest Secret:\n";
	new_contact.setDarkestSecret(read_str());

	if (count > CONTACTS - 1)
		this->contacts[count % (count - 1)] = new_contact;
	else
	{
		this->count++;
		this->contacts[count - 1] = new_contact;
	}

    std::cout << std::endl;
	std::cout << "Contact saved!" << std::endl;
    std::cout << std::endl;
}
