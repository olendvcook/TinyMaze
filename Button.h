#pragma once

#include <SFML\Graphics.hpp>
#include "Includes.h"
#include <iostream>

enum BUTTONTYPE { bSTART, bCREDITS, bBACK, bOPTIONS, bTUTORIAL, bGAMEOVER };
//TODO: BUTTON HOLDs WHAT STATE IT WORKS WITH
class Button
{
private:
	sf::Vector2i mSize;
	sf::Sprite mSprite;
	BUTTONTYPE mButtonType;
	bool mPressed;
public:
	Button(sf::Vector2i pPosition, sf::Vector2i pSize, sf::Texture *pTexture, BUTTONTYPE pButtonType);
	virtual ~Button(void);

	void PressButton();
	void ButtonEvent();
	void Draw(sf::RenderWindow *window);

	bool isPressed() { return mPressed; }
	BUTTONTYPE getButtonType() { return mButtonType; }
	//get bounds to check collision mainly with mouse position
	sf::FloatRect getBounds() { return mSprite.getGlobalBounds(); }
};

