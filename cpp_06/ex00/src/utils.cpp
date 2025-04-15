/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:47:26 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/15 13:39:11 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

bool is_char(std::string const & literal)
{
    return literal.length() == 1 && !is_digits(literal);
}

bool is_int(std::string const & literal)
{
    if (!literal.length() || literal.find_first_not_of("0123456789-+") != literal.npos)
        return false;

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
    if (decimal != 0 || test_of_int(literal))
        return false;
    return true;
}

bool is_float(std::string const & literal)
{
    if (!literal.length() || literal.find_first_not_of("0123456789f.-+") != literal.npos)
        return false;
        
    std::istringstream        iss(literal);
    std::string               literal_cpy;
    long double               nb;

    literal_cpy = literal;
    if (literal_cpy[0] == '-' || literal_cpy[0] == '+')
        literal_cpy.erase(0, 1);
    if (!isdigit(literal_cpy[0]))
        return false;
    iss >> nb;
    if (test_of_float(nb))
        return false;
    return true;
}

bool is_double(std::string const & literal)
{
    if (!literal.length() || 
        (!is_digits(literal) && literal.find("f") == literal.npos && literal.find(".") == literal.npos))
        return false;
    if (literal.find_first_not_of("0123456789f.-+") != literal.npos)
        return false;

    std::istringstream        iss(literal);
    std::string               literal_cpy;
    long double               nb;

    literal_cpy = literal;
    if (literal_cpy[0] == '-' || literal_cpy[0] == '+')
        literal_cpy.erase(0, 1);
    if (!isdigit(literal_cpy[0]))
        return false;
    iss >> nb;
    if (test_of_double(nb))
        return false;
    return true;
}

bool is_impossible(std::string const & literal)
{
    std::istringstream iss(literal);
    long double        big_nb;

    iss >> big_nb;
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    if (test_literal(literal) == false)
    {
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return true;
    }
    if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "float: +inff\n";    
        std::cout << "double: +inf\n";
        return true;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
        return true;
    }
    if (literal.length() && test_of_float(big_nb))
    {
        if (big_nb < 0)
            std::cout << "float: -inff\n";
        else
            std::cout << "float: +inff\n";
    }
    else
        std::cout << "float: nanf\n";
    if (literal.length() && test_of_double(big_nb))
    {
        if (big_nb < 0)
            std::cout << "double: -inf\n";
        else
            std::cout << "double: +inf\n";
    }
    else
        std::cout << "double: nan\n";            
    return false;
}

bool test_literal(std::string literal)
{
    int digits = 0;
    int non_digits = 0;
    
    if (literal.length() == 0)
        return false;
    if (literal == "+inff" || literal == "-inff" || literal == "+inf" || literal == "-inf")
        return true;
    for (size_t i = 0; i < literal.length(); i++)
    {
        if (!isdigit(literal[i]))
            non_digits++;
        else
            digits++;
    }
    if (non_digits > 3)
        return false;
    if (literal.find(".f") != literal.npos)
        return false;
    if (literal.find(".") != literal.npos && literal.find(".") == literal.length() - 1)
        return false;
    if (literal.find("f") != literal.npos && literal.find("f") != literal.length() - 1)
        return false;
    if (literal.find("-") != literal.npos && literal.find("-") != 0)
        return false;
    if (occurences(literal, '+') > 1 || occurences(literal, '-') > 1)
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

int occurences(std::string str, char c)
{
    int count = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
            count++;
    }
    return (count);
}

bool test_of_int(std::string literal)
{
    std::istringstream iss(literal);
    long int nb;

    iss >> nb;
    return (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max());
}

bool test_of_float(long double nb)
{
    return (nb < -std::numeric_limits<float>::max() || nb > std::numeric_limits<float>::max());
}

bool test_of_double(long double nb)
{
    return (nb < -std::numeric_limits<double>::max() || nb > std::numeric_limits<double>::max());
}