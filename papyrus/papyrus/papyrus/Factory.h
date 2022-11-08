#pragma once
#include <string>
#include "Product.h"
#include "Bank.h"
#include <iostream>

class Factory
{
public:
	Factory(std::string nameIn, int buyPriceIn, int upgradePriceIn, Product productIn);

	void buyFactory();
	void upgradeFactory();

	void setBuyPrice(int buyPrice);
	int getBuyPrice();

	void setUpgradePrice(int upgradePrice);
	int getUpgradePrice();

	void setName(std::string Name);
	std::string getName();

	void setTier(int tier);
	int getTier();

	void setProduct(Product product);
	Product getProduct();

private:
	int buyPrice;
	int upgradePrice;

	std::string name;
	int tier = 0;
	bool isOwned = false;

	Product product;
};

static Factory berlin("berlin", 1000, 100, car);