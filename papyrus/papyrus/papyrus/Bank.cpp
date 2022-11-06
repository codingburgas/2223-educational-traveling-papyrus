#include "Bank.h"

Bank::Bank()
{

}

Bank& Bank::getInstance()
{
	static Bank bank;
	return bank;
}

void Bank::increaseBalance()
{
	balance += income;
}

void Bank::increaseIncome()
{
}

void Bank::setBalance(int balance)
{
	this->balance = balance;
}

int Bank::getBalance()
{
	return this->balance;
}

void Bank::setIncome(int income)
{
	this->income = income;
}

int Bank::getIncome()
{
	return this->income;
}
