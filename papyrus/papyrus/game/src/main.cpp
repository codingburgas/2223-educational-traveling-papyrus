#include "Game.h"

int main()
{
	// Create a window
	Game game(1920, 1080, 60, "Papyrus");

	// Load Font
	Font Quando = LoadFontEx("../resources/Quando-Regular.ttf", 60, 0 ,250);
	Font QuandoBig = LoadFontEx("../resources/Quando-Regular.ttf", 100, 0, 250);

	// Load background textures
	Texture2D menuImage = LoadTexture("../resources/Images/menu.png");
	Texture2D mapImage = LoadTexture("../resources/Images/map.png");

	// Load menu buttons
	Texture2D button_exit = LoadTexture("../resources/Images/button_exit.png");
	Texture2D button_play = LoadTexture("../resources/Images/button_play.png");
	Texture2D bold_button_exit = LoadTexture("../resources/Images/bold_button_exit.png");
	Texture2D bold_button_play = LoadTexture("../resources/Images/bold_button_play.png");

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