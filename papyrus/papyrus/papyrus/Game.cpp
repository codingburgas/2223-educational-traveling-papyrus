#include "Game.h"

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

void Game::Tick()
{
	BeginDrawing();
	Update();
	Draw();
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

void Game::Draw()
{
	Bank& bank = Bank::getInstance();
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
