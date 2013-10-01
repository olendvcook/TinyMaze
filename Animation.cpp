#include "Animation.h"

//Class thats a fancy counter to iterate through a list
//see header for more detail

Animation::Animation(int pMaxFrames, float pAnimateSpeed) :
	mMaxFrames(pMaxFrames),
	mAnimateSpeed(pAnimateSpeed)
{
	mCurrentFrame = 0;
}


Animation::~Animation(void)
{
}

//iterate through array to change current frame
void Animation::animate()
{
	//if its time to iterate based on animation speed
	if(mClock.getElapsedTime().asSeconds() > mAnimateSpeed){
		//iterate
		mCurrentFrame++;
		mCurrentFrame %= mMaxFrames;
	
		mClock.restart();
	}
}

//go back to first frame
void Animation::resetAnimation()
{
	mCurrentFrame = 0;
}
