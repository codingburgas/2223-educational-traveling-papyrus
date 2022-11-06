#include "Bank.h"
#include <windows.h>

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
	Sleep(700);
	balance += income;
}

void Bank::increaseIncome()
{
}

void Bank::setBalance(double balance)
{
	this->balance = balance;
}

double Bank::getBalance()
{
	return this->balance;
}

void Bank::setIncome(double income)
{
	this->income = income;
}

double Bank::getIncome()
{
	return this->income;
}
