#pragma once

class Bank
{
public:
	Bank(Bank const&) = delete;
	void operator=(Bank const&) = delete;

	static Bank& getInstance();
	void increaseBalance();
	void increaseIncome();

	void setBalance(double balance);
	double getBalance();

	void setIncome(double income);
	double getIncome();

private:
	Bank();
	
	double balance = 0; //needs to be changed
	double income = 1;
};