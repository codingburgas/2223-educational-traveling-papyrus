#include "Bank.h"

Bank::Bank()
{

}

// Create a static instace of bank
Bank& Bank::getInstance()
{
	static Bank bank;
	return bank;
}

// Increase balance with income
void Bank::increaseBalance()
{
	balance += income;
}

// Increase the income with set amount
void Bank::increaseIncome(int incomeIn)
{
	income += incomeIn;
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
