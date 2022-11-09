#pragma once
#include <string>
#include <raylib.h>
#include "Product.h"
#include "Bank.h"
#include <iostream>

static Vector2 coordinates[30] = {
	// Berlin
	{555,560},
	// Frankfurt|
	{485,625},
	// Hamburg
	{505,543},
	// Paris
	{370,653},
	// Lyon
	{412,733},
	// Madrid
	{225,850},
	// Barcelona
	{341,833},
	// Lisbon
	{103,855},
	// London
	{345,584},
	// Manchester
	{310,529},
	// Dublin
	{245,525},
	// Reykjavik
	{147,207},
	// Oslo
	{512,389},
	// Stockholm
	{615,395},
	// Copenhagen
	{545,494},
	// Amsterdam
	{417,570},
	// Bern
	{457,707},
	// Vienna
	{616,675},
	// Warsaw
	{683,560},
	// Bratislava
	{640,670},
	// Budapest
	{676,688},
	// Belgrade
	{701,744},
	// Sofia
	{777,787},
	// Athens
	{805,905},
	// Bucharest
	{820,731},
	// Prague
	{583,630},
	// Helsinki
	{706,359},
	// Riga
	{710,450},
	// Rome|
	{563,833},
	// Milan
	{492,744}
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