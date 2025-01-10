/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:32:20 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/10 18:17:25 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "PhoneBook constructor called" << std::endl;
    this->_contact_idx = 0;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook destructor called" << std::endl;
}

void PhoneBook::setIncContactIdx(void)
{
    if (this->_contact_idx < 8)
        this->_contact_idx += 1;
}

int PhoneBook::getContactIdx(void)
{
    return this->_contact_idx;
}

Contact *PhoneBook::getContact(int idx)
{
    return &_contact_arr[idx];
}
