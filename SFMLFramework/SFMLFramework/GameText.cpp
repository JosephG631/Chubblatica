#include "GameText.h"
#include "Helpers.h"

GameText::GameText()
{
}

GameText::GameText( const char* fontFileName )
{
	loadFont( fontFileName );
}

GameText::GameText( const sf::Font& font )
{
	setFont( font );
}

GameText::~GameText()
{

}

bool GameText::loadFont( const char* fontFileName )
{
	// Set Font 
	bool loaded = m_font.loadFromFile( fontFileName );
	
	// Check to see if loaded correctly
	ASSERT( loaded == true );

	// Set font to text. 
	setFont( m_font );

	return loaded;
}