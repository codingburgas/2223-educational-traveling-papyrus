#include "Game.h"
#define RAYGUI_IMPLEMENTATION

#include <raygui.h>

struct popUpText
{
	int vertical = -30;
	int j = 255;
	unsigned char opacity = (unsigned char)j;
	int life = 50;
	float x;
	float y;
};

// Income generated by mouse clicks
int mouseIncome = 30;

/**
 * .Creates the game window
 *
 * \param width The width of the game window
 * \param height The height of the game window
 * \param fps The amount of frapes per second the window has
 * \param title The title of the window
 */
Game::Game(int width, int height, int fps, std::string title)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
	ToggleFullscreen();
}

/**
 * .Closes the game window
 */
Game::~Game() noexcept
{
	assert(GetWindowHandle()); //If assertion triggers : Window is already closed
	CloseWindow();
}

/**
 * .Checks if the window should close
 */
bool Game::GameShouldClose() const
{
	return gameShouldClose;
}

/**
 * .Controls the game loop
 *
 * \param menu Texture2D of the game main menu
 * \param map Texture2D of the game map
 * \param button_exit Texture2D of the exit button
 * \param button_play Texture2D of the play button
 * \param bold_button_exit Texture2D of the exit button when being hovered
 * \param bold_button_play Texture2D of the play button when being hovered
 * \param factories A reference to vector of objects of type factory
 * \param coordinates A vector of objects of type Vecor2
 * \param Quando The game's font
 * \param QuandoBig Bold version of the game's font
 */
void Game::Tick(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Factory>& factories, std::vector<Vector2> coordinates, Font Quando, Font QuandoBig)
{
	// Begin the drawing process
	BeginDrawing();

	// Enable the gui
	GuiEnable();

	Update(coordinates, factories, Quando);
	Draw(menu, map, button_exit, button_play, bold_button_exit, bold_button_play, coordinates, factories, Quando, QuandoBig);

	// Disable the gui
	GuiDisable();

	// End the drawing process
	EndDrawing();
}

/**
 * .Updates the logic of the game and checks for actions
 *
 * \param coordinates A vector of objects of type Vecor2
 * \param factories A reference to a vector of objects of type factory
 */
void Game::Update(std::vector<Vector2> coordinates, std::vector<Factory>& factories, Font Quando)
{
	// Get static instance of Bank
	Bank& bank = Bank::getInstance();

	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	mouseIncome = 30;

	// Increase the income on mouse click based on owned factories
	for (int i = 0; i < 30; i++)
	{
		if (factories[i].getIsOwned())
		{
			mouseIncome += 30;
		}

		mouseIncome += factories[i].getTier() * 30;
	}

	// Check if the left mouse button is clicked
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		// Check if mouse coordinates align with city coordinates
		if (isMouseOnCity(coordinates))
		{
			// Check the indexof the factory
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
				// Deselect all factories
				for (int i = 0; i < 30; i++)
				{
					factories[i].setIsSelected(false);
				}

				// Increase the balanced with mouse click
				bank.increaseBalance(mouseIncome);
			}
		}
	}

	// Speed of which each factory generates income
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

/**
 * .Draws the elements of the game
 *
 * \param menu Texture2D of the game main menu
 * \param map Texture2D of the game map
 * \param button_exit Texture2D of the exit button
 * \param button_play Texture2D of the play button
 * \param bold_button_exit Texture2D of the exit button when being hovered
 * \param bold_button_play Texture2D of the play button when being hovered
 * \param coordinates A vector of objects of type Vecor2
 * \param factories A reference to a vector of objects of type factory
 * \param Quando The game's font
 * \param QuandoBig Bold version of the game's font
 */
void Game::Draw(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Vector2> coordinates, std::vector<Factory>& factories, Font Quando, Font QuandoBig)
{
	Vector2 mousePos;

	// Get the positions of the mouse
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();

	ClearBackground(BLACK);

	if (!isMenuClosed)
	{
		// Display menu
		DrawTexture(menu, 0, 0, RAYWHITE);

		// Initialize the coorninates of the play button
		Rectangle play_button = { 400, 500, 207, 92 };

		// Initialize the coorninates of the exit button
		Rectangle exit_button = { 400, 650, 207, 92 };

		// Display the play button when hovered
		if (CheckCollisionPointRec(mousePos, play_button))
		{
			DrawTextEx(QuandoBig, "Play", { 400, 500 }, 100, 0, RAYWHITE);
			DrawRectangleRoundedLines({ 380, 490 , 225, 120 }, 0.2, 2, 3, RAYWHITE);
			DrawTextEx(QuandoBig, "Exit", { 400, 650 }, 100, 0, RAYWHITE);
		}

		// Display the play exit when hovered
		if (CheckCollisionPointRec(mousePos, exit_button))
		{
			DrawTextEx(QuandoBig, "Play", { 400, 500 }, 100, 0, RAYWHITE);
			DrawRectangleRoundedLines({ 380, 640 , 225, 120 }, 0.2, 2, 3, RAYWHITE);
			DrawTextEx(QuandoBig, "Exit", { 400, 650 }, 100, 0, RAYWHITE);
		}

		// Display the play button
		if (!CheckCollisionPointRec(mousePos, play_button))
		{
			DrawTextEx(QuandoBig, "Play", { 400,500 }, 100, 0, RAYWHITE);

		}

		// Display the exit button
		if (!CheckCollisionPointRec(mousePos, exit_button))
		{
			DrawTextEx(QuandoBig, "Exit", { 400, 650 }, 100, 0, RAYWHITE);

		}

		// Check if the left button is pressed
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			// Close the menu and start the game
			if (CheckCollisionPointRec(mousePos, play_button))
			{
				isMenuClosed = true;
				UnloadTexture(menu);
				UnloadTexture(button_play);
				UnloadTexture(button_exit);
			}

			// Exit the game
			if (CheckCollisionPointRec(mousePos, exit_button))
			{
				EndDrawing();
				GuiDisable();
				
				gameShouldClose = true;
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

/**
 * .Draws the cities as colored dots on the map
 *
 * \param coordinates A vector of objects of type Vecor2
 * \param factories A reference to a vector of objects of type factory
 */
void Game::drawCities(std::vector<Vector2> coordinates, std::vector<Factory>& factories)
{
	Bank& bank = Bank::getInstance();

	for (int i = 0; i < coordinates.size(); i++)
	{
		// Default color and radious
		float radius = 6;
		Color color = RAYWHITE;

		// Set color to green if factory is owned
		if (factories[i].getIsOwned())
		{
			color = GREEN;
		}

		// Set color to yellow if factory's tier is 2
		if (factories[i].getTier() == 2)
		{
			color = YELLOW;
		}

		// Set color to orange if factory's tier is 3
		if (factories[i].getTier() == 3)
		{
			color = ORANGE;
		}

		// Set color to purple if factory's tier is 4
		if (factories[i].getTier() == 4)
		{
			color = PURPLE;
		}

		// Set color to dark green if anything is purchasable
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

		// Change radius if a factory is hovered
		if ((i == checkSelectedCity(factories, coordinates)) || factories[i].getIsSelected())
		{
			radius = 8;
		}

		// Display the factories
		DrawCircle(coordinates[i].x, coordinates[i].y, radius + 2, BLACK);
		DrawCircle(coordinates[i].x, coordinates[i].y, radius, color);
	}
}

/**
* .Checks which city is selected
*
* \param factories A vector of objects of type factory
* \param coordinates A vector of objects of tupe Vecor2
*
* \return index of selected factory
 */
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
			// Return the index of the selected factory
			return i;
		}
	}

	// Return -1 if no factory is selected
	return -1;
}

/**
 * .Checks if the mouse is hovered on a city
 *
 * \param coordinates A vector of objects of type Vecor2
 * \return true or false depending if the city is hovered
 */
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
			// Returns true if mouse is hovered on a city
			return true;
		}
	}

	// Returns mouse if mouse is not hovered on a city
	return false;
}

/**
 * .Displays the info about the game
 *
 * \param factories A vector of objects of type Vecor2
 * \param coordinates A reference to a vector of objects of type factory
 * \param Quando The game's font
 */
void Game::drawInfo(std::vector<Factory>& factories, std::vector<Vector2> coordinates, Font Quando)
{
	Bank& bank = Bank::getInstance();

	// Display the current balance
	DrawTextEx(Quando, TextFormat("Euros %i", bank.getBalance()), { 1370, 69 }, 60, 0, BLACK);

	DrawTextEx(Quando, "Level", { 1070, 69 }, 60, 0, BLACK);

	// Display the combined income of all factories
	DrawTextEx(Quando, "Income", { 1127, 300 }, 60, 0, BLACK);
	DrawTextEx(Quando, TextFormat("%i", bank.getIncome()), { 1500, 300 }, 60, 0, BLACK);


	DrawTextEx(Quando, "Statistics", { 1345, 186 }, 60, 0, BLACK);


	DrawTextEx(Quando, "City", { 1127, 430 }, 60, 0, BLACK);
	DrawTextEx(Quando, "Product", { 1127, 560 }, 60, 0, BLACK);

	for (int i = 0; i < coordinates.size(); i++)
	{
		if (factories[i].getIsSelected())
		{
			// Display the tier of the selected factory
			DrawTextEx(Quando, TextFormat("%i", factories[i].getTier()), { 1220, 69 }, 60, 0, BLACK);

			// Display the type of product produced by the selected factory
			DrawTextEx(Quando, factories[i].getProduct().getType().c_str(), { 1500 , 550 }, 60, 0, BLACK);

			// Display the name of the selected factory
			DrawTextEx(Quando, factories[i].getName().c_str(), { 1500, 430 }, 60, 0, BLACK);

			// Display the price for byuing/upgrading the selected factory
			DrawTextEx(Quando, "Price", { 1550, 700 }, 60, 0, BLACK);

			// Create a buy/upgrade button depending if the selected factory is owned or no
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
					if (GuiButton({ 1150, 700, 200, 100 }, "UPGRADE"))
					{
						factories[i].upgradeFactory();
					}
					DrawTextEx(Quando, TextFormat("%i", factories[i].getUpgradePrice()), { 1550, 750 }, 60, 0, BLACK);
				}
				else
				{
					if (GuiButton({ 1150, 700, 200, 100 }, "MAXED OUT"))
					{
						
					}
					DrawTextEx(Quando, "Maxed out", { 1550, 750 }, 60, 0, BLACK);
				}

			}
		}
	}
}

/**
 * .Shows how much money you have made on click
 *
 * \param Quando The game's font
 * \param coordinates A vector of objects of type Vecor2
 */
void Game::popUp(Font Quando, std::vector<Vector2> coordinates)
{
	Vector2 mousePos;
	mousePos.x = GetMouseX();
	mousePos.y = GetMouseY();
	// Vector of pop ups
	static std::vector<popUpText> popUps;

	// Check if mouse is clicked on the map and city is not hovered
	if (mousePos.x >= 47 && mousePos.y >= 44 && mousePos.x <= 980 && mousePos.y <= 1018 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !isMouseOnCity(coordinates))
	{
		// Create new pop up
		popUpText newText;
		newText.x = mousePos.x;
		newText.y = mousePos.y;
		popUps.push_back(newText);
	}

	// Display the money you gained on click for the life time of an pop up
	for (int i = 0; i < popUps.size(); i++)
	{
		popUps[i].life -= 1;

		if (popUps[i].life >= 0)
		{
			DrawTextEx(Quando, TextFormat("+%i", mouseIncome), { popUps[i].x, popUps[i].y + popUps[i].vertical }, 60, 0, Color{ 0,0,0,popUps[i].opacity });
			popUps[i].j -= 3;
			popUps[i].vertical -= 2;
			popUps[i].opacity = (unsigned char)popUps[i].j;
		}
		if (popUps[i].life <= 0)
		{
			popUps.erase(popUps.begin() + i);
		}
	}
}