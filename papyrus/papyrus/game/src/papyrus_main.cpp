#include "Game.h"

int main()
{
	// Note: make corrections to coordinates with diferent monitor sizes


	int currentMonitor(GetCurrentMonitor());
	Vector2 currentResolution = { GetMonitorWidth(currentMonitor), GetMonitorHeight(currentMonitor) };

	// Create a window
	Game game(currentResolution.x, currentResolution.y, 60, "Papyrus");

	// Load background texture
	Image menuImage = LoadImage("../Images/menu.png");
	ImageResize(&menuImage, GetMonitorWidth(currentMonitor), GetMonitorHeight(currentMonitor));
	Texture2D menu = LoadTextureFromImage(menuImage);
	UnloadImage(menuImage);
	
	Image mapImage = LoadImage("../Images/map.png");
	ImageResize(&mapImage, GetMonitorWidth(currentMonitor), GetMonitorHeight(currentMonitor));
	Texture2D map = LoadTextureFromImage(mapImage);

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