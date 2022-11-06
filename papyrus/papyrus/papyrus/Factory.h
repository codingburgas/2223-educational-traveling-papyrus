#pragma once
#include <string>
#include "Product.h"
#include "Bank.h"
#include <iostream>

class Factory
{
public:
	Factory(std::string name,int buyPrice, int upgradeFactory);

	void buyFactory();
	void upgradeFactory();

private:
	int buyPrice;
	int upgradePrice;

	std::string name;
	std::string location;
	int tier = 0;
	bool isOwned = false;

	Product product;
};