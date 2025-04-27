/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekix <lekix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:14:34 by kipouliq          #+#    #+#             */
/*   Updated: 2025/04/27 17:45:47 by lekix            ###   ########.fr       */
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

bool    BitcoinExchange::badInput(std::string input)
{
    std::cout << "Error: bad input => " << input << "\n";
    return false;
}

bool    BitcoinExchange::checkDateValues(std::string date)
{
    std::string year;
    std::string month;
    std::string day;

    year = date.substr(0, 4);
    if (date.find('-') == date.npos)
        return (this->badInput(date.substr(0, '|')));
    month = date.substr(date.find('-') + 1, 2);
    day = date.substr(date.find_last_of('-') + 1, 2);
    if (atoi(year.c_str()) <= 0 || atoi(month.c_str()) <= 0 || atoi(month.c_str()) > 31 
        || atoi(day.c_str()) <= 0 || atoi(day.c_str()) > 31)
        return this->badInput(date);
    return true;
}

std::map<std::string, float>::iterator BitcoinExchange::findCheckDate(std::string line)
{
    std::map<std::string, float>::iterator it;
    size_t                                 delim_pos;
    std::string                            date;

    delim_pos = line.find('|');
    if (delim_pos == line.npos)
        return this->badInput(line), this->_db.end();
    if (!this->checkDateValues(line.substr(0, line.find('|'))))
        return this->_db.end();
    date = line.substr(0, delim_pos);
    it = this->_db.find(date);
    if (it == this->_db.end())
    {
        it = this->_db.lower_bound(date);
        if (it == this->_db.begin())
            return this->badInput(line), this->_db.end();
        --it;
    }
    return it;
}

bool    BitcoinExchange::checkFloatValue(std::string float_value)
{
    float value;
    
    if (float_value.find_first_not_of("0123456789.-"))
        return this->badInput(float_value);
    value = atof(float_value.c_str());
    if (value < 0)
        return std::cout << "Error: not a positive number.\n", false;
    if (value > 1000)
        return std::cout << "Error: too large a number.\n", false;
    return true;
}

void    BitcoinExchange::openParseInputFile(std::string filename)
{
    std::map<std::string, float>::iterator it;
    std::ifstream                          inputfile;
    std::string                            line;
    std::string                            float_value;

    if (!filename.length())
        throw FileError();
    inputfile.open(filename.c_str());
    if (!inputfile.is_open())
        throw FileError();
    std::getline(inputfile, line, '\n');
    while (std::getline(inputfile, line, '\n'))
    {
        if ((it = this->findCheckDate(line)) == this->_db.end())
            continue;
        float_value = line.substr(line.find('|') + 1);
        if (!checkFloatValue(float_value))
            continue;
        float btc_value = atof(float_value.c_str());
        std::cout << it->first << " => " << btc_value << " = " << (it->second * btc_value) << "\n";
    }
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

