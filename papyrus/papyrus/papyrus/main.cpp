#include "Game.h"

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    Game game(screenWidth, screenHeight,60, "GEOGRAPHY");

    while (!game.GameShouldClose())
    {
        game.Tick();
    }

    return 0;
}