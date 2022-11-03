#pragma once

class Bank
{
public:
	Bank();

	void increaseBalance();
	void increaseIncome();
	
private:
	double balance = 0; //needs to be changed
	double income = 1;
};