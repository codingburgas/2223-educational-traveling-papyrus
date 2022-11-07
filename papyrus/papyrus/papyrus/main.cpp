#include "Game.h"

int main()
{
    // Open a window
    const int screenWidth = 1920;
    const int screenHeight = 1080;

	int score = 0;

	Vector2 coordinates[30] = {
	{560,560},
	{490,625},
	{510,543},
	{375,653},
	{417,733},
	{230,850},
	{346,833},
	{108,855},
	{346,584},
	{315,529},
	{251,525},
	{152,207},
	{517,389},
	{621,395},
	{550,494},
	{422,570},
	{463,707},
	{621,675},
	{688,560},
	{645,670},
	{681,688},
	{706,744},
	{782,787},
	{810,905},
	{825,731},
	{588,630},
	{711,359},
	{715,450},
	{568,833},
	{497,744}
	};

    Game game(screenWidth, screenHeight, 60, "GEOGRAPHY");

    Texture2D menuTexture = LoadTexture("../Images/menu.png");

    while (!game.GameShouldClose())
    {
        DrawTexture(menuTexture, 0, 0, RAYWHITE);
		drawCities(coordinates);
		if (isCityClicked(coordinates))
		{
			score++;
		}
		DrawText(TextFormat("%i", score), 1090, 185, 40, RAYWHITE);
        game.Tick();

    }
}