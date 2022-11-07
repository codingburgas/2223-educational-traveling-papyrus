#include "Game.h"

int main()
{
    // Open a window
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    int val = 12;

    Game game(screenWidth, screenHeight, 60, "GEOGRAPHY");
    Vector2 mousePos;

    Texture2D menuTexture = LoadTexture("../Images/menu.png");

    while (!game.GameShouldClose())
    {
        mousePos.x = GetMouseX();
        mousePos.y = GetMouseY();
        DrawTexture(menuTexture, 0, 0, RAYWHITE);
        DrawCircle(230, 850, 8, BLACK);
        DrawCircle(230, 850, 6, RAYWHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (CheckCollisionPointCircle(mousePos, Vector2{ 230,850 }, 8))
            {
                val++;
            }
        }
        DrawText(TextFormat("%i", val), 1400, 400, 50, RAYWHITE);
        
        game.Tick();
    }
}


/*
   
*/