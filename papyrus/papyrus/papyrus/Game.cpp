#include "Game.h"

bool isMenuClosed = false;

Game::Game(int width, int height, int fps, std::string title)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
	ToggleFullscreen();
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

void Game::Tick(Texture2D menu, Texture2D map, std::vector<Factory> factories, std::vector<Vector2> coordinates)
{
	BeginDrawing();
	Update(coordinates, factories);
	Draw(menu, map, coordinates);
	EndDrawing();
}

void Game::Update(std::vector<Vector2> coordinates, std::vector<Factory> factories)
{
	// Set money tick 1 second
	static int moneyTick = 100;

	Bank& bank = Bank::getInstance();

	for (int i = 0; i < 30; i++)
	{
		// Check if mouse is clicked
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (isCityClicked(coordinates))
			{
				factories.at(i).buyFactory();
			}
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

void Game::Draw(Texture2D menu, Texture2D map, std::vector<Vector2> coordinates)
{
	Bank& bank = Bank::getInstance();

	if (!isMenuClosed)
	{
		// Display menu
		DrawTexture(menu, 0, 0, RAYWHITE);

		if (IsKeyPressed(KEY_SPACE))
		{
			isMenuClosed = true;
			UnloadTexture(menu);
		}
	}
	if (isMenuClosed)
	{
		//Display map
		DrawTexture(map, 0, 0, RAYWHITE);

		// Place the cites on the map
		drawCities(coordinates);

		// Display score
		DrawText(TextFormat("%i", bank.getBalance()), 1100, 70, 40, BLACK);
	}
}

void drawCities(std::vector<Vector2> coordinates)
{
	// Display the cities as white dots with black borders

	for (int i = 0; i < coordinates.size(); i++)
	{
		DrawCircle(coordinates[i].x, coordinates[i].y, 8, BLACK);
		DrawCircle(coordinates[i].x, coordinates[i].y, 6, RAYWHITE);
	}
}

bool isCityClicked(std::vector<Vector2> coordinates)
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	std::cout << mousePos.x << " " << mousePos.y << std::endl;

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
