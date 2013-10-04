#include "GameLoop.h"
#include <Windows.h>

//use visual leak detector only in debug mode
#ifdef _DEBUG
#include <vld.h>
#endif

//extern variable declaration
//extern global variables because many classes alter the states
GAMESTATE mGameState = gMENU;
MENUSTATE mMenuState = mMAIN;

//main method for not console applications
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//int main()
{
	//call game loop class
	GameLoop mGameloop;
}
