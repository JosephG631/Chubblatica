#include "TextureManager.h"
#include "Helpers.h"

TextureManager::TextureManager()
{

	
	// Fill map full of textures & keys
	loadTexture( "Assets/Textures/fly.png", "Fly" );
	loadTexture( "Assets/Textures/Ship.png", "Player" );
	loadTexture( "Assets/Textures/grunt.png", "Grunt" );
	loadTexture( "Assets/Textures/boss.png", "Boss" );
	loadTexture( "Assets/Textures/spaceSpriteSheet.png", "Background" );
	loadTexture( "Assets/Textures/UIShip.png", "UIShip" );
	loadTexture( "Assets/Textures/GameLogo.png", "Logo" );
	loadTexture( "Assets/Textures/bullet.png", "Bullet" );
	loadTexture( "Assets/Textures/explosion.png", "Explosion" );
}

TextureManager::~TextureManager()
{
	// Deconstructor 
}
const sf::Texture& TextureManager::getTexture( const std::string& mapKey ) 
{
	return m_textureMap[mapKey];
}
void TextureManager::loadTexture( const char* fileName, const std::string& mapKey )
{
	
	// Load file to texture
	bool loaded = m_tempTexture.loadFromFile( fileName );

	// Check if file loaded 
	ASSERT( loaded );

	m_textureMap[mapKey] = m_tempTexture;
}