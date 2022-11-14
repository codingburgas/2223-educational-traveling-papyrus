#include "Game.h"

bool isMenuClosed = false;

Game::Game(int width, int height, int fps, std::string title)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
	//ToggleFullscreen();
}

Game::~Game() noexcept
{
	assert(GetWindowHandle()); //If assertion triggers : Window is already closed
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return WindowShouldClose();
}

void Game::Tick(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, std::vector<Factory>& factories, std::vector<Vector2> coordinates)
{
	BeginDrawing();
	Update(coordinates, factories);
	Draw(menu, map, button_exit, button_play, coordinates, factories);
	EndDrawing();
}

void Game::Update(std::vector<Vector2> coordinates, std::vector<Factory>& factories)
{
	// Set money tick 1 second
	static int moneyTick = 100;

	Bank& bank = Bank::getInstance();

	// Check if mouse is clicked
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		if (isCityClicked(coordinates))
		{
			factories.at(CheckClickedCity(coordinates)).buyFactory();
		}
	}


	// Countdown money tick until it hits zero
	if (moneyTick == 0)
	{
		bank.increaseBalance();
		moneyTick = 100;
	}
	else
	{
		moneyTick -= 1;
	}
}

void Game::Draw(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, std::vector<Vector2> coordinates, std::vector<Factory> factories)
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	Bank& bank = Bank::getInstance();

	if (!isMenuClosed)
	{
		// Display menu
		DrawTexture(menu, 0, 0, RAYWHITE);
		DrawTexture(button_exit, 400, 650, RAYWHITE);
		DrawTexture(button_play, 400, 500, RAYWHITE);

		Rectangle play_button = { 400, 500, 207, 92 };
		Rectangle exit_button = { 400, 650, 207, 92 };

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (CheckCollisionPointRec(mousePos, play_button))
			{
				isMenuClosed = true;
				UnloadTexture(menu);
				UnloadTexture(button_play);
				UnloadTexture(button_exit);
			}
			if (CheckCollisionPointRec(mousePos, exit_button))
			{

				CloseWindow();
			}

		}
	}
	if (isMenuClosed)
	{
		//Display map
		DrawTexture(map, 0, 0, RAYWHITE);

		// Place the cites on the map
		drawCities(coordinates, factories);

		// Display score
		DrawText(TextFormat("%i", bank.getBalance()), 1100, 70, 40, BLACK);
	}
}

void drawCities(std::vector<Vector2> coordinates, std::vector<Factory> factories)
{
	// Display the cities as white dots with black borders

	for (int i = 0; i < coordinates.size(); i++)
	{
		/*if (factories[i].getOwned() == true)
		{
			DrawCircle(coordinates[i].x, coordinates[i].y, 6, GREEN);
		}*/

		DrawCircle(coordinates[i].x, coordinates[i].y, 6, RAYWHITE);
		DrawCircle(coordinates[i].x, coordinates[i].y, 8, BLACK);
	}
}

bool isCityClicked(std::vector<Vector2> coordinates)
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	// Check if mouse collides with the cities
	for (int i = 0; i < coordinates.size(); i++)
	{
		if (CheckCollisionPointCircle(mousePos, coordinates[i], 8))
		{
			return true;
		}
	}
	return false;
}

int CheckClickedCity(std::vector<Vector2> coordinates)
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	// Check if mouse collides with the cities
	for (int i = 0; i < coordinates.size(); i++)
	{
		if (CheckCollisionPointCircle(mousePos, coordinates[i], 8))
		{
			return i;
		}
	}
	return -1;
}