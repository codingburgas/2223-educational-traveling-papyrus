#pragma once
#include <string>
#include <raylib.h>
#include "Product.h"
#include "Bank.h"
#include <iostream>

static Vector2 coordinates[30] = {
	{560,560},
	{490,625},
	{510,543},
	{375,653},
	{417,733},
	{230,850},
	{346,833},
	{108,855},
	{346,584},
	{315,529},
	{251,525},
	{152,207},
	{517,389},
	{621,395},
	{550,494},
	{422,570},
	{463,707},
	{621,675},
	{688,560},
	{645,670},
	{681,688},
	{706,744},
	{782,787},
	{810,905},
	{825,731},
	{588,630},
	{711,359},
	{715,450},
	{568,833},
	{497,744}
};

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