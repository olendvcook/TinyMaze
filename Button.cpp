#include "Button.h"

//Class to simulate a button
//just draws and does some action when pressed

Button::Button(sf::Vector2i pPosition, sf::Vector2i pSize, sf::Texture *pTexture, BUTTONTYPE pButtonType) :
	mSize(pSize),
	mButtonType(pButtonType),
	mSprite(*pTexture),
	mPressed(false)
{
	//set sprite position now instead of in draw because buttons dont move
	mSprite.setPosition(pPosition.x, pPosition.y);
	mSprite.scale(0.5, 0.5);
}


Button::~Button(void)
{
}
//do what the button is designed to do
void Button::ButtonEvent()
{
	//rather than a class for each button that extends this class, we store button type and use
	//a switch statement to determine what to do

	switch(mButtonType)
	{
	//do stuff based on what button it is
	case(bSTART):
		if(mMenuState == mMAIN)
		{
			if(isPressed())
			{
			mGameState = gGAME;
			}
			PressButton();
		}
		break;
	case(bCREDITS):
		if(mMenuState == mMAIN)
		{
			if(isPressed())
			{
			mMenuState = mCREDITS;
			}
			PressButton();
		}
		break;
	case(bBACK):
		if(mMenuState == mCREDITS)
		{
			if(isPressed())
			{
			mMenuState = mMAIN;
			}
			PressButton();
		}
		break;
	}
}

void Button::Draw(sf::RenderWindow *window)
{
	mSprite.setTextureRect(sf::IntRect(mButtonType * mSize.x, mPressed * mSize.y, mSize.x, mSize.y));
	window->draw(mSprite);
}

//switch between button up and button down basically just to animate it
inline void Button::PressButton()
{
	mPressed = !mPressed;
}
