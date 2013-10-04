#pragma once
#include "animatedsprite.h"

//Extended from AnimatedSprite, also contains player specific stuff for the player

//player states that determine what the player does
//TODO: states are dumb, how can u do more than one at once? move up/left
enum PLAYERSTATE { pLEFT, pUP, pRIGHT, pDOWN, pJUMP, pNONE };
static const float mSpeed = 5;

class Player :
	public AnimatedSprite
{
protected:
	PLAYERSTATE mPlayerState;
public:
	Player(void);
	Player(
		sf::Vector2f pPosition, 
		sf::Vector2f pVelocity, 
		sf::Vector2i pSize, 
		sf::Texture *pTexture, 
		float pAngle = 0, 
		float pAngularVelocity = 0);
	virtual ~Player(void);
	void setPlayerState(PLAYERSTATE pPlayerState) { mPlayerState = pPlayerState; }
	void update();
};

