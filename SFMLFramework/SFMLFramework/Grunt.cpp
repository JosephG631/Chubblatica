#include "Grunt.h"
#include "Settings.h"
Grunt::Grunt()
	:Alien()
{
	loadTexture( "Assets / Textures /grunt.png" );
}
Grunt::Grunt(const sf::Texture& texture,const int& destroyScore, const sf::SoundBuffer& soundEffect )
	:Alien ( texture, destroyScore, soundEffect )
{
	
}

void Grunt::dive( const sf::Vector2f& playerPosition )
{
	// Set the dive points relevant to formation position  & player position 
	m_diveOnePoints = { std::vector<sf::Vector2f>{getFormationPosition(),sf::Vector2f( getFormationPosition().x, getFormationPosition().y - 150.0f ) }
	,std::vector<sf::Vector2f>{sf::Vector2f( getFormationPosition().x, getFormationPosition().y - 150.0f ),sf::Vector2f( getFormationPosition().x + 280.0f, getFormationPosition().y - 200.0f ), sf::Vector2f( getFormationPosition().x + 280.0f, getFormationPosition().y + 40.0f ),sf::Vector2f( getFormationPosition().x - 50.0f,400.0f )},
		std::vector<sf::Vector2f>{sf::Vector2f( getFormationPosition().x - 50.0f,400.0f ),sf::Vector2f( getFormationPosition().x - 100.0f, 500.0f ),sf::Vector2f( getFormationPosition().x  , 600.0f ) ,sf::Vector2f( getFormationPosition().x  ,600.0f )},std::vector<sf::Vector2f>{sf::Vector2f( getFormationPosition().x  ,600.0f ),sf::Vector2f( playerPosition.x,Settings::k_arenaHeight + 20.0f)}
	,std::vector<sf::Vector2f>{ sf::Vector2f( getFormationPosition().x , -50.0f ),getFormationPosition()} };
	setDivePoints( m_diveOnePoints );
}
