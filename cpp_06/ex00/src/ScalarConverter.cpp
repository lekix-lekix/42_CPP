/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:19:31 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/14 17:34:03 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include "../include/utils.h"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const & other)
{
    *this = other;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & other) 
{
    (void) other;
    return *this;
}

bool ScalarConverter::convert(std::string const literal)
{
    std::istringstream iss(literal);

    long double big_nb;
    double      decimal = 0;
    std::string f;

    std::cout << "literal = " << literal << "\n" ;
    std::cout << "length = " << literal.length() << "\n";
    
    if (literal.length() == 0)
        return (is_impossible(literal));
    iss >> big_nb >> decimal >> f;
    std::cout << "f = " << f << "\n";
    // if (f.length() > 1 || literal.find(".f") != literal.npos || )
    if (test_literal(literal) == false)
        return (is_impossible(literal));
    std::cout << "big_nb : " << big_nb << "\n";
    // std::cout << "dot : " << dot << "\n";
    std::cout << "decimal : " << decimal << "\n";
    // std::cout << "f : " << f << "\n";

    std::cout << "==========\n";
    
    if (is_char(literal))
    {
        std::cout << "Char found\n";
        char c = literal[0];
        std::cout << "char: " << c << "\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "\n" ;
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return true;
    }
    else if (is_int(literal))
    {
        std::cout << "int found\n";

        int nb = std::atoi(literal.c_str());

        std::cout << "char: ";
        if ((nb >= 0 && nb < 32) || nb > 126)
            std::cout << "Non displayable\n";
        else if (nb < 0 || nb > 255)
            std::cout << "impossible\n";
        else
            std::cout << static_cast<char>(nb) << "\n";
        std::cout << "int: " << nb << "\n";
        std::cout << "float: " << static_cast<float>(nb) << ".0f" << "\n";
        std::cout << "double: " << static_cast<double>(nb) << ".0" << "\n";
        return true;
    }
    else if (is_float(literal))
    {
        std::cout << "float found\n";
        std::istringstream iss(literal);
        float              nb;

        iss >> nb;
        std::cout << "char: ";
        if ((nb >= 0 && nb < 32) || nb > 126)
            std::cout << "Non displayable\n";
        else if (nb < 0 || nb > 255)
            std::cout << "impossible\n";
        else
            std::cout << static_cast<char>(nb) << "\n";
        if (!test_of_int(literal))
            std::cout << "int: " << static_cast<int>(nb) << "\n";
        else
            std::cout << "int: impossible\n";
        std::cout << "float: " << nb << "f" << "\n";
        std::cout << "double: " << static_cast<double>(nb) << "\n";
        return true;
    }
    else if (is_double(literal))
    {
        std::cout << "Double found\n";
        std::istringstream iss(literal);
        double             nb;

        iss >> nb;
        std::cout << "char: ";
        if ((nb >= 0 && nb < 32) || nb > 126)
            std::cout << "Non displayable\n";
        else if (nb < 0 || nb > 255)
            std::cout << "impossible\n";
        else
            std::cout << static_cast<char>(nb) << "\n";
        if (!test_of_int(literal))
            std::cout << "int: " << static_cast<int>(nb) << "\n";
        else
            std::cout << "int: impossible\n";
        std::cout << "float: ";
        if (nb < 0)
            std::cout << "-inff\n";
        else
            std::cout << "+inff\n";
        std::cout << "double: " << static_cast<double>(nb) << "\n";
        return true;
    }
    else
        return (is_impossible(literal));
}