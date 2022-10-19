#pragma once
#include <string>
#include <raylib.h>

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
