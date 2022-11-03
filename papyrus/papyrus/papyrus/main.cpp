#include "Game.h"

int main(void)
{
    // Open a window
    const int screenWidth = 800;
    const int screenHeight = 450;

    Game game(screenWidth, screenHeight,60, "GEOGRAPHY");

    while (!game.GameShouldClose())
    {
        game.Tick();
    }

    printCountryNames();
    
    // Enter a number to select country
    std::cout << "Enter a number: ";

    int num;

    std::cin >> num;
    
    selectCountry(num);
}