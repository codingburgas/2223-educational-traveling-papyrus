#pragma once

class Bank
{
public:
	Bank(Bank const&) = delete;
	void operator=(Bank const&) = delete;

	// Creates a static instance of the Bank class
	static Bank& getInstance();

	// Increases the balance with a set amount
	void increaseBalance(int income);

	// Set the balance to inputed balance
	void setBalance(int balance);
	// Returns the bank's balance
	int getBalance();

	// Sets the income to inputed income
	void setIncome(int income);
	// Returns the bank's income
	int getIncome();

private:
	// Create instance of a bank
	Bank();

	int balance = 50000; //needs to be changed
	int income = 0;
};