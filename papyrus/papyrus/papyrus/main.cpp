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


	while (!game.GameShouldClose())
	{	
  		game.Tick(menu, map);

	}
}