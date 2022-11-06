#include "Game.h"

int main()
{
    // Open a window
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    Game game(screenWidth, screenHeight,60, "GEOGRAPHY");

    Texture2D menuTexture = LoadTexture("../Images/menu.png");

    while (!game.GameShouldClose())
    {
        
        DrawTexture(menuTexture, 0, 0, RAYWHITE);
        game.Tick();
    }
}