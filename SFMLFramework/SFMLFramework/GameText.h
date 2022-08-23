#ifndef GAMETEXT_H
#define GAMETEXT_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

//-----------------------------------------------
//class			: GameText
// Purpose		: class that allows text render with an applyied font 
// Usage		:	
//					GameText()
//					GameText( const char* fontFileName )
//					GameText( const sf::Font& font )
//					~GameText()
//					bool loadFont( const char* fontFileName )
// See also	: 
//-----------------------------------------------
class GameText : public sf::Text
{
private: 

	sf::Font	m_font; // Font set to the Text 


public:
	//-----------------------------------------------
	// Function		: GameText
	// Purpose		: default class constructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	GameText();
	//-----------------------------------------------
	// Function		: GameText( const char* fontFileName )
	// Purpose		: constructor passing in file path of font 
	// Parameters	: const char* fontFileName
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	GameText( const char* fontFileName );
	//-----------------------------------------------
	// Function		: GameText( const sf::font* font )
	// Purpose		: constructor passing in a font 
	// Parameters	: const sf::font& font 
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	GameText( const sf::Font& font );
	//-----------------------------------------------
	// Function		: GameText
	// Purpose		: default class deconstructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: Don't call
	// See also		: N/A
	//-----------------------------------------------
	~GameText();
	//-----------------------------------------------
	// Function		: loadFont
	// Purpose		: load a font and set it to the text
	// Parameters	:  const char* fontFileName
	// Returns		: bool 
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	bool loadFont( const char* fontFileName );
};

#endif