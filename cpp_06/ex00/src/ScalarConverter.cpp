/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:19:31 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/15 15:22:41 by kipouliq         ###   ########.fr       */
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

    if (test_literal(literal) == false)
        return (is_impossible(literal));
    iss >> big_nb >> decimal >> f;
    
    if (is_char(literal))
    {
        char c = literal[0];
        std::cout << "char: " << c << "\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n" ;
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return true;
    }
    else if (is_int(literal))
    {
        std::istringstream iss(literal);
        int nb = 0;

        std::cout << "char: ";
        iss >> nb;
        if (nb < 0 || nb > 255)
            std::cout << "impossible\n";
        else if ((nb >= 0 && nb < 32) || nb > 126)
            std::cout << "Non displayable\n";
        else
            std::cout << static_cast<char>(nb) << "\n";
        std::cout << "int: " << nb << "\n";
        if ((nb >= -1e6 && nb <= 1e6) && !fmod((float)nb, 1.0))
        {
            std::cout << "float: " << nb << ".0f\n";
            std::cout << "double: " << static_cast<double>(nb) << ".0\n";
        }
        else
        {
            std::cout << "float: " << nb << "f" << "\n";
            std::cout << "double: " << static_cast<double>(nb) << "\n";
        }
        return true;
    }
    else if (is_float(literal))
    {
        std::istringstream iss(literal);
        float              nb;

        iss >> nb;
        std::cout << "char: ";
        if (nb < 0 || nb > 255)
            std::cout << "impossible\n";
        else if ((nb >= 0 && nb < 32) || nb > 126)
            std::cout << "Non displayable\n";
        else
            std::cout << static_cast<char>(nb) << "\n";
        if (!test_of_int(literal))
            std::cout << "int: " << static_cast<int>(nb) << "\n";
        else
            std::cout << "int: impossible\n";
        if ((nb >= -1e6 && nb <= 1e6) && !fmod(nb, 1.0))
        {
            std::cout << "float: " << nb << ".0f\n";
            std::cout << "double: " << static_cast<double>(nb) << ".0\n";
        }
        else
        {
            std::cout << "float: " << nb << "f" << "\n";
            std::cout << "double: " << static_cast<double>(nb) << "\n";
        }
        return true;
    }
    else if (is_double(literal))
    {
        std::istringstream iss(literal);
        double             nb;

        iss >> nb;
        std::cout << "char: ";
        if (nb < 0 || nb > 255)
            std::cout << "impossible\n";
        else if ((nb >= 0 && nb < 32) || nb > 126)
            std::cout << "Non displayable\n";
        else
            std::cout << static_cast<char>(nb) << "\n";
        if (!test_of_int(literal))
            std::cout << "int: " << static_cast<int>(nb) << "\n";
        else
            std::cout << "int: impossible\n";
        std::cout << "float: " << static_cast<float>(nb) << "\n";
        if ((nb >= -1e6 && nb <= 1e6) && !std::fmod(nb, 1.0))
            std::cout << "double: " << nb << ".0\n";
        else
            std::cout << "double: " << nb << "\n";
        return true;
    }
    else
        return (is_impossible(literal));
}