/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:10:58 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/26 20:04:09 by lekix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, float>                _db;
        std::map<std::string, float>                _file;
        std::map<std::string, float>::iterator      findCheckDate(std::string input);
        bool                                        badInput(std::string input);
        bool                                        checkDateValues(std::string date);
        bool                                        checkFloatValue(std::string float_value);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & other);
        BitcoinExchange const &operator=(BitcoinExchange const & rhs);

        std::map<std::string, float>openParseDataFile(std::string filename, char delim, std::string charset);
        void openParseInputFile(std::string filename);
        void printData(void);

    class FileError : public std::exception
    {
        public:
            const char *what(void) const throw();
    };
};

#endif