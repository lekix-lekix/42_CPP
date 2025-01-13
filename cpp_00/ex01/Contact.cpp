/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:38:14 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/13 13:57:37 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact(void)
{
    std::cout << "Contact contructor called" << std::endl;
}

Contact::~Contact(void)
{
    std::cout << "Contact destructor called" << std::endl;
}

int Contact::setFirstName(std::string first_name)
{
    if (check_field_length(first_name) == -1)
        return -1;
    if (contains_number(first_name))
    {
        std::cout << "First and last names can not contain any number !" << std::endl;
        return -1;
    }
    else
    {
        this->_first_name = first_name;
        return 0;
    }
}

int Contact::setLastName(std::string last_name)
{
    if (check_field_length(last_name) == -1)
        return -1;
    if (contains_number(last_name))
    {
        std::cout << "First and last names can not contain any number!" << std::endl;
        return -1;
    }
    else
    {
        this->_last_name = last_name;
        return 0;
    }
}

int Contact::setNickName(std::string nickname)
{
    if (check_field_length(nickname) == -1)
        return -1;
    this->_nickname = nickname;
    return 0;
}

int Contact::setDarkestSecret(std::string darkest_secret)
{
    if (check_field_length(darkest_secret) == -1)
        return -1;
    this->_darkest_secret = darkest_secret;
    return 0;
}

int Contact::setPhoneNumber(std::string phone_number)
{
    if (check_field_length(phone_number) == -1)
        return -1;
    if (!contains_only_numbers(phone_number))
    {
        std::cout << "Phone numbers must strictly contain digits!" << std::endl;
        return -1;
    }
    else if (phone_number.length() != 10)
    {
        std::cout << "Phone numbers must strictly be 10 characters long!" << std::endl;
        return -1;
    }
    else
    {
        this->_phone_number = phone_number;
        return (0);
    }
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
