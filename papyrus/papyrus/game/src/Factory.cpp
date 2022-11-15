#include "Factory.h"

Factory::Factory(std::string nameIn, int buyPriceIn, int upgradePriceIn, Product productIn, float xIn, float yIn)
	:
	name(nameIn),
	buyPrice(buyPriceIn),
	upgradePrice(upgradePriceIn),
	product(productIn),
	coordinates{ xIn, yIn }
{

}

std::vector<Factory> createFactory()
{
	std::vector<Factory> factories;

	io::CSVReader<7> in("exports.txt");
	in.read_header(io::ignore_extra_column, "name", "buyPrice", "upgradePrice", "productName", "productCost", "x", "y");

	std::string name;
	int buyPrice;
	int upgradePrice;
	std::string productName;
	int productCost;
	float x;
	float y;

	while (in.read_row(name, buyPrice, upgradePrice, productName, productCost, x, y))
	{
		factories.push_back(Factory(name, buyPrice, upgradePrice, Product(productName, productCost), x, y));
	}

	return factories;
}

std::vector<Vector2> getCoordinates(std::vector<Factory> factories)
{
	std::vector<Vector2> coordinates;

	for (int i = 0; i < factories.size(); i++)
	{
		coordinates.push_back({ factories[i].getCoordinates().x, factories[i].getCoordinates().y });
	}

	return coordinates;
}

void Factory::buyFactory()
{
	Bank& bank = Bank::getInstance();

	// Check if factory is owned
	if (this->isOwned == false)
	{
		// Check if you have enough money
		if (bank.getBalance() >= this->getBuyPrice())
		{

			bank.setBalance(bank.getBalance() - this->getBuyPrice());
			this->isOwned = true;

			// Increase the income with the price of the product
			bank.setIncome(this->getProduct().getSellingPrice() - this->getProduct().getProductionCost());
		}
	}
}

void Factory::upgradeFactory()
{
	Bank& bank = Bank::getInstance();

	// Check if factory is owned
	if (this->isOwned == true)
	{
		// Check if you have enough money
		std::cout << "owned ";
		if (bank.getBalance() >= this->getUpgradePrice())
		{
			std::cout << "enough cash ";
			//check tier of the factory
			if (this->getTier() <= 3)
			{
				bank.setBalance(bank.getBalance() - this->getUpgradePrice());

				this->setTier(getTier() + 1);
				this->maxSpeed -= 50;

				bank.setIncome(bank.getIncome() * 1.3);
				this->setUpgradePrice(this->getUpgradePrice() * 1.5);
				std::cout << "upgrade bought";
			}
		}
	}
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