#pragma once
#include <string>
#include <raylib.h>
#include <assert.h>
#include <iostream>

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

void printCountryNames();
std::string selectCountry(int num);
