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
	void Tick(Texture2D menu, Texture2D map, std::vector<Factory> factories, std::vector<Vector2> coordinates);

private:
	void Update();
	void Draw(Texture2D menu, Texture2D map, std::vector<Vector2> coordinates);
};

void drawCities(std::vector<Vector2> coordinates);

bool isCityClicked(std::vector<Vector2> coordinates);
