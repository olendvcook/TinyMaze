#pragma once
#include <SFML\Graphics.hpp>
#include "Includes.h"
#include "Player.h"
#include "AnimatedSprite.h"
#include "Textures.h"
#include "Enemy.h"

//Handles the gameplay state, holds its entities like enemies and player would hold score etc...
//Handles interaction between entities


//TODO: Gameplay states for easy seperate levels possibly, think about it more
class Game
{
private:
	//store entities
	Player mPlayer;
	std::vector<Enemy*> mEnemies;
	Textures *mTextures;
public:
	Game(Textures *pSpriteSheet);
	virtual ~Game(void);

	void update();
	void draw(sf::RenderWindow *window, float pInterpolation);
	void input(sf::Event *pEvent);
	void reset();
	void addEnemy();
	void removeEnemy(int pIndex);
	void quit();
};

