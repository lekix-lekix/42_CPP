/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:24:01 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/16 10:49:47 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
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
            break;
        if (buffer.compare("ADD") == 0)
        {
            if (my_phonebook.add_contact())
                break;
        }
        else if (buffer.compare("SEARCH") == 0)
        {
            if (my_phonebook.search_contact())
                break;
        }
        else if (buffer.compare("EXIT") == 0)
        {
            std::cout << "Ok ok i'ts over, I get it! EXITING !\n";
            break;
        }
        else
            std::cout << "NO ENTIENDO HOMBRE! Remember usage : only ADD, SEARCH or EXIT ! OK?!" << std::endl;
    }
}
