#include "Textures.h"

//load all texture and insert into a vector
Textures::Textures(void)
{
	//TODO: not hardcode how texture is loaded
	sf::Texture texture1;
	texture1.loadFromFile("Assets/buttonSheet.png");
	mSheets.insert(mSheets.end(), texture1);

	texture1.loadFromFile("Assets/playerSheet.png");
	mSheets.insert(mSheets.end(), texture1);

	texture1.loadFromFile("Assets/burgerSheet.png");
	mSheets.insert(mSheets.end(), texture1);

	texture1.loadFromFile("Assets/background.png");
	mSheets.insert(mSheets.end(), texture1);

	texture1.loadFromFile("Assets/gameover.png");
	mSheets.insert(mSheets.end(), texture1);
}

Textures::~Textures(void)
{
}

sf::Texture* Textures::getTexture(SPRITESHEETS pSheet)
{
	return &(mSheets.at(pSheet));
}