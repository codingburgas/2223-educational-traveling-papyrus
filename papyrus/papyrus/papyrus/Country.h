#pragma once
#include <string>
#include <raylib.h>
#include <vector>
//#include "Factory.h"


class Country
{
public:
	Country(std::string name, bool inEU, std::string currency/*, std::vector<Factory> factories*/);

private:
	std::string name;
	bool isEU;
	std::string currency;
};

/*
Country Germany("Germany", true, "euro", { {"Berlin", 50000, 70000}, {"Frankfurt", 30000, 50000}, {"Hamburg", 25000, 40000} });
Country France("France", true, "euro", { {"Paris", 50000, 70000}, {"Lyon", 30000, 50000} });
Country Spain("Spain", true, "euro", { {"Madrid", 25000, 40000}, {"Barcelona", 20000, 40000} });
Country Portugal("Portugal", true, "euro", { {"Lisbon", 40000, 60000} });
Country UK("UK", false, "pound", { {"London", 60000, 85000}, {"Manchester", 15000, 30000} });
Country Ireland("Ireland", true, "euro", { {"Dublin", 6000, 4000} });
Country Iceland("Iceland", true, "iceKrona", { {"Reykjavik", 20000, 40000} });
Country Norway("Norway", false, "norKrona", { {"Oslo", 30000, 60000} });
Country Sweden("Sweden", true, "sweKrona", { {"Stockholm", 70000, 90000} });
Country Denmark("Denmark", true, "denKrona", { {"Kopenhagen", 20000, 40000} });
Country Benelux("Benelux", true, "euro", { {"Amsterdam", 60000, 80000} });
Country Swiss("Swiss", false, "frank", { {"Bern", 25000, 40000} });
Country Austria("Austria", true, "euro", { {"Vienna", 25000, 40000} });
Country Poland("Poland", true, "zlota", { {"Warsaw", 35000, 50000} });
Country Slovakia("Slovakia", true, "euro", { {"Bratislava", 25000, 40000} });
Country Hungary("Hungary", true, "euro", { {"Budapest", 35000, 50000} });
Country Serbia("Serbia", false, "dinar", { {"Belgrade", 35000, 50000} });
Country Bulgaria ("Bulgaria", true, "lev", { {"Sofia", 10000, 20000} });
Country Greece("Greece", true, "euro", { {"Athens", 15000, 30000} });
Country Romania("Romania", true, "leu", { {"Bucharest", 15000, 30000} });
Country Czechia("Czechia", true, "cheKrona", { {"Prague", 20000, 40000} });
Country Finland("Finland", true, "euro", { {"Helsinki", 10000, 20000} });
Country Baltic("Baltic", true, "euro", { {"Riga", 10000, 20000} });
Country Italy("Italy", true, "euro", { {"Rome", 9000, 18000}, {"Milan", 30000, 60000 }});*/