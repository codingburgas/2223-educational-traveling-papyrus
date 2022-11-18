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
	Game(int width, int height, int fps, std::string title);
	~Game() noexcept;

	bool GameShouldClose() const;
	void Tick(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Factory>& factories, std::vector<Vector2> coordinates);

private:
	void Update(std::vector<Vector2> coordinates, std::vector<Factory> &factories);
	void Draw(Texture2D menu, Texture2D map, Texture2D button_exit, Texture2D button_play, Texture2D bold_button_exit, Texture2D bold_button_play, std::vector<Vector2> coordinates, std::vector<Factory>& factories);
};

void drawCities(std::vector<Vector2> coordinates, std::vector<Factory> factories);

void drawInfo(std::vector<Factory>& factories, std::vector<Vector2> coordinates);

int checkSelectedCity(std::vector<Factory>& factories, std::vector<Vector2> coordinate);
bool isMouseOnCity(std::vector<Vector2> coordinates);
