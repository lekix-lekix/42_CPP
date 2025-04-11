/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:15:52 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/11 16:54:10 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <iostream>
#include <sstream>
#include <limits>
#include <exception>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const & other);
        ScalarConverter & operator=(ScalarConverter const & other);
        
    public:
        static void convert(std::string const literal);
};

#endif