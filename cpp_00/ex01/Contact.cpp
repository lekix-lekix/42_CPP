/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:38:14 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/09 18:49:41 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    std::cout << "Contructor called" << std::endl;
}

Contact::~Contact(void)
{
    std::cout << "Destructor called" << std::endl;
}

// void Contact::setFirstName(std::string first_name)
// {
//     this->_first_name = first_name;
// }

// void Contact::setLastName(std::string last_name)
// {
//     this->_last_name = last_name;
// }

void Contact::setName(std::string name_field, std::string content)
{
    if (content.co)   
}

void Contact::setNickName(std::string nickname)
{
    this->_nickname = nickname;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
    this->_darkest_secret = darkest_secret;
}

void Contact::setPhoneNumber(std::string phone_number)
{
    this->_phone_number = phone_number;
}

std::string Contact::getFirstName(void) const
{
    return this->_first_name;
}

std::string Contact::getLastName(void) const
{
    return this->_last_name;
}

std::string Contact::getNickName(void) const
{
    return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const
{
    return this->_phone_number;
}

std::string Contact::getDarkestSecret(void) const
{
    return this->_darkest_secret;
}

// Contact::set_infos(std::string field, std::string content)
// {
// if (field.compare("first_name") == 0)
// this->first_name = content;
// else if (field.compare("last_name") == 0)
// this->last_name = content;
// else if (field.compare("nickname") == 0)
// this->nickname = content;
// else if (field.compare("darkest_secret") == 0)
// this->darkest_secret = content;
// else if (field.compare("phone_number") == 0)
// {
// const char *phone_number = content.c_str();
// int phone_number =
// }
// }