#pragma once
#include <string>
#include <raylib.h>
#include <assert.h>
#include <iostream>
#include "Bank.h"
#include "Factory.h"
#include "csv.h"

class Game
{
public:
	// Creates the game window
	Game(int width, int height, int fps, std::string title);

	// Closes the game window
	~Game() noexcept;

	// Checks if the window should close
	bool GameShouldClose() const;

	// Controls the game loop
	void Tick(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Factory>& factories, std::vector<Vector2> coordinates, Font Quando, Font QuandoBig);

private:
	// Updates the logic of the game and checks for actions
	void Update(std::vector<Vector2> coordinates, std::vector<Factory>& factories, Font Quando);

	// Draws the elements of the game
	void Draw(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Vector2> coordinates, std::vector<Factory>& factories, Font Quando, Font QuandoBig);

	// Draws the cities as colored dots on the map
	void drawCities(std::vector<Vector2> coordinates, std::vector<Factory>& factories);

	// Displays the info about the game
	void drawInfo(std::vector<Factory>& factories, std::vector<Vector2> coordinates, Font Quando);

	// Shows how much money you have made on click
	void popUp(Font Quando, std::vector<Vector2> coordinates);

	// Checks which city is selected
	int checkSelectedCity(std::vector<Factory>& factories, std::vector<Vector2> coordinate);

	// Checks if the mouse is hovered on a city
	bool isMouseOnCity(std::vector<Vector2> coordinates);

	bool isMenuClosed = false;
};

