#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <map>
#include <string>

#include "SFML/Graphics.hpp"

//-----------------------------------------------
//class			: TextureManager
// Purpose		: Manages textures to reduce repeititve loading  
// Usage		:	void  loadTexture( const char* fileName ,const std::string& mapKey )
//					TextureManager()
//					~TextureManager()
//					const sf::Texture& getTexture( const std::string& mapKey )
// See also	: 
//-----------------------------------------------
class TextureManager
{

private:
	sf::Texture							m_tempTexture;	// Temporay texture 
	std::map<std::string, sf::Texture>	m_textureMap;	// storage of all textures 
	//-----------------------------------------------
	// Function		: LoadTexture
	// Purpose		: used to load in textures safely 
	// Parameters	: const char* fileName ,const std::string& mapKey 
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	void  loadTexture( const char* fileName ,const std::string& mapKey );
public:
	//-----------------------------------------------
	// Function		: TextureManager
	// Purpose		: default class constructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	TextureManager();
	//-----------------------------------------------
	// Function		: TextureManager
	// Purpose		: default class deconstructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	~TextureManager();
	//-----------------------------------------------
	// Function		: getTexture
	// Purpose		:  Get texture from map using key 
	// Parameters	: const std::string& mapKey
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	const sf::Texture& getTexture( const std::string& mapKey );

};


#endif // !TEXTUREMANAGER_H

