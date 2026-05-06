#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {
	this->_amount = 0;
	_nbAccounts ++;
	_accountIndex = _nbAccounts - 1;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(int initial_deposit) {
	this->_amount = initial_deposit;
	_nbAccounts ++;
	_accountIndex = _nbAccounts - 1;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}


Account::~Account(void) {
	_nbAccounts --;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}


void Account::makeDeposit(int deposit) {
	_nbDeposits ++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposit:" << deposit << ";amount:" << this->_amount + deposit
		<< ";nb_deposits:" << _nbDeposits << std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits ++;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawals:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals ++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals ++;

	return (true);
}

int Account::checkAmount(void) const {
	return (this->_amount);
}

void Account::displayStatus(void) const {
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
		<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

//static

void Account::displayAccountsInfos(void) {
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {

}

int Account::getNbAccounts(void) {
	return(_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

