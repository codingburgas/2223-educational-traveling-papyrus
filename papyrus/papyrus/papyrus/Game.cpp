#include "Game.h"

Game::Game(int width, int height, int fps, std::string title)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept
{
	assert(GetWindowHandle()); //If assertion triggers : Window is already closed
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return WindowShouldClose();
}

void Game::Tick()
{
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}

void Game::Update()
{

}

void Game::Draw()
{
	
}

void printCountryNames()
{
	std::cout << "1.Germany" << std::endl;
	std::cout << "2.France" << std::endl;
	std::cout << "3.Spain" << std::endl;
	std::cout << "4.Portugal" << std::endl;
	std::cout << "5.UK" << std::endl;
	std::cout << "6.Ireland" << std::endl;
	std::cout << "7.Iceland" << std::endl;
	std::cout << "8.Norway" << std::endl;
	std::cout << "9.Sweden" << std::endl;
	std::cout << "10.Denmark" << std::endl;
	std::cout << "11.Benelux" << std::endl;
	std::cout << "12.Switzerland" << std::endl;
	std::cout << "13.Austria" << std::endl;
	std::cout << "14.Poland" << std::endl;
	std::cout << "15.Slovakia" << std::endl;
	std::cout << "16.Hungary" << std::endl;
	std::cout << "17.Serbia" << std::endl;
	std::cout << "18.Bulgaria" << std::endl;
	std::cout << "19.Greece" << std::endl;
	std::cout << "20.Romania" << std::endl;
	std::cout << "21.Czechia" << std::endl;
	std::cout << "22.Finland" << std::endl;
	std::cout << "23.Baltic" << std::endl;
	std::cout << "24.Italy" << std::endl;
}

std::string selectCountry(int num)
{
	

	switch (num)
	{
	case 1:
		return "germany";
		std::cout << 1;
	case 2:
		return "france";
	case 3:
		return "spain";
	case 4:
		return "portugal";
	case 5:
		return "uk";
	case 6:
		return "ireland";
	case 7:
		return "iceland";
	case 8:
		return "norway";
	case 9:
		return "sweden";
	case 10:
		return "denmark";
	case 11:
		return "benelux";
	case 12:
		return "swiss";
	case 13:
		return "austria";
	case 14:
		return "poland";
	case 15:
		return "slovakia";
	case 16:
		return "hungary";
	case 17:
		return "serbia";
	case 18:
		return "bulgaria";
	case 19:
		return "greece";
	case 20:
		return "romania";
	case 21:
		return "czechia";
	case 22:
		return "finland";
	case 23:
		return "baltic";
	case 24:
		return "italy";
	default:
		std::cout << "Enter a valid number";
	}
}