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
	// Creates an instance of Factory
	Factory(std::string nameIn, int buyPriceIn, int upgradePriceIn, Product productIn, float xIn, float yIn);

	// Buys a selected factory
	void buyFactory();
	// Upgrades the selecrted factory
	void upgradeFactory();

	// Sets the buy price to inputed price
	void setBuyPrice(int buyPrice);
	// Returns the buy price
	int getBuyPrice();
	
	// Sets the upgrade price to inputed price
	void setUpgradePrice(int upgradePrice);
	// Returns the upgrade price
	int getUpgradePrice();

	// Sets the name of the factory to inputed name
	void setName(std::string Name);
	// Returns the factory's name
	std::string getName();

	// Set the tier to inputed tier
	void setTier(int tier);
	// Returns the factory's tier
	int getTier();

	// Sets the product to inputed product
	void setProduct(Product product);
	// Returns the produced product by the factory
	Product getProduct();

	// Sets the coordinates of the factory
	void setCoordinates(float x, float y);
	// Returns the coordinates of the factory
	Vector2 getCoordinates();

	// Sets factory ownership
	void setIsOwned(bool isOwned);
	// Returs the factory ownership
	bool getIsOwned();

	// Sets the is selected status
	void setIsSelected(bool isSelected);
	// Returns the selected status
	bool getIsSelected();
	
	// Sets the max production speed to inputed max production speed
	void setMaxSpeed(int maxSpeed);
	// Returns the max production speed
	int getMaxSpeed();

	// Sets the production speed to inputed production speed
	void setProductionSpeed(int productionSpeed);
	// Returns the factory's production speed
	int getProductionSpeed();

	// Set the factory's income to a inputed income
	void setIncome(int income);
	// Returns the factory's income
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

// Creates a vector of factories from a file
std::vector<Factory> createFactory();

// Retunrs a vector factories's coordinates
std::vector<Vector2> getCoordinates(std::vector<Factory> factories);