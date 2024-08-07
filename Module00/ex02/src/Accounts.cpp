/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accounts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:07:13 by Ardeiro           #+#    #+#             */
/*   Updated: 2024/07/31 23:09:57 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cin, cout, endl
#include <iomanip> // std::setw, setfill
#include <ctime> // time(), localtime()
#include "Account.hpp"

//	Init variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//	Constructor:
Account::Account(int initial_deposit)
{
    _nbAccounts++;
    this->_accountIndex = _nbAccounts - 1;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "created" << std::endl;
    return ;
}

//	Destructor:
Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "closed" << std::endl;
}

//	Funbctions:

int Account::getNbAccounts() {
    return _nbAccounts;
}
int Account::getTotalAmount() {
    return _totalAmount;
}
int Account::getNbDeposits() {
    return _totalNbDeposits;
}
int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

// We need to remove the "static" keyword
// because: https://stackoverflow.com/questions/15725922/static-function-a-storage-class-may-not-be-specified-here
void Account::_displayTimestamp(void)
{
    time_t      t_stmp_ptr;
    struct tm   *t_stmp;

    std::time(&t_stmp_ptr);
    t_stmp = localtime(&t_stmp_ptr);
    std::cout << "[" << t_stmp->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_sec;
    std::cout << "] ";
}

// We need to remove the "static" keyword
// because: https://stackoverflow.com/questions/15725922/static-function-a-storage-class-may-not-be-specified-here
void	Account::displayAccountsInfos(void) 
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";"
        << "total:" << Account::getTotalAmount() << ";"
        << "deposits:" << Account::getNbDeposits() << ";"
        << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    this->_totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "p_amount:" << this->_amount - deposit << ";"
         << "deposit:" << deposit << ";"
         << "amount:" << this->_amount << ";"
		 << "nb_deposits" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
        << "p_amount:" << _amount << ";"
        << "withdrawal:" << std::flush;
    if (checkAmount() <= withdrawal)
	{
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    this->_totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    std::cout << withdrawal << ";"
    	<< "amount:" << _amount << ";"
        << "nb_deposit:" << _nbDeposits << std::endl;
    return true;
}

int     Account::checkAmount(void) const
{
    return _amount;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
         << "amount:" << this->_amount << ";"
         << "deposits:" << this->_nbDeposits << ";"	 
         << "withdrawals:" << this->_nbWithdrawals << std::endl;
	
}
