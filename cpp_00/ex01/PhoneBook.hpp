/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:35:59 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/13 16:55:17 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "utils.hpp"
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>

class PhoneBook
{
public:
    PhoneBook(void);
    ~PhoneBook(void);
    void add_contact(void);
    void search_contact(void);

private:
    void incContactIdx(void);
    void print_one_contact(int idx);
    void print_all_contacts(void);
    int _contact_idx;
    Contact _contact_arr[8];
};
#endif