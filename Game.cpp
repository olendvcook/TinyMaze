#include "Game.h"

//takes in pointer to class that hold spritesheets so entities can be created with certain spritesheet
Game::Game(Textures *pSpriteSheet) :
	mTextures(pSpriteSheet),
	mPlayer(sf::Vector2f(200,200), sf::Vector2f(0,0), sf::Vector2i(16,16), (pSpriteSheet->getTexture(sPLAYER)))
{
	//hardcoded enemies because time
	for(int i = 0; i < 100; i++)
	{
		addEnemy();
	}
}

Game::~Game(void)
{
}

//TODO: paramertertize this method to input the valuves to be used for the enemies
void Game::addEnemy()
{
	//if no delete before removed u get memory leaks
	mEnemies.insert(mEnemies.begin(), new Enemy(sf::Vector2f(450,400), sf::Vector2f(0,0), sf::Vector2i(32,32), (mTextures->getTexture(sBURGER))));
	
}

void Game::removeEnemy(int pIndex)
{
	delete(mEnemies.at(pIndex));
	mEnemies.erase((mEnemies.begin() + pIndex));
}

//update method used during game state
//TODO: think of a way to make Game update not so beastly and hacky, maybe some kind of event system
void Game::update()
{
	//call each entity update
	mPlayer.update();
	for(int i = 0; i < mEnemies.size(); i++)
	{	
		//bounds check each enemy with player
		if(mPlayer.getPosition().x < (mEnemies[i]->getPosition().x - 50) && mPlayer.getPosition().x > (mEnemies[i]->getPosition().x - 80))
			mEnemies[i]->setEnemyState(eRIGHT);
		else if(mPlayer.getPosition().x > (mEnemies[i]->getPosition().x + 50) && mPlayer.getPosition().x < (mEnemies[i]->getPosition().x + 80))
			mEnemies[i]->setEnemyState(eLEFT);
		else mEnemies[i]->setEnemyState(eNONE);

		//update enemy
		mEnemies[i]->update();

		//collision detection with player
		if(mEnemies[i]->getBounds().intersects(mPlayer.getBounds()))
		{
			removeEnemy(i);
			continue;
		}
		//kill enemy if off screen
		if(mEnemies[i]->getPosition().x > WindowWidth || mEnemies[i]->getPosition().x < 0)
		{
			removeEnemy(i);
			continue;
		}
		if(mEnemies[i]->getPosition().y > WindowHeight || mEnemies[i]->getPosition().y < 0)
		{
			removeEnemy(i);
			continue;
		}
		
	}
	
	//check for gameover state
	//if(mEnemies.size() == 0)
	//	mGameState = gGAMEOVER;
	
}

//just call draw of all entities
void Game::draw(sf::RenderWindow *window, float pInterpolation)
{
	mPlayer.draw(window, pInterpolation);
	
	for(int i = 0; i < mEnemies.size(); i++)
	{
		mEnemies[i]->draw(window, pInterpolation);
	}	
}

//get passed the input events do stuff based on event type
void Game::input(sf::Event *pEvent)
{
	switch(pEvent->type)
	{
	//change state of player based on what key is pressed
	case(sf::Event::KeyPressed):
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			mPlayer.setPlayerState(pLEFT);
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			mPlayer.setPlayerState(pRIGHT);
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			mPlayer.setPlayerState(pDOWN);
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			mPlayer.setPlayerState(pUP);

		//created to test for memory leaks
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			addEnemy();
		}
		break;
	case(sf::Event::KeyReleased):
		mPlayer.setPlayerState(pNONE);
		break;
	default:
		break;
	}
}

//TODO: impliment reset
void Game::reset()
{
}

//handle memory leaks before quitting
void Game::quit()
{
	//we go down because when we remove from front, everything shifts down
	for(int i = mEnemies.size() - 1; i >= 0; i--)
	{
		removeEnemy(i);
	}
}