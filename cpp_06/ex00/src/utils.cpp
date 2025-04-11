/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:47:26 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/11 19:07:40 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

bool is_char(std::string const & literal)
{
    return literal.length() == 1 && !is_digits(literal);
}

bool is_digits(std::string str)
{
    if (str[0] == '-' || str[0] == '+')
        str.erase(0, 1);
    return str.find_first_not_of("0123456789") == str.npos;
}

bool is_int(std::string str, double decimal)
{
    if (str[0] == '-' || str[0] == '+')
        str.erase(0, 1);
    return decimal == 0;    
}

bool is_printable(int c)
{
    return (c >= 32 && c <= 126);
}

bool test_of_int(long int nb)
{
    return (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max());
}

bool test_of_int_float(long int nb)
{
    return (nb < std::numeric_limits<float>::min() || nb > std::numeric_limits<float>::max());
}

bool test_of_int_double(long int nb)
{
    return (nb < std::numeric_limits<double>::min() || nb > std::numeric_limits<double>::max());
}