#include "Factory.h"


Factory::Factory(std::string name, int buyPrice, int upgradeFactory)
{
}

void Factory::buyFactory()
{
	if (!this->isOwned)
	{
		Bank& bank = Bank::getInstance();
		bank.setIncome(bank.getIncome() - this->buyPrice);
		this->isOwned = true;
	}
	else
	{
		std::cout << "Already owned";
	}
}

void Factory::upgradeFactory()
{

}
