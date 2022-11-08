#include "Factory.h"


Factory::Factory(std::string nameIn, int buyPriceIn, int upgradePriceIn, Product productIn)
	:
	name(nameIn),
	buyPrice(buyPriceIn),
	upgradePrice(upgradePriceIn),
	product(productIn)
{

}

void Factory::buyFactory()
{
	if (!this->isOwned)
	{
		Bank& bank = Bank::getInstance();
		bank.setBalance(bank.getBalance() - this->buyPrice);
		this->isOwned = true;
		bank.setIncome(product.getSellingPrice() - product.getProductionCost());
	}
	else
	{
		std::cout << "Already owned";
	}
}

void Factory::upgradeFactory()
{

}

//setter and getters

void Factory::setBuyPrice(int buyPrice)
{
	this->buyPrice = buyPrice;
}

int Factory::getBuyPrice()
{
	return this->buyPrice;
}

void Factory::setUpgradePrice(int upgradePrice)
{
	this->upgradePrice = upgradePrice;
}

int Factory::getUpgradePrice()
{
	return this->upgradePrice;
}

void Factory::setName(std::string Name)
{
	this->name = name;
}

std::string Factory::getName()
{
	return this->name;
}

void Factory::setTier(int tier)
{
	this->tier = tier;
}

int Factory::getTier()
{
	return this->tier;
}

void Factory::setProduct(Product product)
{
	this->product = product;
}

Product Factory::getProduct()
{
	return this->product;
}
