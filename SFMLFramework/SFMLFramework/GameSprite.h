#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include<SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
//-----------------------------------------------
//class			: GameSprite
// Purpose		: To act as parent for all gj that require a sprite & texture
// Usage		:	
//					GameSprite()
//					GameSprite( const char* textureFileName )
//					GameSprite( const sf::Texture& texture )
//					~GameSprite()
//					bool loadTexture( const char* fileName )
//					const sf::Vector2u& getTextureDimensions() const
//					virtual void update()
//					void setOriginToCenter( const sf::Texture& texture )				
// See also	: 
//-----------------------------------------------
class GameSprite : public sf::Sprite
{
private:
	sf::Texture		m_texture;				// Setting the Sprites texture
	sf::Vector2u	m_textureDimensions;	// Dimensions of the sprite 
public:
	//-----------------------------------------------
	// Function		: GameSprite
	// Purpose		: default class constructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	GameSprite();
	//-----------------------------------------------
	// Function		: GameSprite
	// Purpose		: class constructor with texture loading
	// Parameters	: const char* textureFileName
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	GameSprite( const char* textureFileName );
	//-----------------------------------------------
	// Function		: GameSprite
	// Purpose		: class constructor with texture loading for the texture manager 
	// Parameters	: const sf::Texture& texturee
	// Returns		: void
	// Notes		: N/A
	// See also		: other contructors 
	//-----------------------------------------------
	GameSprite( const sf::Texture& texture );
	//-----------------------------------------------
	// Function		: GameSprite
	// Purpose		: default class deconstructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: Don't call
	// See also		: N/A
	//-----------------------------------------------
	virtual~GameSprite();
	//-----------------------------------------------
	// Function		: load
	// Purpose		: to check if you have loaded a textuure to the sprite
	// Parameters	: const char* fileName 
	// Returns		: bool loaded
	// Notes		: currently not in use as constructor does the function
	// See also		: GameSprite( const char* textureFileName )
	//-----------------------------------------------
	bool loadTexture( const char* fileName );
	//-----------------------------------------------
	// Function		: getTextureDimensions()
	// Purpose		: to get the dimensions of the texture 
	// Parameters	: N/A
	// Returns		: const vector2U textureDimensions
	// Notes		: N/A
	// See also		:
	//-----------------------------------------------
	const sf::Vector2u& getTextureDimensions() const;
	//-----------------------------------------------
	// Function		: update
	// Purpose		: update the entire game sprite 
	// Parameters	: N/A
	// Returns		: N/A
	// Notes		: N/A
	// See also		:
	//-----------------------------------------------
	virtual void update();
	//-----------------------------------------------
	// Function		: setOriginToCenter
	// Purpose		: update the sprites origin to the center of the sprite 
	// Parameters	: const sf::Texture& texture
	// Returns		: void
	// Notes		: N/A
	// See also		: setUpTextureCoords
	//-----------------------------------------------
	void setOriginToCenter( const sf::Texture& texture );
	
};
#endif // !GAMSPRITE_H

