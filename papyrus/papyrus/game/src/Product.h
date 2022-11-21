#pragma once
#include <string>

class Product
{
public:
	// Creates an instace of Product
	Product(std::string typeIn, int productionCostIn);

	// Sets type to inputed type
	void setType(std::string type);
	// Returns the product type
	std::string getType();

	// Sets the selling price to inputed price
	void setSellingPrice(int sellingPrice);
	// Returns the selling price
	int getSellingPrice();

	// Sets the production cost to inputd cost
	void setProductionCost(int productionCost);
	// Returns the production cost
	int getProductionCost();

private:
	std::string type;
	int sellingPrice;
	int productionCost;
};