/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:09:05 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/16 10:37:50 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool contains_number(std::string str)
{
    int str_len = str.length();
    
    for (int i = 0; i < str_len; i++)
    {
        if (isdigit(str[i]))
            return true;
    }
    return false;
}

bool contains_only_numbers(std::string str)
{
    int str_len = str.length();
    
    for (int i = 0; i < str_len; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

int check_field_length(std::string str)
{
    if (str.length() == 0)
    {
        std::cout << "No empty field por favor!" << std::endl;
        return -1;
    }
    return (0);
}

std::string resize_str(std::string str)
{    
    if (str.length() > 10)
    {
        str.resize(9);
        str.push_back('.');
    }
    return str;
}
