#pragma once
#include <string>
#include <raylib.h>
#include "Product.h"
#include "Bank.h"
#include <iostream>
#include <vector>
#include "csv.h"

class Factory
{
public:
	Factory(std::string nameIn, int buyPriceIn, int upgradePriceIn, Product productIn, float xIn, float yIn);

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

	void setCoordinates(float x, float y);
	Vector2 getCoordinates();

	void setIsOwned(bool isOwned);
	bool getIsOwned();

	void setIsSelected(bool isSelected);
	bool getIsSelected();
	
	void setMaxSpeed(int maxSpeed);
	int getMaxSpeed();

	void setProductionSpeed(int productionSpeed);
	int getProductionSpeed();

	void setIncome(int income);
	int getIncome();

private:
	int buyPrice;
	int upgradePrice;

	std::string name;
	int tier = 0;

	bool isOwned = false;
	bool isSelected = false;

	int income = 0;
	int maxSpeed = 300;
	int productionSpeed = maxSpeed;

	Vector2 coordinates;

	Product product;

};

std::vector<Factory> createFactory();
std::vector<Vector2> getCoordinates(std::vector<Factory> factories);