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
	Texture2D button_exit = LoadTexture("../Images/button_exit.png");
	Texture2D button_play = LoadTexture("../Images/button_play.png");

	//Font setback = LoadFont("../setbackt.ttf");

	static std::vector<Factory> factories = createFactory();

	static std::vector<Vector2> coordinates = getCoordinates(factories);

	while (!game.GameShouldClose())
	{
		game.Tick(menu, map, button_exit, button_play, factories, coordinates);
	}
}