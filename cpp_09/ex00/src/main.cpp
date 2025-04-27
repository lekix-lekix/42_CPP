/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:32:32 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/27 17:37:34 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    try
    {
        BitcoinExchange data;
        if (argc != 2)
            throw BitcoinExchange::FileError();
        data.openParseInputFile(std::string(argv[1]));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    
}