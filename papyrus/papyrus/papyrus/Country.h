#pragma once
#include <string>
#include <raylib.h>
#include <vector>
#include "Factory.h"


class Country
{
public:
	Country(std::string name, bool inEU, std::string currency, std::vector<Factory> factories);

private:
	std::string name;
	bool isEU;
	std::string currency;
};

Country Germany("Germany", true, "euro", { {"Berlin", 10000, 7000}, {"Frankfurt", 9000, 7000}});

/*
class France : public Country
{
public:
	France() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "France";
	Image sprite;
	std::vector<std::string> offices{ "Paris", "Lyon" };
	std::vector<std::string> exports{ "car", "pharmaceutical"};
};

class Spain : public Country
{
public:
	Spain() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Spain";
	Image sprite;
	std::vector<std::string> offices{ "Madrid", "Barcelona" };
	std::vector<std::string> exports{ "food", "car" };
};

class Portugal : public Country
{
public:
	Portugal() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Portugal";
	Image sprite;
	std::vector<std::string> offices{ "Lisbon" };
	std::vector<std::string> exports{ "car" };
};

class UK : public Country
{
public:
	UK() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "UK";
	Image sprite;
	std::vector<std::string> offices{ "London", "Manchester" };
	std::vector<std::string> exports{ "car", "machinery" };
};

class Ireland : public Country
{
public:
	Ireland() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Ireland";
	Image sprite;
	std::vector<std::string> offices{ "Dublin" };
	std::vector<std::string> exports{ "machinery" };
};

class Iceland : public Country
{
public:
	Iceland() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Iceland";
	Image sprite;
	std::vector<std::string> offices{ "Reykjavik" };
	std::vector<std::string> exports{ "fish" };
};

class Norway : public Country
{
public:
	Norway() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Norway";
	Image sprite;
	std::vector<std::string> offices{ "Oslo" };
	std::vector<std::string> exports{ "oil" };
};

class Sweden : public Country
{
public:
	Sweden() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Sweden";
	Image sprite;
	std::vector<std::string> offices{ "stockholm" };
	std::vector<std::string> exports{ "car" };
};

class Denmark : public Country
{
public:
	Denmark() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Denmark";
	Image sprite;
	std::vector<std::string> offices{ "Copnehagen" };
	std::vector<std::string> exports{ "food" };
};

class Benelux : public Country
{
public:
	Benelux() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Benelux";
	Image sprite;
	std::vector<std::string> offices{ "Amsterdam" };
	std::vector<std::string> exports{ "car" };
};

class Swiss : public Country
{
public:
	Swiss() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Swiss";
	Image sprite;
	std::vector<std::string> offices{ "Bern" };
	std::vector<std::string> exports{ "machinery" };
};

class Austria : public Country
{
public:
	Austria() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Austria";
	Image sprite;
	std::vector<std::string> offices{ "Vienna" };
	std::vector<std::string> exports{ "machinery" };
};

class Poland : public Country
{
public:
	Poland() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Poland";
	Image sprite;
	std::vector<std::string> offices{ "Warsaw" };
	std::vector<std::string> exports{ "car" };
};

class Slovakia : public Country
{
public:
	Slovakia() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Slovakia";
	Image sprite;
	std::vector<std::string> offices{ "Bratislava" };
	std::vector<std::string> exports{ "car" };
};

class Hungary : public Country
{
public:
	Hungary() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Hungary";
	Image sprite;
	std::vector<std::string> offices{ "Budapest" };
	std::vector<std::string> exports{ "car" };
};

class Serbia : public Country
{
public:
	Serbia() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Serbia";
	Image sprite;
	std::vector<std::string> offices{ "Belgrade" };
	std::vector<std::string> exports{ "car" };
};

class Bulgaria : public Country
{
public:
	Bulgaria() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Bulgaria";
	Image sprite;
	std::vector<std::string> offices{ "Sofia" };
	std::vector<std::string> exports{ "machinery" };
};

class Greece : public Country
{
public:
	Greece() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Greece";
	Image sprite;
	std::vector<std::string> offices{ "Athens" };
	std::vector<std::string> exports{ "oil" };
};

class Romania: public Country
{
public:
	Romania() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Romania";
	Image sprite;
	std::vector<std::string> offices{ "Bucharest" };
	std::vector<std::string> exports{ "car" };
};

class Czechia : public Country
{
public:
	Czechia() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Czechia";
	Image sprite;
	std::vector<std::string> offices{ "Prague" };
	std::vector<std::string> exports{ "car" };
};

class Finland : public Country
{
public:
	Finland() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Finland";
	Image sprite;
	std::vector<std::string> offices{ "Helsinki" };
	std::vector<std::string> exports{ "machinery" };
};

class Baltic : public Country
{
public:
	Baltic() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Baltic";
	Image sprite;
	std::vector<std::string> offices{ "Riga" };
	std::vector<std::string> exports{ "machinery" };
};

class Italy : public Country
{
public:
	Italy() : Country(Name, sprite, offices, exports)
	{

	}
private:
	std::string Name = "Italy";
	Image sprite;
	std::vector<std::string> offices{ "Rome", "Milan"};
	std::vector<std::string> exports{ "machinery", "pharmaceutical"};
};
*/