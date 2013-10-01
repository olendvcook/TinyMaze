#pragma once

#include <SFML\Graphics.hpp>

//Class used to control and store what animation frame the animation is on
class Animation
{
private:
	int mCurrentFrame;
	int mMaxFrames;

	//control how fast to iterate to play animations faster/slower
	float mAnimateSpeed;
	sf::Clock mClock;

public:
	Animation(int pMaxFrames, float pAnimateSpeed = 0.3);
	virtual ~Animation(void);

	void animate();
	void resetAnimation();
	int getCurrentFrame() { return mCurrentFrame; }
};

