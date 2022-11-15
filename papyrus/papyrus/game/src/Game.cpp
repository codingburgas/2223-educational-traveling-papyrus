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

void Game::Tick(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, std::vector<Factory>& factories, std::vector<Vector2> coordinates)
{
	BeginDrawing();
	Update(coordinates, factories);
	Draw(menu, map, button_exit, button_play, coordinates, factories);
	EndDrawing();
}

void Game::Update(std::vector<Vector2> coordinates, std::vector<Factory>& factories)
{
	Bank& bank = Bank::getInstance();

	// Check if mouse is clicked
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		isCityClicked(coordinates, factories);
		//factories[checkSelectedCity(factories, coordinates)].buyFactory();
	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
	{
		isCityClicked(coordinates, factories);
		//factories[checkSelectedCity(factories, coordinates)].upgradeFactory();
	}

	for (int i = 0; i < 30; i++)
	{
		if (factories[i].isOwned == true)
		{
			if (factories[i].productionSpeed <= 0)
			{
				factories[i].productionSpeed = factories[i].maxSpeed;

				bank.increaseBalance();
			}
			else
			{
				factories[i].productionSpeed -= 1;
			}
		}
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

		// Display balance
		DrawText(TextFormat("Euros %i", bank.getBalance()),70, 64, 50, BLACK);

		//Display info
		drawInfo(factories, coordinates);
	}
}

void drawCities(std::vector<Vector2> coordinates, std::vector<Factory> factories)
{
	// Display the cities as white dots with black borders

	for (int i = 0; i < coordinates.size(); i++)
	{
		DrawCircle(coordinates[i].x, coordinates[i].y, 8, BLACK);

		if (factories[i].isOwned)
		{
			DrawCircle(coordinates[i].x, coordinates[i].y, 6, GREEN);
		}
		else
		{
			DrawCircle(coordinates[i].x, coordinates[i].y, 6, RAYWHITE);
		}
	}
}

void isCityClicked(std::vector<Vector2> coordinates, std::vector<Factory>& factories)
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
			factories[i].isSelected = true;
		}
	}
}

void drawInfo(std::vector<Factory> &factories, std::vector<Vector2> coordinates)
{
	for (int i = 0; i < coordinates.size(); i++)
	{
		if (factories[i].isSelected)
		{
			DrawText(TextFormat("Level %i", factories[i].getTier()), 1070, 69, 50, BLACK);
			DrawText("Statistics", 1305, 186, 60, BLACK);
			DrawText("Income", 1160, 303, 55, BLACK);
			DrawText("Country", 1137, 430, 55, BLACK);
			DrawText("Buy", 1260, 780, 65, BLACK);
			DrawText(TextFormat("%s", factories[i].getName()), 200, 200, 60, BLACK);
			DrawText("Product", 1127, 537, 60, BLACK);
		}
		else
		{
			DrawText("Level", 1070, 69, 50, BLACK);
			DrawText("Statistics", 1305, 186, 60, BLACK);
			DrawText("Income", 1160, 303, 55, BLACK);
			DrawText("Country", 1137, 430, 55, BLACK);
			DrawText("Buy", 1260, 780, 65, BLACK);
			DrawText("Product", 1127, 537, 60, BLACK);
		}
	}
}

int checkSelectedCity(std::vector<Factory>& factories, std::vector<Vector2> coordinates)
{
	for (int i = 0; i < coordinates.size(); i++)
	{
		if (factories[i].isSelected)
		{
			return i;
		}
		else
		{
			isCityClicked(coordinates, factories);
		}
	}
} 