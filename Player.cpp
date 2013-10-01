#include "Player.h"

Player::Player(
		sf::Vector2f pPosition, 
		sf::Vector2f pVelocity, 
		sf::Vector2i pSize, 
		sf::Texture *pTexture,  
		float pAngle, 
		float pAngularVelocity) :
	AnimatedSprite(pPosition, pVelocity, pSize, pTexture, pAngle, pAngularVelocity)
{
	//add animations idle/walk/jump
	mAnimations.insert(mAnimations.begin(), Animation(2));
	mAnimations.insert(mAnimations.begin(), Animation(2));
	mAnimations.insert(mAnimations.begin(), Animation(2));
	mSprite.scale(4,4);
	//start playing idle animation
	AnimatedSprite::startAnimation();
	mPlayerState = pNONE;
}

Player::~Player(void)
{
}

//update depending on player state
void Player::update()
{
	//right now just moves and switches animations
	switch(mPlayerState)
	{
	case(pLEFT):
		mVelocity = sf::Vector2f(-mSpeed, 0);
		AnimatedSprite::setCurrentAnimation(2);
		mSprite.setScale(-4.f,4.f);
		break;
	case(pRIGHT):
		mVelocity = sf::Vector2f(mSpeed, 0);
		AnimatedSprite::setCurrentAnimation(2);
		mSprite.setScale(4.f,4.f);
		break;
	case(pUP):
		mVelocity = sf::Vector2f(0, -mSpeed);
		AnimatedSprite::setCurrentAnimation(1);
		break;
	case(pDOWN):
		mVelocity = sf::Vector2f(0, +mSpeed);
		AnimatedSprite::setCurrentAnimation(2);
		break;
	case(pNONE):
		AnimatedSprite::setCurrentAnimation(0);
		mVelocity = sf::Vector2f(0, 0);
		break;
	default:
		break;
	}
	//call superclass update
	AnimatedSprite::update();
}