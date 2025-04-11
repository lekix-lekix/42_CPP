/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:19:31 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/11 19:10:04 by kipouliq         ###   ########.fr       */
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

void ScalarConverter::convert(std::string const literal)
{
    std::istringstream iss(literal);

    long int           big_nb;
    // char           dot;
    double         decimal = 0;
    // float           f;

    std::cout << "literal = " << literal << "\n" ;
    
    iss >> big_nb >> decimal;
    if (!iss)
        std::cout << "ERROR\n";
    std::cout << "big_nb : " << big_nb << "\n";
    // std::cout << "dot : " << dot << "\n";
    std::cout << "decimal : " << decimal << "\n";
    // std::cout << "f : " << f << "\n";

    std::cout << "==========\n";
    
    if (is_char(literal))
    {
        char c = literal[0];
        std::cout << "char: ";
        if (c < 32 || c > 126)
            std::cout << "Non displayable\n";
        else
            std::cout << c << "\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "\n" ;
        std::cout << "double: " << static_cast<double>(c) << "\n";
    }
    else if (is_int(literal, decimal))
    {
        int nb;
        bool of = test_of_int(big_nb);
        
        if (!of)
            nb = big_nb;
        if (of == false && is_printable(nb))
            std::cout << "char: " << static_cast<char>(nb) << "\n";
        else
            std::cout << "char: impossible\n";
        if (!of)
            std::cout << "int = " << nb << "\n";
        else
            std::cout << "int = impossible\n";
        if (test_of_float(big_nb))
            std::cout << "float = impossible\n";
        else
            std::cout << "float = " << static_cast<float>(nb) << "\n";
        if (test_of_double(big_nb))
            std::cout << "double = impossible\n";
        else
            std::cout << "double = " << static_cast<double>(nb) << "\n";
    }
    

    
    // if (!iss || !is_digits(literal))
    // {
    //     std::cout << "char: impossible\n";
    //     std::cout << "int: impossible\n";
    // }
    // else if (nb < 32 || nb > 126)
    //     std::cout << "char: Non displayable\n";
    // else
    // {
    //     std::cout << "char: " << static_cast<char>(nb) << "\n";
    //     std::cout << "int: " << nb << "\n";
    // }

    // std::cout << "float: ";
    // if (!iss)
    //     std::cout << "impossible\n";

    // std::cout << "double: ";
    // if (!iss)
    //     std::cout << "impossible\n";
}