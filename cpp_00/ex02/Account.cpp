/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipouliq <kipouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:02:30 by kipouliq          #+#    #+#             */
/*   Updated: 2025/01/13 19:02:54 by kipouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
    Account::_nbAccounts += 1;
    this->_accountIndex = Account::_nbAccounts - 1;
    this->_totalAmount = initial_deposit;
    std::cout << "index:" << this->_accountIndex << ";" << "amount:" << checkAmount() << ";" << "created" << std::endl;
}

Account::~Account(void)
{
    std::cout << "account destroyed" << std::endl;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

void Account::displayAccountsInfos(void)
{
    std::cout << "display account infos" << std::endl;
}

void Account::displayStatus(void) const
{
    std::cout << "display status" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    (void)deposit;
    std::cout << "make deposit" << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    (void)withdrawal;
    std::cout << "make withdrawal" << std::endl;
    return true;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;