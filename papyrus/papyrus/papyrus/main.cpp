#include "Game.h"

int main()
{
	// Open a window
	const int screenWidth = 1920;
	const int screenHeight = 1080;

	Game game(screenWidth, screenHeight, 60, "GEOGRAPHY");

	// Background texture
	Texture2D map = LoadTexture("../Images/map.png");
	Texture2D menu = LoadTexture("../Images/menu.png");

	// Set money tick 1 second
	int moneyTick = 1000;
	Bank& bank = Bank::getInstance();

	while (!game.GameShouldClose())
	{	
  		game.Tick(menu, map);

		// Countdown money tick until it hits zero
		if (moneyTick == 0)
		{
			bank.increaseBalance();
			moneyTick = 1000;
		}
		else
		{
			moneyTick -= 1;
		}
	}
}