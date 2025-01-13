/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:32:20 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/13 17:20:55 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "PhoneBook constructor called" << std::endl;
    this->_contact_idx = 0;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook destructor called" << std::endl;
}

void PhoneBook::incContactIdx(void)
{
    if (this->_contact_idx == 7)
        this->_contact_idx = 0;
    else
        this->_contact_idx += 1;
}

void PhoneBook::add_contact(void)
{
    int err = -1;
    std::string buffer;

    std::cout << "ADDING!" << std::endl;
    std::cout << "Please enter a first name mamen :" << std::endl;
    while (err)
    {
        std::getline(std::cin, buffer, '\n');
        if (std::cin.eof())
            exit(EXIT_FAILURE);
        err = this->_contact_arr[this->_contact_idx].setFirstName(buffer);
    }
    std::cout << "Now it's time for a last name mate :" << std::endl;
    err = -1;
    while (err)
    {
        std::getline(std::cin, buffer, '\n');
        if (std::cin.eof())
            exit(EXIT_FAILURE);
        err = this->_contact_arr[this->_contact_idx].setLastName(buffer);
    }
    std::cout << "IMPRESSIVE ! I guess he/she/it/they has.ve a little funny nickname :" << std::endl;
    err = -1;
    while (err)
    {
        std::getline(std::cin, buffer, '\n');
        if (std::cin.eof())
            exit(EXIT_FAILURE);
        err = this->_contact_arr[this->_contact_idx].setNickName(buffer);
    }
    std::cout << "Ok nice one homie! Give me a phone number right now :" << std::endl;
    err = -1;
    while (err)
    {
        std::getline(std::cin, buffer, '\n');
        if (std::cin.eof())
            exit(EXIT_FAILURE);
        err = this->_contact_arr[this->_contact_idx].setPhoneNumber(buffer);
    }
    std::cout << "Well done on outputting NUMBERS. You're doing just fine. Last but not least : give me his/her/their secret. I WANT IT :" << std::endl;
    err = -1;
    while (err)
    {
        std::getline(std::cin, buffer, '\n');
        if (std::cin.eof())
            exit(EXIT_FAILURE);
        err = this->_contact_arr[this->_contact_idx].setDarkestSecret(buffer);
    }
    std::cout << "Hhuehue I promise I wont tell" << std::endl;
    std::cout << "Contact successfully added !" << std::endl;
    std::cout << "Back to main menu !" << std::endl;
    this->incContactIdx();
}

void PhoneBook::print_all_contacts(void)
{
    for (int i = 0; i < 8; i++)
        print_one_contact(i);
}

void PhoneBook::print_one_contact(int idx)
{
    std::cout << std::setw(10) << idx << '|';
    std::cout << std::setw(10) << resize_str(this->_contact_arr[idx].getFirstName()) << '|';
    std::cout << std::setw(10) << resize_str(this->_contact_arr[idx].getLastName()) << '|';
    std::cout << std::setw(10) << resize_str(this->_contact_arr[idx].getNickName()) << std::endl;
}

void PhoneBook::search_contact(void)
{
    int err = -1;
    std::string buffer;

    std::cout << "SEARCHING !" << std::endl;
    this->print_all_contacts();
    while (err)
    {
        std::cout << "Ok hombre, give me your contact index por favor and I'll have a look." << std::endl;
        std::getline(std::cin, buffer, '\n');
        if (std::cin.eof())
            exit(EXIT_FAILURE);
        if (buffer.length() > 1)
            std::cout << "Index can only be one character long ! YOU FOOL!" << std::endl;
        else if (!contains_only_numbers(buffer))
            std::cout << "Index can only contain number ! You FOOL !" << std::endl;
        else if (atoi(buffer.c_str()) > 7)
            std::cout << "Indexes range is 0-7 (included) ! YOU FOOL!" << std::endl;
        else
            err = 0;
    }
    this->print_one_contact(atoi(buffer.c_str()));
    std::cout << "Back to main menu !" << std::endl;
}