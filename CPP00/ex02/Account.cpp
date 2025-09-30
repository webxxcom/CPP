/* --- Account.cpp --- */

/* ------------------------------------------
author: undefined
date: 9/23/2025
------------------------------------------ */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    std::cout << "[19920104_091532] ";
    //  std::time_t now = std::time(0);
    // std::tm *ltm = std::localtime(&now);
    // char buf[25];
    // std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", ltm);
    // std::cout << buf << ' ';
}

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
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts()
              << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
            : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
    if (initial_deposit < 0)
        return;
    this->_amount += initial_deposit;
    Account::_totalAmount += initial_deposit;
    Account::_nbAccounts += 1;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;
    Account::_nbAccounts -= 1;
    Account::_totalAmount -= this->_amount;
}

void Account::makeDeposit(int deposit)
{
    if (deposit < 0)
        return;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    this->_displayTimestamp();
    std::cout << "index:"<<_accountIndex
              << ";p_amount:"<< this->_amount - deposit
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal <= 0 || this->_amount < withdrawal)
    {
        this->_displayTimestamp();
        std::cout << "index:" << this->_accountIndex
                  << ";p_amount:" << this->_amount
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount + withdrawal
              << ";withdrawal:" << withdrawal << ";"
              << "amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->_amount << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals << std::endl;;
}
