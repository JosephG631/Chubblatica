#include "Boss.h"

Boss::Boss()
	:Alien()
{
	// Load texture in manually 
	loadTexture( "Assets / Textures /boss.png" );
}

Boss::Boss( const sf::Texture& texture , const int& destroyScore,const sf::SoundBuffer& soundEffect )
	:Alien ( texture,destroyScore , soundEffect )
{

}

Boss::~Boss()
{

}
