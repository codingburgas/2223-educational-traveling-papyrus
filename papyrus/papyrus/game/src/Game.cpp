#include "Game.h"
#define RAYGUI_IMPLEMENTATION

#include <raygui.h>

class popUpText
{
public:
	int vertical = -10;
	int j = 255;
	unsigned char opacity = (unsigned char)j;
	int life = 50;
};
int mouseIncome = 10;

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

void Game::Tick(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Factory>& factories, std::vector<Vector2> coordinates, Font Quando, Font QuandoBig)
{
	BeginDrawing();
	GuiEnable();
	Update(coordinates, factories, Quando);
	Draw(menu, map, button_exit, button_play, bold_button_exit, bold_button_play, coordinates, factories, Quando, QuandoBig);
	GuiDisable();
	EndDrawing();
}

void Game::Update(std::vector<Vector2> coordinates, std::vector<Factory>& factories, Font Quando)
{
	// Get static instance of Bank
	Bank& bank = Bank::getInstance();

	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	mouseIncome = 10;

	for (int i = 0; i < 30; i++)
	{
		if (factories[i].getIsOwned())
		{
			mouseIncome += 10;
		}

		mouseIncome += factories[i].getTier() * 30;
	}

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
			if (!CheckCollisionPointRec(mousePos, { 1000, 0, 1950, 1100 }))
			{
				for (int i = 0; i < 30; i++)
				{
					factories[i].setIsSelected(false);
				}

				bank.increaseBalance(mouseIncome);
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

				bank.increaseBalance(factories[i].getIncome());
			}
			else
			{
				factories[i].setProductionSpeed(factories[i].getProductionSpeed() - 1);
			}
		}
	}

}

void Game::Draw(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Vector2> coordinates, std::vector<Factory>& factories, Font Quando, Font QuandoBig)
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
			DrawTextEx(QuandoBig, "Play", { 400, 500 }, 100, 0, RAYWHITE);
			DrawRectangleRoundedLines({ 380, 490 , 225, 120 }, 0.2, 2, 3, RAYWHITE);
			DrawTextEx(QuandoBig, "Exit", { 400, 650 }, 100, 0, RAYWHITE);
		}
		if (CheckCollisionPointRec(mousePos, exit_button))
		{
			DrawTextEx(QuandoBig, "Play", { 400, 500 }, 100, 0, RAYWHITE);
			DrawRectangleRoundedLines({ 380, 640 , 225, 120 }, 0.2, 2, 3, RAYWHITE);
			DrawTextEx(QuandoBig, "Exit", { 400, 650 }, 100, 0, RAYWHITE);
		}
		if (!CheckCollisionPointRec(mousePos, play_button))
		{
			DrawTextEx(QuandoBig, "Play", { 400,500 }, 100, 0, RAYWHITE);

		}
		if (!CheckCollisionPointRec(mousePos, exit_button))
		{
			DrawTextEx(QuandoBig, "Exit", { 400, 650 }, 100, 0, RAYWHITE);

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

		//Display info
		drawInfo(factories, coordinates, Quando);

		popUp(Quando, coordinates);
	}
}

void Game::drawCities(std::vector<Vector2> coordinates, std::vector<Factory>& factories)
{
	Bank& bank = Bank::getInstance();

	// Display the cities as white dots with black borders
	for (int i = 0; i < coordinates.size(); i++)
	{
		float radius = 6;
		Color color = RAYWHITE;

		if (factories[i].getIsOwned())
		{
			color = GREEN;
		}

		if (factories[i].getTier() == 2)
		{
			color = ORANGE;
		}

		if (factories[i].getTier() == 3)
		{
			color = YELLOW;
		}

		if (factories[i].getTier() == 4)
		{
			color = PURPLE;
		}

		if (!factories[i].getIsOwned())
		{
			if (bank.getBalance() >= factories[i].getBuyPrice())
			{
				color = DARKGREEN;
			}
		}
		else
		{
			if (bank.getBalance() >= factories[i].getUpgradePrice())
			{
				color = DARKGREEN;
			}
		}

		if ((i == checkSelectedCity(factories, coordinates)) || factories[i].getIsSelected())
		{
			radius = 8;
		}

		DrawCircle(coordinates[i].x, coordinates[i].y, radius + 2, BLACK);
		DrawCircle(coordinates[i].x, coordinates[i].y, radius, color);
	}
}

int Game::checkSelectedCity(std::vector<Factory>& factories, std::vector<Vector2> coordinates)
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

bool Game::isMouseOnCity(std::vector<Vector2> coordinates)
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

void Game::drawInfo(std::vector<Factory>& factories, std::vector<Vector2> coordinates, Font Quando)
{
	Bank& bank = Bank::getInstance();
	DrawTextEx(Quando, TextFormat("Euros %i", bank.getBalance()), { 1370, 69 }, 60, 0, BLACK);
	DrawTextEx(Quando, "Level", { 1070, 69 }, 60, 0, BLACK);
	DrawTextEx(Quando, TextFormat("%i", bank.getIncome()), { 1500, 300 }, 60, 0, BLACK);
	DrawTextEx(Quando, "Statistics", { 1345, 186 }, 60, 0, BLACK);
	DrawTextEx(Quando, "Income", { 1127, 300 }, 60, 0, BLACK);
	DrawTextEx(Quando, "City", { 1127, 430 }, 60, 0, BLACK);
	DrawTextEx(Quando, "Product", { 1127, 560 }, 60, 0, BLACK);

	for (int i = 0; i < coordinates.size(); i++)
	{
		if (factories[i].getIsSelected())
		{
			DrawTextEx(Quando, TextFormat("%i", factories[i].getTier()), { 1220, 69 }, 60, 0, BLACK);
			DrawTextEx(Quando, factories[i].getProduct().getType().c_str(), { 1500 , 550 }, 60, 0, BLACK);
			DrawTextEx(Quando, factories[i].getName().c_str(), { 1500, 430 }, 60, 0, BLACK);
			DrawTextEx(Quando, "Price", { 1550, 700 }, 60, 0, BLACK);

			if (!factories[i].getIsOwned())
			{
				DrawTextEx(Quando, TextFormat("%i", factories[i].getBuyPrice()), { 1550, 750 }, 60, 0, BLACK);

				if (GuiButton({ 1150, 700, 200, 100 }, "BUY"))
				{
					factories[i].buyFactory();
				}
			}
			else
			{
				if (factories[i].getTier() != 4)
				{
					DrawTextEx(Quando, TextFormat("%i", factories[i].getUpgradePrice()), { 1550, 750 }, 60, 0, BLACK);
				}
				else
				{
					DrawTextEx(Quando, "Maxed out", { 1550, 750 }, 60, 0, BLACK);
				}

				if (GuiButton({ 1150, 700, 200, 100 }, "UPGRADE"))
				{
					factories[i].upgradeFactory();
				}
			}
		}
	}
}

void Game::popUp(Font Quando, std::vector<Vector2> coordinates)
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	static std::vector<popUpText> popUps;

	if (mousePos.x >= 47 && mousePos.y >= 44 && mousePos.x <= 980 && mousePos.y <= 1018 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !isMouseOnCity(coordinates))
	{
		popUpText newText;
		popUps.push_back(newText);
	}

	for (int i = 0; i < popUps.size(); i++)
	{
		popUps[i].life -= 1;

		if (popUps[i].life >= 0)
		{
			DrawTextEx(Quando, TextFormat("+%i", mouseIncome), { mousePos.x, mousePos.y + popUps[i].vertical }, 60, 0, Color{ 0,0,0,popUps[i].opacity });
			popUps[i].j -= 10;
			popUps[i].vertical -= 2;
			popUps[i].opacity = (unsigned char)popUps[i].j;
		}
		if (popUps[i].life <= 0)
		{
			popUps.erase(popUps.begin() + i);
		}
	}
}