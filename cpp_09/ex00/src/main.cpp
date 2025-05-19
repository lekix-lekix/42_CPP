/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:32:32 by kipouliq          #+#    #+#             */
/*   Updated: 2025/05/19 14:35:21 by kipouliq         ###   ########.fr       */
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
    }
}