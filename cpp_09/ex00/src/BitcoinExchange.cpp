/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:14:34 by kipouliq          #+#    #+#             */
/*   Updated: 2025/05/22 13:55:15 by kipouliq         ###   ########.fr       */
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
        std::cerr << e.what();
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

bool    BitcoinExchange::isDateValid(int year, int month, int day)
{
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month <= 7)
    {
        if (month % 2 == 0 && day > 30)
            return false;
    }
    else if (month >= 8)
    {
        if (month % 2 != 0 && day > 30)
            return false;
    }
    if (month == 2)
    {
        if (year % 100 == 0 && year % 400 == 0 && day > 29)
            return false;
        else if ((year % 4 == 0 && day > 29) || (year % 4 != 0 && day > 28))
            return false;
    }
    return true;
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
    if (!this->isDateValid(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str())))
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
    std::cout << std::setprecision(2) << std::fixed << std::showpoint;
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

const char *BitcoinExchange::FileError::what(void) const throw()
{
    return ("Error: could not open file.\n");
}

