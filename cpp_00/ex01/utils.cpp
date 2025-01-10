/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:09:05 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/10 14:35:33 by kipouliq         ###   ########.fr       */
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
