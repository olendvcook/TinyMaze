#pragma once

#include <SFML\Graphics.hpp>
#include "Includes.h"

//didn't use just created for later
//Gameover is seperate incase you do something fancy here like save high scores
class GameOver
{
private:

public:
	GameOver(void);
	virtual ~GameOver(void);

	void update();
	void draw(sf::RenderWindow *window, float pInterpolation);
	void input(sf::Event *pEvent);
	void reset();
};

