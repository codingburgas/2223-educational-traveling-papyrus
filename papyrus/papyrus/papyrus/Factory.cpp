#include "Factory.h"


Factory::Factory(std::string nameIn, int buyPriceIn, int upgradePriceIn, Product productIn, float xIn, float yIn)
	:
	name(nameIn),
	buyPrice(buyPriceIn),
	upgradePrice(upgradePriceIn),
	product(productIn),
	coordinates{xIn, yIn}
{

}

std::vector<Factory> createFactory()
{
	std::vector<Factory> factories;

	io::CSVReader<8> in("exports.txt");
	in.read_header(io::ignore_extra_column, "buyPrice", "upgradePrice", "productName", "productCost", "x", "y");

	std::string name;
	int buyPrice;
	int upgradePrice;
	std::string productName;
	int productCost;
	float x; float y;

	while (in.read_row(name, buyPrice, upgradePrice, productName, productCost, x, y))
	{
		factories.push_back(Factory (name, buyPrice, upgradePrice, Product(productName, 1000, productCost), x, y));
	}
} 


void Factory::buyFactory()
{
	Bank& bank = Bank::getInstance();
	// Check if factory is owned
	if (!this->isOwned)
	{
		// Check if you have enough money
		if (bank.getBalance() >= this->buyPrice)
		{
			bank.setBalance(bank.getBalance() - this->buyPrice);
			this->isOwned = true;

			// Increase the income with the price of the product
			bank.setIncome(product.getSellingPrice() - product.getProductionCost());
		}
		else
		{
			std::cout << "Not enoguh cash";
		}

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

void Factory::setCoordinates(float x, float y)
{
	this->coordinates.x = x;
	this->coordinates.y = y;
}

Vector2 Factory::getCoordinates()
{
	return this->coordinates;
}
