/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:32:20 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/09 18:10:32 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int main()
{
    Contact contact_instance;

    contact_instance.setDarkestSecret("moche");
    std::cout << contact_instance.getDarkestSecret() << std::endl;
    std::cout << "hello la mif" << std::endl;
}