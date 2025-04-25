/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:32:32 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/25 16:26:34 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return -1;
    try
    {
        BitcoinExchange data;
        // data.printData();
        data.openParseInputFile(std::string(argv[1]));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}