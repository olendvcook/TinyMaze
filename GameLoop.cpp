#include "GameLoop.h"
#include <iostream>

//just call gameloop
GameLoop::GameLoop(void) :
	mSpriteSheet()
{
	loop();
}


GameLoop::~GameLoop(void) 
{
}

void GameLoop::loop()
{
	mGameState = gMENU;
	//Initialize variables to regulate update speed
	sf::Clock clock;
	int nextGameTick = clock.getElapsedTime().asMilliseconds();
	int loops;
	float interpolation;
	//--------------------------------------------
	//create window
	mWindow.create(sf::VideoMode(WindowWidth, WindowHeight), "Tiny Maze");

	//create container classes
	Menu mMenu(&mSpriteSheet);
	Game mGame(&mSpriteSheet);

	//game loop
	while (mWindow.isOpen())
	{
		loops = 0;
		mWindow.clear();

		sf::Event event;

		//controls update speed
		while (clock.getElapsedTime().asMilliseconds() > nextGameTick && loops < MAX_FRAMESKIP)
		{
			//updates Here
			switch(mGameState)
			{
			case(gMENU):
				mMenu.update();
				break;
			case(gGAME):
				mGame.update();
				break;
			case(gGAMEOVER):
				break;
			default:
				break;
			}

			nextGameTick += SKIP_TICKS;
			loops++;
		}

		//Input Here
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				mGame.quit();
				mWindow.close();
			}

			switch(mGameState)
			{
			case(gMENU):
				mMenu.input(&event, &mWindow);
				break;
			case(gGAME):
				mGame.input(&event);
				break;
			case(gGAMEOVER):
				break;
			default:
				break;
			}
		}

		//calculate interpolation to (try to) smooth rendering between update
		interpolation = float(clock.getElapsedTime().asMilliseconds() + SKIP_TICKS - nextGameTick)
			/ float(SKIP_TICKS);

		sf::Sprite gameOver;

		//draw methods here
		switch(mGameState)
		{
		case(gMENU):
			mMenu.draw(&mWindow);
			break;
		case(gGAME):
			mGame.draw(&mWindow, interpolation);
			break;
		case(gGAMEOVER):
			gameOver.setTexture(*mSpriteSheet.getTexture(sGAMEOVER));
			mWindow.draw(gameOver);
			break;
		default:
			break;
		}

		mWindow.display();
	}
}
