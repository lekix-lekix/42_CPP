/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:23:13 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/16 10:50:01 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include "PhoneBook.hpp"

bool contains_number(std::string str);
bool contains_only_numbers(std::string str);
int check_field_length(std::string str);
std::string resize_str(std::string str);

#endif