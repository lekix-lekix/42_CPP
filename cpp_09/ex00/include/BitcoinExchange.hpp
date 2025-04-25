/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:10:58 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/25 17:46:47 by kipouliq         ###   ########.fr       */
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
        std::map<std::string, float> _db;
        std::map<std::string, float> _file;
        bool                         checkDateValues(std::string);

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