/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:02:30 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/14 17:57:12 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

Account::Account(int initial_deposit)
{
    Account::_nbAccounts += 1;
    this->_accountIndex = Account::_nbAccounts - 1;
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << checkAmount() << ";"
              << "created" << std::endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';'
              << "amount:" << this->_amount << ';'
              << "closed" << std::endl;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ';'
              << "total:" << Account::getTotalAmount() << ';'
              << "deposits:" << Account::getNbDeposits() << ';'
              << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';'
              << "amount:" << this->_amount << ';'
              << "deposits:" << this->_nbDeposits << ';'
              << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';'
              << "p_amount:" << p_amount << ';'
              << "deposit:" << deposit << ';'
              << "amount:" << this->_amount << ';'
              << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';'
              << "p_amount:" << this->_amount << ';';
    if (this->_amount - withdrawal < 0)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    Account::_totalNbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals += 1;
    this->_amount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ';'
              << "amount:" << this->_amount << ';'
              << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    std::cout << '['
              << now->tm_year + 1900
              << std::setw(2) << std::setfill('0') << now->tm_mon + 1
              << std::setw(2) << std::setfill('0') << now->tm_mday
              << '_'
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;