#pragma once

#include <SFML\Graphics.hpp>
#include "Includes.h"
#include "Button.h"
#include "Textures.h"

//Main Menu class that holds the main menu buttons and contains states for different menus
//like opetions/credits

class Menu
{
private:
	//could do a vector of backgrounds instead
	sf::Sprite mBackground;
	std::vector<Button> mButtons;
public:
	Menu(Textures *pSpriteSheet);
	virtual ~Menu(void);
	void update();
	void draw(sf::RenderWindow *window);
	void input(sf::Event *pEvent, sf::RenderWindow *window);
	void reset();
};

