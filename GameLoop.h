#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Includes.h"
#include "Game.h"
#include "Textures.h"

//Constant Game Speed indepenent of Variable FPS Game Loop implementation
//USING: http://www.koonsolo.com/news/dewitters-gameloop/

//TICKS_PER_SECOND = Update Speed
const int TICKS_PER_SECOND = 60;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 5;

class GameLoop
{
private:
	sf::RenderWindow mWindow;
	Textures mSpriteSheet;
public:
	GameLoop(void);
	virtual ~GameLoop(void);
	void init();
	void loop();
};

