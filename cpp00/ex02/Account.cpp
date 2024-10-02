/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:02:27 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 10:58:29 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <sys/time.h>
#include <iostream>
#include <ctime>

/*
definition and initialization of the static variable
*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
destructor
*/
Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";closed" << std::endl;
}

/*
constructor
*/
static int	get_index()
{
	static int	index = -1;
	index++;
	return (index);
}

Account::Account(void)
{
	this->_amount = 0;
	this->_accountIndex = get_index();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";created" << std::endl;
}

/*
parametrized constructor
*/
Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = get_index();
	_totalAmount += this->_amount;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";created" << std::endl;
}

/*
getters
*/
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

/*
functions
*/
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:"
		<< _totalAmount << ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int orig_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" 
		<< orig_amount << ";deposit:" << deposit << ";amount:" 
		<< this->_amount << ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int	amount_left = this->_amount - withdrawal;
	if (amount_left < 0)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:"
			<< this->_amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	int orig_amount = this->_amount;
	this->_amount = amount_left;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << orig_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl;

	return true;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
		<< this->_amount << ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *const local_now = std::localtime(&now);
	std::cout << "[" << local_now->tm_year + 1900
		<< (local_now->tm_mon < 10 ? "0" : "")
		<< local_now->tm_mon
		<< (local_now->tm_mday < 10 ? "0" : "")
		<< local_now->tm_mday
		<< "_" << (local_now->tm_hour < 10 ? "0" : "")
		<< local_now->tm_hour
		<< (local_now->tm_min < 10 ? "0" : "")
		<< local_now->tm_min
		<< (local_now->tm_sec < 10 ? "0" : "")
		<< local_now->tm_sec << "] " << std::flush;
}
