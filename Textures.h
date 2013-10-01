#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Textures.h"

//Class that holds all the spritesheets so that each entity does not need to store a copy
//Entitie Sprites hold pointers to these spritesheets

//spritesheet type
enum SPRITESHEETS { sBUTTONS, sPLAYER, sBURGER, sBACKGROUND, sGAMEOVER};
class Textures
{
private:
	//vetor that holds the textures
	std::vector<sf::Texture> mSheets;
public:
	Textures(void);
	virtual ~Textures(void);

	sf::Texture* getTexture(SPRITESHEETS pSheet);
};

