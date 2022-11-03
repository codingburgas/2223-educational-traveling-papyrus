#include "Bank.h"
#include <windows.h>

Bank::Bank()
{

}

void Bank::increaseBalance()
{
	Sleep(700);
	balance += income;
}

void Bank::increaseIncome()
{
}