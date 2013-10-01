#pragma once

#include "Animation.h"
#include <SFML\Graphics.hpp>

//A Entity that holds arrays of animation to display an animated sprite using a sprite sheet
//Has basic entity stuff like position, size, velocity
//Designed to be extended by more specific entities like Player/Enemy
class AnimatedSprite
{
protected:
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;
	sf::Vector2i mSize;
	//for rotation
	float mAngle;
	float mAngularVelocity;
	//Sprite that hold and displays
	sf::Sprite mSprite;

	//store which array of animation is currently being used
	int mCurrentAnimation;
	
	bool mIsAnimating;

	//array of class Animation to store all the different Animations like Idle/Walk/Jump
	std::vector<Animation> mAnimations;
public:
	AnimatedSprite(
		sf::Vector2f pPosition, 
		sf::Vector2f pVelocity, 
		sf::Vector2i pSize, 
		sf::Texture *pTexture, 
		float pAngle = 0, 
		float pAngularVelocity = 0);

	virtual ~AnimatedSprite(void);

	virtual void startAnimation();
	virtual void endAnimation();
	virtual void update();
	virtual void draw(sf::RenderWindow *window, float pInterpolation);

	//getters and setters

	//change what the current animation is like idle/jump/walk
	virtual void setCurrentAnimation(int pRow) { mCurrentAnimation = pRow; }
	//get bounds in global space for use in collision detection
	virtual sf::FloatRect getBounds() { return mSprite.getGlobalBounds(); }
	virtual sf::Vector2f getPosition() { return mPosition; }
};

