/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:19:31 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/13 17:57:07 by lekix            ###   ########.fr       */
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
        std::cout << "char: " << c << "\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "\n" ;
        std::cout << "double: " << static_cast<double>(c) << "\n";
    }
    else if (is_int(literal))
    {
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
    }
    else if (is_float(literal))
    {
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
        std::cout << "int: " << static_cast<int>(nb) << "\n";
        std::cout << "float: " << nb << "f" << "\n";
        std::cout << "double: " << static_cast<double>(nb) << "\n";
    }
    else if (is_double(literal))
    {
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
        std::cout << "int: " << static_cast<int>(nb) << "\n";
        std::cout << "float: " << nb << "f" << "\n";
        std::cout << "double: " << static_cast<double>(nb) << "\n";
    }
    else
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
    }
        // if (!of)
        //     nb = big_nb;
        // if (of == false && is_printable(nb))
        //     std::cout << "char: " << static_cast<char>(nb) << "\n";
        // else if (of == false && nb >= 0 && nb <= 255)
        //     std::cout << "char: Non displayable\n";
        // else
        //     std::cout << "char: impossible\n";
        // if (!of)
        //     std::cout << "int: " << nb << "\n";
        // else
        //     std::cout << "int: impossible\n";
        // if (test_of_float(big_nb))
        //     std::cout << "float: impossible\n";
        // else if (test_of_int(big_nb) && !test_of_float(big_nb))
        //     std::cout << "float: " << static_cast<float>(big_nb) << ".0f" << "\n";
        // if (test_of_double(big_nb))
        //     std::cout << "double: impossible\n";
        // else
        //     std::cout << "double: " << static_cast<double>(nb) << ".0" << "\n";
    

    
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