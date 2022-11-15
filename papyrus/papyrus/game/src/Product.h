#pragma once
#include <string>

class Product
{
public:
	Product(std::string typeIn, int productionCostIn);

	void setType(std::string type);
	std::string getType();

	void setSellingPrice(int sellingPrice);
	int getSellingPrice();

	void setProductionCost(int productionCost);
	int getProductionCost();

private:
	std::string type;
	int sellingPrice;
	int productionCost;
};