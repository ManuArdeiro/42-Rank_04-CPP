/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accounts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ardeiro <Ardeiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:07:13 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/02/20 21:34:23 by Ardeiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cin, cout, endl
#include <iomanip> // std::setw, setfill
#include <ctime> // time(), localtime()
#include "../include/Account.hpp"

using std::cin;
using std::cout;
using std::endl;

// Init variables

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit)
{
    _nbAccounts++;
    this->_accountIndex = _nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 1;
    this->_nbWithdrawals = 0;
    this->_totalAmount = initial_deposit;
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "created" << endl;
    return ;
}

// Destructor
Account::~Account()
{
    _displayTimestamp();
    cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "closed" << endl;
}

/* Getters */

int Account::_getNbAccounts() {
    return _nbAccounts;
}
int Account::_getTotalAmount() {
    return _totalAmount;
}
int Account::_getNbDeposits() {
    return _totalNbDeposits;
}
int Account::_getNbWithdrawals() {
    return _totalNbWithdrawals;
}



static void _displayTimestamp(void)
{
    time_t      t_stmp_ptr;
    struct tm   *t_stmp;

    std::time(&t_stmp_ptr);
    t_stmp = localtime(&t_stmp_ptr);
    cout << "[" << t_stmp->tm_year + 1900;
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mon + 1;
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mday << "_";
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_hour;
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_min;
    cout << std::setw(2) << std::setfill('0') << t_stmp->tm_sec;
    cout << "] ";
}

static void	_displayAccountsInfos( void ) {
    _displayTimestamp();
    cout << "accounts:" << Account::_getNbAccounts() << ";"
         << "total:" << Account::_getTotalAmount() << ";"
         << "deposits:" << Account::_getNbDeposits() << ";"
         << "withdrawals:" << Account::_getNbWithdrawals() << endl;
}
