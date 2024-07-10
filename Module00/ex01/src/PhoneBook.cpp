/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:23:19 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/02/11 17:27:30 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

using std::cin;
using std::cout;
using std::endl;

// Default constructor
PhoneBook::PhoneBook() : count(0) {};

void PhoneBook::addContact(void)
{
    Contact     new_contact;
    std::string str;

	cout << "First name: ";
	getline(cin, str);
	new_contact.setFirstName(str);
	cout << "Last name: ";
	getline(cin, str);
	new_contact.setLastName(str);
	cout << "Nickname: ";
	getline(cin, str);
	new_contact.setNickName(str);
    while (1)
    {
        cout << "Phone number: ";
		getline(cin, str);
		if (str.empty() || str.find_first_not_of("0123456789") != std::string::npos) 
		{
            cin.clear();
            clearerr(stdin);
			cout << "Phone number accepts only numbers." << endl;
			continue;
		}
		new_contact.setPhoneNumber(str);
		break;
    }
    cout << "Darkest Secret: ";
	getline(cin, str);
	new_contact.setDarkestSecret(str);
	if (count > CONTACTS - 1)
		this->contacts[count - 1] = new_contact;
	else
	{
		this->count++;
		this->contacts[count - 1] = new_contact;
	}
    cout << endl;
	cout << "Contact saved!" << endl;
    cout << endl;
}

void display_contact(Contact contact)
{
	cout << endl;
	cout << "First name: " << contact.getFirstName() << endl;
	cout << "Last name: " << contact.getLastName() << endl;
	cout << "Nickname: " << contact.getNickname() << endl;
	cout << "Phone number: " << contact.getPhoneNumber() << endl;
	cout << "Darkest secret: " << contact.getDarkestSecret() << endl;
	cout << endl;
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
        cout << "No contacts to show!!" << endl;
        return ;
    }
    cout << "\n|     Index|First Name| Last Name|  Nickname|" << endl;
    for (i = 0; i < this->count; i++)
    {
    	cout << endl;
        cout << std::right << std::setw(10) << i + 1 << "|"; 
        cout << std::right << std::setw(10) << field_format(this->contacts[i].getFirstName()) << "|"; 
        cout << std::right << std::setw(10) << field_format(this->contacts[i].getLastName()) << "|"; 
        cout << std::right << std::setw(10) << field_format(this->contacts[i].getNickname()) << "|"; 
        
    }
    while (1)
    {
        cout << endl << "Please select a Contact by typing next just its index number: ";
	    getline(cin, index_str);
		if (index_str.empty() || index_str.find_first_not_of("01234567") != std::string::npos) 
		{
            cin.clear();
            clearerr(stdin);
			cout << "PhoneBook accepts only the Contact index." << endl;
			continue;
		}
        index_nb = atoi(index_str.c_str());
        if (index_nb > 7)
        {
            cout << "Please introduce a valid option or I'll kill you!!" << endl;
            cout <<endl;
            continue;
        }
        display_contact(this->contacts[index_nb - 1]);
        break;
    }
    
    
}