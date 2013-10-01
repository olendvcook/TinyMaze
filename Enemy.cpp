#include "Enemy.h"


Enemy::Enemy(sf::Vector2f pPosition, 
		sf::Vector2f pVelocity, 
		sf::Vector2i pSize, 
		sf::Texture *pTexture,  
		float pAngle, 
		float pAngularVelocity) :
	//call superclass constructor
	AnimatedSprite(pPosition, pVelocity, pSize, pTexture, pAngle, pAngularVelocity)
{
	//insert animations based on Enemy spriteSheet
	mAnimations.insert(mAnimations.begin(), Animation(2));
	mAnimations.insert(mAnimations.begin(), Animation(2));
	mAnimations.insert(mAnimations.begin(), Animation(2));
	mAnimations.insert(mAnimations.begin(), Animation(2));
	//start idle animation
	AnimatedSprite::startAnimation();
}


Enemy::~Enemy(void)
{
}

//update based on what state we are in
void Enemy::update()
{
	//call superclass update that handles changing pos by velocity and animates
	AnimatedSprite::update();

	switch (mEnemyState)
	{
	case eLEFT:
		mVelocity = sf::Vector2f(-5,0);
		break;
	case eRIGHT:
		mVelocity = sf::Vector2f(5,0);
		break;
	default:
		mVelocity = sf::Vector2f(0,0);
		break;
	}

}

