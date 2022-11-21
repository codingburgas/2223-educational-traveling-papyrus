#include "Factory.h"

/**
 * .Creates an instance of Factory
 * 
 * \param nameIn The inputed name
 * \param buyPriceIn The inputed buy price
 * \param upgradePriceIn The inputed upgrade price
 * \param productIn The inputed product
 * \param xIn The inputed x coordinate
 * \param yIn The inputed y coordinete
 */
Factory::Factory(std::string nameIn, int buyPriceIn, int upgradePriceIn, Product productIn, float xIn, float yIn)
	:
	name(nameIn),
	buyPrice(buyPriceIn),
	upgradePrice(upgradePriceIn),
	product(productIn),
	coordinates{ xIn, yIn }
{

}

/**
 * .Creates a vector of factories from a file
 * 
 * \return vector of factories
 */
std::vector<Factory> createFactory()
{
	std::vector<Factory> factories;

	// Read the file with factory info
	io::CSVReader<7> in("../resources/exports.txt");
	in.read_header(io::ignore_extra_column, "name", "buyPrice", "upgradePrice", "productName", "productCost", "x", "y");

	std::string name;
	int buyPrice;
	int upgradePrice;
	std::string productName;
	int productCost;
	float x;
	float y;

	// Push back the factory info into vector
	while (in.read_row(name, buyPrice, upgradePrice, productName, productCost, x, y))
	{
		factories.push_back(Factory(name, buyPrice, upgradePrice, Product(productName, productCost), x, y));
	}

	return factories;
}

/**
 * .Retunrs a vector factories's coordinates
 * 
 * \param factories A vector of objects of type factory
 * 
 * \return vector of coordinates
 */
std::vector<Vector2> getCoordinates(std::vector<Factory> factories)
{
	std::vector<Vector2> coordinates;

	for (int i = 0; i < factories.size(); i++)
	{
		coordinates.push_back({ factories[i].getCoordinates().x, factories[i].getCoordinates().y });
	}

	return coordinates;
}

/**
 * .Buys a selected factory
 * 
 */
void Factory::buyFactory()
{
	Bank& bank = Bank::getInstance();

	// Check if factory is owned
	if (!this->isOwned)
	{
		// Check if you have enough money
		if (bank.getBalance() >= this->buyPrice)
		{
			// Decrease the balance with the buy price of the factory
			bank.setBalance(bank.getBalance() - this->buyPrice);

			// Set ownership of the factory to true
			this->isOwned = true;
			this->tier = 1;

			// Increase the income with the price of the product
			this->income = this->product.getSellingPrice() - this->product.getProductionCost();
			bank.setIncome(+this->income);
		}
	}
}

/**
 * .Upgrades the selecrted factory
 * 
 */
void Factory::upgradeFactory()
{
	Bank& bank = Bank::getInstance();

	// Check if factory is owned
	if (this->isOwned)
	{
		// Check if you have enough money
		if (bank.getBalance() >= this->upgradePrice)
		{
			//check tier of the factory
			if (this->tier <= 3)
			{
				// Decrease the balance with the upgrade price of the factory
				bank.setBalance(bank.getBalance() - this->upgradePrice);

				// Increase the factory tier
				this->tier = this->tier + 1;

				// Deacres the production speed of the factory
				this->maxSpeed = this->maxSpeed - 50;


				// Increase the income
				bank.setIncome(-this->income);
				this->income = this->income * 1.3;
				bank.setIncome(+this->income);

				// Increase the upgrade price
				this->upgradePrice = this->upgradePrice * 1.5;
			}
		}
	}

	// Make factories above tier 4 unpurchasable
	if (this->getTier() > 3)
	{
		this->setUpgradePrice(INT_MAX);
	}
}

/**
 * .Sets the buy price to inputed price
 * 
 * \param buyPrice Inputed price
 */
void Factory::setBuyPrice(int buyPrice)
{
	this->buyPrice = buyPrice;
}

/**
 * .Returns the buy price
 * 
 * \return buy price
 */
int Factory::getBuyPrice()
{
	return this->buyPrice;
}

/**
 * .Sets the upgrade price to inputed price
 * 
 * \param upgradePrice Inputed price
 */
void Factory::setUpgradePrice(int upgradePrice)
{
	this->upgradePrice = upgradePrice;
}

/**
 * .Returns the upgrade price
 * 
 * \return upgrade price
 */
int Factory::getUpgradePrice()
{
	return this->upgradePrice;
}

/**
 * .Sets the name of the factory to inputed name
 * 
 * \param Name Inputed name
 */
void Factory::setName(std::string Name)
{
	this->name = name;
}

/**
 * .Returns the factory's name
 * 
 * \return factory name
 */
std::string Factory::getName()
{
	return this->name;
}

/**
 * .Set the tier to inputed tier
 * 
 * \param tier Inputed tier
 */
void Factory::setTier(int tier)
{
	this->tier = tier;
}

/**
 * .Returns the factory's tier
 * 
 * \return factory's tier
 */
int Factory::getTier()
{
	return this->tier;
}

/**
 * .Sets the product to inputed product
 * 
 * \param product Inputed product
 */
void Factory::setProduct(Product product)
{
	this->product = product;
}

/**
 * .Returns the produced product by the factory
 * 
 * \return produced product
 */
Product Factory::getProduct()
{
	return this->product;
}

/**
 * .Sets the coordinates of the factory
 * 
 * \param x The x coordinate
 * \param y The y coordinate
 */
void Factory::setCoordinates(float x, float y)
{
	this->coordinates.x = x;
	this->coordinates.y = y;
}

/**
 * .Returns the coordinates of the factory
 * 
 * \return factory's coordinates
 */
Vector2 Factory::getCoordinates()
{
	return this->coordinates;
}

/**
 * .Sets factory ownership
 * 
 * \param isOwned new onwership
 */
void Factory::setIsOwned(bool isOwned)
{
	this->isOwned = isOwned;
}

/**
 * .Returs the factory ownership
 * 
 * \return factory's ownership
 */
bool Factory::getIsOwned()
{
	return this->isOwned;
}

/**
 * .Sets the is selected status
 * 
 * \param isSelected new selected status
 */
void Factory::setIsSelected(bool isSelected)
{
	this->isSelected = isSelected;
}

/**
 * .Returns the selected status
 * 
 * \return selected status
 */
bool Factory::getIsSelected()
{
	return this->isSelected;
}

/**
 * .Sets the max production speed to inputed max production speed
 * 
 * \param maxSpeed Inputed max production speed
 */
void Factory::setMaxSpeed(int maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

/**
 * .Returns the max production speed
 * 
 * \return max production speed
 */
int Factory::getMaxSpeed()
{
	return this->maxSpeed;
}

/**
 * .Sets the production speed to inputed production speed
 * 
 * \param productionSpeed Inputed productions speed
 */
void Factory::setProductionSpeed(int productionSpeed)
{
	this->productionSpeed = productionSpeed;
}

/**
 * .Returns the factory's production speed
 * 
 * \return production speed
 */
int Factory::getProductionSpeed()
{
	return this->productionSpeed;
}

/**
 * .Set the factory's income to a inputed income
 * 
 * \param income Inputed income
 */
void Factory::setIncome(int income)
{
	this->income = income;
}

/**
 * .Returns the factory's income
 * 
 * \return factory's income
 */
int Factory::getIncome()
{
	return this->income;
}
