/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:14:34 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/25 17:58:36 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) 
{
    try
    {
        this->_db = openParseDataFile("./data.csv", ',', "0123456789,-.");
    }
    catch(const std::exception& e)
    {
        throw e;
    }
}

std::map<std::string, float>BitcoinExchange::openParseDataFile(std::string filename, char delim, std::string charset)
{
    std::map<std::string, float> data;
    std::ifstream                datafile;
    std::string                  line;
    
    datafile.open(filename.c_str());
    if (!datafile.is_open())
        throw FileError();
    while (std::getline(datafile, line, '\n'))
    {   
        if (line.find_first_not_of(charset) != line.npos)
            continue;
        std::string date = line.substr(0, line.find(delim));
        std::string value = line.substr(line.find(delim) + 1, line.npos);
        data.insert(std::make_pair(date, atof(value.c_str())));
    }
    return data;
}

bool    BitcoinExchange::checkDateValues(std::string date)
{
    std::string year;
    std::string month;
    std::string day;

    
    year = date.substr(0, date.find('-'));
    month = date.substr(date.find('-') + 1, date.find_last_of('-'));
    std::cout << "last = " << date.find_last_of('-') << "\n";
    // day = date.substr(date.find_last_of('-', 0), date.length());

    // std::cout << year << " " << month << " " << day << "\n";
    std::cout << year << "\n";
    std::cout << month << "\n";
    return true;
}

void    BitcoinExchange::openParseInputFile(std::string filename)
{
    std::map<std::string, float>::iterator it;
    std::ifstream   inputfile;
    std::string     line;
    
    inputfile.open(filename.c_str());
    if (!inputfile.is_open())
        throw FileError();
    while (std::getline(inputfile, line, '\n'))
    {   
        this->checkDateValues(line);
        size_t delim_pos = line.find('|');
        if (delim_pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }
        std::string year = line.substr(0, delim_pos);
        it = this->_db.find(year);
        if (it == this->_db.end())
        {
            it = this->_db.lower_bound(year);
            if (it == this->_db.begin())
            {
                std::cout << "Error: bad input => " << line << "\n";
                continue;
            }
            --it;
            std::cout << it->first << "\n";
        }
        // if (it2 == input_data.end())
        // {
        //     it2 = this->_db.lower_bound(it->first);
        //     std::cout << "lower bound\n";
        // }
        // if (it2 == input_data.end())
        // printf("invalid input \n");
        // std::cout << it2->first << " => " << it2->second << "\n";
    }
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other)
{
    *this = other;
}

BitcoinExchange const & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    this->_db = rhs._db;
    return *this;
}

void BitcoinExchange::printData(void)
{
    std::map<std::string, float>::iterator it;

    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);
    for (it = this->_db.begin(); it != this->_db.end(); it++)
    {
        std::cout << it->first << " : " << it->second << "\n";
    }
}

const char *BitcoinExchange::FileError::what(void) const throw()
{
    return ("Error: could not open file.\n");
}

