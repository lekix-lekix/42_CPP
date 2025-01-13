/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:24:01 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/13 17:23:50 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook my_phonebook;
    std::string buffer;

    while (1)
    {
        std::cout << "Yoooo ! I'm a freaking PhoneBook ! Whatchu wanna do?\n";
        std::getline(std::cin, buffer, '\n');
        if (std::cin.eof())
            exit(EXIT_FAILURE);
        if (buffer.compare("ADD") == 0)
            my_phonebook.add_contact();
        else if (buffer.compare("SEARCH") == 0)
            my_phonebook.search_contact();
        else if (buffer.compare("EXIT") == 0)
        {
            std::cout << "Ok ok i'ts over, I get it! EXITING !\n";
            break;
        }
        else
            std::cout << "NO ENTIENDO HOMBRE! Remember usage : only ADD, SEARCH or EXIT ! OK?!" << std::endl;
    }
}
