#include "Game.h"

//takes in pointer to class that hold spritesheets so entities can be created with certain spritesheet
Game::Game(Textures *pSpriteSheet) :
	mPlayer(sf::Vector2f(200,200), sf::Vector2f(0,0), sf::Vector2i(16,16), (pSpriteSheet->getTexture(sPLAYER)))
{
	//hardcoded enemies because time
	mEnemies.insert(mEnemies.begin(), new Enemy(sf::Vector2f(100,200), sf::Vector2f(0,0), sf::Vector2i(32,32), (pSpriteSheet->getTexture(sBURGER))));
	mEnemies.insert(mEnemies.begin(), new Enemy(sf::Vector2f(300,300), sf::Vector2f(0,0), sf::Vector2i(32,32), (pSpriteSheet->getTexture(sBURGER))));
	mEnemies.insert(mEnemies.begin(), new Enemy(sf::Vector2f(150,250), sf::Vector2f(0,0), sf::Vector2i(32,32), (pSpriteSheet->getTexture(sBURGER))));
	mEnemies.insert(mEnemies.begin(), new Enemy(sf::Vector2f(300,50), sf::Vector2f(0,0), sf::Vector2i(32,32), (pSpriteSheet->getTexture(sBURGER))));
	mEnemies.insert(mEnemies.begin(), new Enemy(sf::Vector2f(345,289), sf::Vector2f(0,0), sf::Vector2i(32,32), (pSpriteSheet->getTexture(sBURGER))));
	mEnemies.insert(mEnemies.begin(), new Enemy(sf::Vector2f(500,400), sf::Vector2f(0,0), sf::Vector2i(32,32), (pSpriteSheet->getTexture(sBURGER))));
	mEnemies.insert(mEnemies.begin(), new Enemy(sf::Vector2f(450,400), sf::Vector2f(0,0), sf::Vector2i(32,32), (pSpriteSheet->getTexture(sBURGER))));
}

Game::~Game(void)
{
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
		//kill enemy if off screen
		if(mEnemies[i]->getBounds().intersects(mPlayer.getBounds()))
		{
			mEnemies.erase((mEnemies.begin() + i));
			continue;
		}
		if(mEnemies[i]->getPosition().x > WindowWidth || mEnemies[i]->getPosition().x < 0)
		{
			mEnemies.erase((mEnemies.begin() + i));
			continue;
		}
		if(mEnemies[i]->getPosition().y > WindowHeight || mEnemies[i]->getPosition().y < 0)
		{
			mEnemies.erase((mEnemies.begin() + i));
			continue;
		}

	}
	
	//check for gameover state
	if(mEnemies.size() == 0)
		mGameState = gGAMEOVER;
	
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