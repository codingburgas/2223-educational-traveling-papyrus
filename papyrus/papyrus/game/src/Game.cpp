#include "Game.h"
#define RAYGUI_IMPLEMENTATION

#include <raygui.h>

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

void Game::Tick(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Factory>& factories, std::vector<Vector2> coordinates)
{
	GuiEnable();
	BeginDrawing();
	Update(coordinates, factories);
	Draw(menu, map, button_exit, button_play, bold_button_exit, bold_button_play, coordinates, factories);
	EndDrawing();
}

void Game::Update(std::vector<Vector2> coordinates, std::vector<Factory>& factories)
{
	// Get static instance of Bank
	Bank& bank = Bank::getInstance();

	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	// Check if mouse is clicked
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		// Check if mouse coordinates align with city coordinates
		if (isMouseOnCity(coordinates))
		{
			for (int i = 0; i < 30; i++)
			{
				factories[i].setIsSelected(false);
			}

			factories[checkSelectedCity(factories, coordinates)].setIsSelected(true);
		}
		else
		{
			for (int i = 0; i < 30; i++)
			{
				if (!CheckCollisionPointRec(mousePos, { 1000, 0, 1950, 1100 }))
				{
					factories[i].setIsSelected(false);
				}
			}
		}
	}

	for (int i = 0; i < 30; i++)
	{
		if (factories[i].getIsOwned() == true)
		{
			if (factories[i].getProductionSpeed() <= 0)
			{
				factories[i].setProductionSpeed(factories[i].getMaxSpeed());

				bank.increaseBalance();
			}
			else
			{
				factories[i].setProductionSpeed(factories[i].getProductionSpeed() - 1);
			}
		}
	}
}

void Game::Draw(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Vector2> coordinates, std::vector<Factory>& factories)
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	//Bank& bank = Bank::getInstance();

	ClearBackground(BLACK);

	if (!isMenuClosed)
	{
		// Display menu
		DrawTexture(menu, 0, 0, RAYWHITE);

		Rectangle play_button = { 400, 500, 207, 92 };
		Rectangle exit_button = { 400, 650, 207, 92 };

		if (CheckCollisionPointRec(mousePos, play_button))
		{

			DrawTexture(bold_button_play, 400, 500, RAYWHITE);
			DrawTexture(button_exit, 400, 650, RAYWHITE);
		}
		if (CheckCollisionPointRec(mousePos, exit_button))
		{
			DrawTexture(bold_button_exit, 400, 650, RAYWHITE);
			DrawTexture(button_play, 400, 500, RAYWHITE);
		}
		if (!CheckCollisionPointRec(mousePos, play_button))
		{
			DrawTexture(button_play, 400, 500, RAYWHITE);
		}
		if (!CheckCollisionPointRec(mousePos, exit_button))
		{
			DrawTexture(button_exit, 400, 650, RAYWHITE);

		}

		

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
				EndDrawing();
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

		if (factories[i].getIsOwned())
		{
			DrawCircle(coordinates[i].x, coordinates[i].y, 6, GREEN);
		}
		else
		{
			DrawCircle(coordinates[i].x, coordinates[i].y, 6, RAYWHITE);
		}
	}
}

int checkSelectedCity(std::vector<Factory>& factories, std::vector<Vector2> coordinates)
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	for (int i = 0; i < coordinates.size(); i++)
	{
		if (CheckCollisionPointCircle(mousePos, coordinates[i], 8))
		{
			return i;
		}
	}

	return -1;
}

bool isMouseOnCity(std::vector<Vector2> coordinates)
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	for (int i = 0; i < coordinates.size(); i++)
	{
		if (CheckCollisionPointCircle(mousePos, coordinates[i], 8))
		{
			return true;
		}
	}

	return false;
}

void drawInfo(std::vector<Factory>& factories, std::vector<Vector2> coordinates)
{
	Bank& bank = Bank::getInstance();

	DrawText(TextFormat("Euros %i", bank.getBalance()), 1370, 69, 55, BLACK);
	DrawText("Level", 1070, 69, 55, BLACK);
	DrawText("Statistics", 1305, 186, 55, BLACK);
	DrawText("Income", 1127, 300, 55, BLACK);
	DrawText("City", 1127, 430, 55, BLACK);
	DrawText("Product", 1127, 560, 55, BLACK);

	for (int i = 0; i < coordinates.size(); i++)
	{
		if (factories[i].getIsSelected())
		{
			DrawText(TextFormat("Level %i", factories[i].getTier()), 1070, 69, 55, BLACK);
			DrawText(factories[i].getName().c_str(), 1500, 430, 55, BLACK);

			if (GuiButton({ 1150, 700, 200, 100 }, "BUY"))
			{
				factories[i].buyFactory();
			}

			if (GuiButton({ 1550, 700, 200, 100 }, "UPGRADE"))
			{
				factories[i].upgradeFactory();
			}
		}
	}
}