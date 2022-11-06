#pragma once

class Bank
{
public:
	Bank(Bank const&) = delete;
	void operator=(Bank const&) = delete;

	static Bank& getInstance();
	void increaseBalance();
	void increaseIncome();

	void setBalance(int balance);
	int getBalance();

	void setIncome(int income);
	int getIncome();

private:
	Bank();
	
	int balance = 0; //needs to be changed
	int income = 1;
};