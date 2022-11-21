#include "Bank.h"

/**
 * .Create instance of a bank
 * 
 */
Bank::Bank()
{

}

/**
 * .Creates a static instance of the Bank class
 * 
 * \return static instance of Bank
 */
Bank& Bank::getInstance()
{
	static Bank bank;
	return bank;
}

/**
 * .Increases the balance with a set amount
 * 
 * \param income The amount with which the balance will increase
 */
void Bank::increaseBalance(int income)
{
	this->setBalance(this->getBalance() + income);
}

/**
 * .Set the balance to inputed balance
 * 
 * \param balance Inputed balance
 */
void Bank::setBalance(int balance)
{
	this->balance = balance;
}

/**
 * .Returns the bank's balance
 * 
 * \return bank's balance
 */
int Bank::getBalance()
{
	return this->balance;
}

/**
 * .Sets the income to inputed income
 * 
 * \param income Inputed income
 */
void Bank::setIncome(int income)
{
	this->income += income;
}

/**
 * .Returns the bank's income
 * 
 * \return bank's income
 */
int Bank::getIncome()
{
	return this->income;
}
