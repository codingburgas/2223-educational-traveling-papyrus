#pragma once
#include <string>
#include <raylib.h>
#include <assert.h>
#include <iostream>
#include "Bank.h"
#include "Factory.h"

class Game
{
public:
	Game(int width, int height, int fps, std::string title);
	~Game() noexcept;

	bool GameShouldClose() const;
	void Tick();

private:
	void Update();
	void Draw();
};

void drawCities(Vector2 coordinates[]);

bool isCityClicked(Vector2 coordinates[]);
