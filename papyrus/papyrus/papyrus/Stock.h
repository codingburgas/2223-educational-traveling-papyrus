#pragma once
#include <string>

class Stock
{
public:
	Stock(std::string Name, int Price);


	void SelectStock();
	void Export();
	void Produce();

private:
	bool isSelected = false;

};


class Car : public Stock
{
public:
	Car() : Stock(Name, Price)
	{

	}
private:
	std::string Name = "Car";
	int Price;
	int amount = 0;
};

class Food : public Stock
{
public:
	Food() : Stock(Name, Price)
	{

	}
private:
	std::string Name = "Food";
	int Price;
	int amount = 0;
};

class Steel : public Stock
{
public:
	Steel() : Stock(Name, Price)
	{

	}
private:
	std::string Name = "Steel";
	int Price;
	int amount = 0;
};

class Pharmaceutical : public Stock
{
public:
	Pharmaceutical() : Stock(Name, Price)
	{

	}
private:
	std::string Name = "Pharmaceutical";
	int Price;
	int amount = 0;
};

class Machinery : public Stock
{
public:
	Machinery() : Stock(Name, Price)
	{

	}
private:
	std::string Name = "Machinery";
	int Price;
	int amount = 0;
};

class Oil : public Stock
{
public:
	Oil() : Stock(Name, Price)
	{

	}
private:
	std::string Name = "Oil";
	int Price;
	int amount = 0;
};

