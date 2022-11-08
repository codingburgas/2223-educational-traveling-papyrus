#include "Product.h"

Product::Product(std::string typeIn, int sellingPriceIn, int productionCostIn)
	:
	type(typeIn),
	sellingPrice(sellingPriceIn),
	productionCost(productionCostIn)
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
