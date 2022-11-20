#include "Game.h"

int main()
{
	// Create a window
	Game game(1920, 1080, 60, "Papyrus");

	// Load Font
	Font Quando = LoadFontEx("../Quando-Regular.ttf", 60, 0 ,250);
	Font QuandoBig = LoadFontEx("../Quando-Regular.ttf", 100, 0, 250);

	// Load background textures
	Texture2D menuImage = LoadTexture("../Images/menu.png");
	Texture2D mapImage = LoadTexture("../Images/map.png");

	// Load menu buttons
	Texture2D button_exit = LoadTexture("../Images/button_exit.png");
	Texture2D button_play = LoadTexture("../Images/button_play.png");
	Texture2D bold_button_exit = LoadTexture("../Images/bold_button_exit.png");
	Texture2D bold_button_play = LoadTexture("../Images/bold_button_play.png");

	// Create a static instance of vector of factories
	static std::vector<Factory> factories = createFactory();

	// Create static instace of all factories coordinates
	static std::vector<Vector2> coordinates = getCoordinates(factories);	

	// Create the game loop
	while (!game.GameShouldClose())
	{
		game.Tick(menuImage, mapImage, button_exit, button_play, bold_button_exit, bold_button_play, factories, coordinates, Quando, QuandoBig);
	}
	
	UnloadFont(Quando);
	UnloadFont(QuandoBig);
	UnloadTexture(menuImage);
	UnloadTexture(mapImage);
	UnloadTexture(button_exit);
	UnloadTexture(button_play);
	UnloadTexture(bold_button_exit);
	UnloadTexture(bold_button_play);
}