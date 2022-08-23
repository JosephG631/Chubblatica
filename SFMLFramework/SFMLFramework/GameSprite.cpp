#include "GameSprite.h"
#include "Helpers.h"

GameSprite::GameSprite()
{

}

GameSprite::GameSprite( const char* textureFileName )
{
	
	loadTexture( textureFileName );
}

GameSprite::GameSprite(const  sf::Texture& texture )

{
	// Setting up GameSprites texture
	setOriginToCenter( texture );
	setTexture( texture );
}

GameSprite::~GameSprite()
{

}



bool GameSprite::loadTexture( const char* fileName )

{
	// Load file to texture
	bool loaded = m_texture.loadFromFile( fileName ); 

	// Check if file loaded 
	ASSERT( loaded );

	// Set sprite texture 
	setTexture( m_texture );

	// Set the sprite orgin to center 
	setOriginToCenter( m_texture );
	
	return loaded;
}

const sf::Vector2u& GameSprite::getTextureDimensions()const
{
	return m_textureDimensions;
}

 void GameSprite::update()
{
	 
}

 void GameSprite::setOriginToCenter( const sf::Texture& texture)
 {
	 // Get texture size 
	 m_textureDimensions = texture.getSize();

	// Set the sprite origin to the center
	setOrigin( static_cast<float>( m_textureDimensions.x * 0.5f ),static_cast<float>( m_textureDimensions.y * 0.5f ) );
 }



