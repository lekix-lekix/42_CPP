/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:47:26 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/13 18:04:06 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

bool is_char(std::string const & literal)
{
    return literal.length() == 1 && !is_digits(literal);
}

bool is_int(std::string const & literal)
{
    std::istringstream iss(literal);
    std::string        literal_cpy;
    long int           nb;
    float              decimal = 0;
    
    literal_cpy = literal;
    if (literal_cpy[0] == '-' || literal_cpy[0] == '+')
        literal_cpy.erase(0, 1);
    if (!isdigit(literal_cpy[0]))
        return false;
    iss >> nb >> decimal;
    if (decimal != 0 || test_of_int(nb))
        return false;
    return true;
}

bool is_float(std::string const & literal)
{
    std::istringstream iss(literal);
    std::string        literal_cpy;
    long double        nb;
    char               f;

    literal_cpy = literal;
    if (literal_cpy[0] == '-' || literal_cpy[0] == '+')
        literal_cpy.erase(0, 1);
    if (!isdigit(literal_cpy[0]))
        return false;
    iss >> nb >> f;
    if (test_of_float(nb) || !f)
        return false;
    return true;
}

bool is_double(std::string const & literal)
{
    std::istringstream iss(literal);
    std::string        literal_cpy;
    long double        nb;
    char               f;

    literal_cpy = literal;
    if (literal_cpy[0] == '-' || literal_cpy[0] == '+')
        literal_cpy.erase(0, 1);
    if (!isdigit(literal_cpy[0]))
        return false;
    iss >> nb >> f;
    if (test_of_double(nb) || f)
        return false;
    return true;
}

bool is_digits(std::string str)
{
    return str.find_first_not_of("0123456789") == str.npos;
}

bool is_printable(int c)
{
    return (c >= 32 && c <= 126);
}

bool test_of_int(long int nb)
{
    return (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max());
}

bool test_of_float(long double nb)
{
    return (nb < std::numeric_limits<float>::min() || nb > std::numeric_limits<float>::max());
}

bool test_of_double(long double nb)
{
    return (nb < std::numeric_limits<double>::min() || nb > std::numeric_limits<double>::max());
}