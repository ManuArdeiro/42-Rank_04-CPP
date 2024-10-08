/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:17:35 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/10 17:23:38 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact()
{
}

// Destructor
Contact::~Contact()
{
}

//Setters:
void Contact::setFirstName(std::string str)
{
    this->first_name = str;
}

void Contact::setLastName(std::string str)
{
    this->last_name = str;
}

void Contact::setNickName(std::string str)
{
    this->nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
    this->phone_number = str;
}

void Contact::setDarkestSecret(std::string str)
{
    this->darkest_secret = str;
}

//Getters:
std::string Contact::getFirstName(void) const
{
    return this->first_name;
}

std::string Contact::getLastName(void) const
{
    return this->last_name;
}

std::string Contact::getNickname(void) const
{
    return this->nickname;
}

std::string Contact::getPhoneNumber(void) const
{
    return this->phone_number;
}

std::string Contact::getDarkestSecret(void) const
{
    return this->darkest_secret;
}