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
	void Tick(Texture2D menu, Texture2D map);

private:
	void Update();
	void Draw(Texture2D menu, Texture2D map);
};

void drawCities(Vector2 coordinates[]);

bool isCityClicked(Vector2 coordinates[]);
