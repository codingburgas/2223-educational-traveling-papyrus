#include "Product.h"

/**
 * .Creates an instace of Product
 * 
 * \param typeIn The inputed type
 * \param productionCostIn The inputed production cost
 */
Product::Product(std::string typeIn, int productionCostIn)
	:
	type(typeIn),
	productionCost(productionCostIn),
	sellingPrice(2.2 * productionCostIn)
{

}

/**
 * .Sets type to inputed type
 * 
 * \param type Inputed type
 */
void Product::setType(std::string type)
{
	this->type = type;
}

/**
 * .Returns the product type
 * 
 * \return product's type
 */
std::string Product::getType()
{
	return this->type;
}

/**
 * .Sets the selling price to inputed price
 * 
 * \param sellingPrice Inputed price
 */
void Product::setSellingPrice(int sellingPrice)
{
	this->sellingPrice;
}

/**
 * .Returns the selling price
 * 
 * \return selling price
 */
int Product::getSellingPrice()
{
	return this->sellingPrice;
}

/**
 * .Sets the production cost to inputd cost
 * 
 * \param productionCost Inputed price
 */
void Product::setProductionCost(int productionCost)
{
	this->productionCost = productionCost;
}

/**
 * .Returns the production cost
 * 
 * \return production cost
 */
int Product::getProductionCost()
{
	return this->productionCost;
}
