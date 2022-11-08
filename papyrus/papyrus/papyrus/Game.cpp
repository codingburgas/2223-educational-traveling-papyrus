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

void Game::Tick(Texture2D menu, Texture2D map)
{
	BeginDrawing();
	Update();
	Draw(menu, map);
	EndDrawing();
}

void Game::Update()
{
	Bank& bank = Bank::getInstance();

	if (IsKeyDown(KEY_ENTER))
	{
		berlin.buyFactory();
	}
}

void Game::Draw(Texture2D menu, Texture2D map)
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
		DrawText(TextFormat("%i", bank.getBalance()), 1090, 400, 40, RAYWHITE);
	}
}

void drawCities(Vector2 coordinates[])
{
	// Display the cities as white dots with black borders
	for (int i = 0; i < 30; i++)
	{
		DrawCircle(coordinates[i].x, coordinates[i].y, 8, BLACK);
		DrawCircle(coordinates[i].x, coordinates[i].y, 6, RAYWHITE);
	}
}

bool isCityClicked(Vector2 coordinates[])
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	// Check if the left mouse button is clicked
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		// Check if mouse collides with the cities
		for (int i = 0; i < 30; i++)
		{
			if (CheckCollisionPointCircle(mousePos, coordinates[i], 8))
			{
				return true;
			}
		}
		return false;
	}
	return false;
}
