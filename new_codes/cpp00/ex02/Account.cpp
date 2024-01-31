#include "Account.hpp"
#include <iostream>
#include <iomanip>

// HEPSININ BAŞINDA BİR DE TIMESTAMP YAZDIRMA FONKSİYONU EKLEYEBİLİRİZ

// initializing static variables

int	Account::_nbAccounts = 0;

int	Account::_totalNbWithdrawals = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalAmount = 0;

// STATIC MEMBER FUNCTIONS

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
	std::cout << std::endl;
}

int	Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now;

	now = std::time(NULL);
	std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}
// CONSTRUCTORS AND DESTRUCTORS

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	
	// printing message
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << "created" << std::endl;
}

Account::Account( void )
{
	_displayTimestamp();
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout <<  "amount:" << this->_amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

// class üzerinde değişiklik yapamıyor olması lazım const sayesinde, sadece bilgilere erişebiliyor
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << (this->_amount - deposit) << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->_amount<< ";";
		std::cout << "withdrawal:refused";
		std::cout << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << (this->_amount + withdrawal) << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbDeposits;
	std::cout << std::endl;
	return (true);
}

int	Account::checkAmount() const
{
	return (this->_amount);
}