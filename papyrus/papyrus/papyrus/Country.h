#pragma once
#include <string>
#include <raylib.h>
#include <vector>

class Country
{
public:
	Country(std::string Name, Image image, std::vector<std::string> offices, std::vector<std::string> exports);

	void DrawCountry();
	void UpgradeOffices();
	void BuyOffice();
	void SelectOffice();
private:
	bool isClicked;
};

