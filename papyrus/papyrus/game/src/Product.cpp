#include "Product.h"

Product::Product(std::string typeIn, int productionCostIn)
	:
	type(typeIn),
	productionCost(productionCostIn),
	sellingPrice(2.2 * productionCostIn)
{

}

void Product::setType(std::string type)
{
	this->type = type;
}

std::string Product::getType()
{
	return this->type;
}

void Product::setSellingPrice(int sellingPrice)
{
	this->sellingPrice;
}

int Product::getSellingPrice()
{
	return this->sellingPrice;
}

void Product::setProductionCost(int productionCost)
{
	this->productionCost = productionCost;
}

int Product::getProductionCost()
{
	return this->productionCost;
}
