/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:24:01 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/10 18:39:50 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void add_contact(PhoneBook *my_phonebook)
{
    int err = -1;
    std::string buffer;
    Contact *curr_contact = my_phonebook->getContact(my_phonebook->getContactIdx());

    std::cout << "ADDING!" << std::endl;
    std::cout << "Please enter a first name mamen :" << std::endl;
    while (err)
    {
        std::getline(std::cin, buffer, '\n');
        err = curr_contact->setFirstName(buffer);
    }
    std::cout << "Now it's time for a last name mate :" << std::endl;
    err = -1;
    while (err)
    {
        std::getline(std::cin, buffer, '\n');
        err = curr_contact->setLastName(buffer);
    }
    std::cout << "IMPRESSIVE ! I guess he/she/it/they has.ve a little funny nickname :" << std::endl;
    ;
    std::getline(std::cin, buffer, '\n');
    curr_contact->setNickName(buffer);
    std::cout << "Ok nice one homie! Give me a phone number right now :" << std::endl;
    err = -1;
    while (err)
    {
        std::getline(std::cin, buffer, '\n');
        err = curr_contact->setPhoneNumber(buffer);
    }
    std::cout << "Well done on outputting NUMBERS. You're doing just fine. Last but not least : give me is secret. I WANT IT :" << std::endl;
    std::getline(std::cin, buffer, '\n');
    curr_contact->setDarkestSecret(buffer);
    std::cout << "Hhuehue I promise I wont tell" << std::endl;
}

int main()
{
    PhoneBook my_phonebook;
    std::string buffer;

    std::cout << "Yoooo ! I'm a freaking PhoneBook ! Whatchu wanna do?\n";
    while (1)
    {
        std::getline(std::cin, buffer, '\n');
        if (buffer.compare("ADD") == 0)
            add_contact(&my_phonebook);
        else if (buffer.compare("SEARCH") == 0)
        {
            std::cout << "SEARCHING !\n";
        }
        else if (buffer.compare("EXIT") == 0)
        {
            std::cout << "Ok ok i'ts over, I get it! EXITING !\n";
            break;
        }
        else
            std::cout << "NO ENTIENDO HOMBRE! Remember usage : only ADD, SEARCH or EXIT ! OK?!" << std::endl;
        std::cout << my_phonebook.getContact(0)->getFirstName() << std::endl;
        std::cout << my_phonebook.getContact(0)->getLastName() << std::endl;
        std::cout << my_phonebook.getContact(0)->getNickName() << std::endl;
        std::cout << my_phonebook.getContact(0)->getPhoneNumber() << std::endl;
        std::cout << my_phonebook.getContact(0)->getDarkestSecret() << std::endl;
    }
}