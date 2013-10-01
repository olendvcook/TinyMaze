#include "GameLoop.h"
#include <Windows.h>

//extern variable declaration
//extern global variables because many classes alter the states
GAMESTATE mGameState = gMENU;
MENUSTATE mMenuState = mMAIN;

//main method for not console applications
//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

int main()
{
	//call game loop class
	new GameLoop();
}
