#include "GameSound.h"
#include "Helpers.h"

GameSound::GameSound()
{
	// Constructor 
}

GameSound::GameSound( const sf::SoundBuffer& soundFile )
{
	// Set Sound 
	setBuffer( soundFile );
}

GameSound::~GameSound()
{

}

bool GameSound::load( const char* fileName )
{
	// Load sound from file path
	bool loaded = m_buffer.loadFromFile( fileName );

	// Check to see if loaded susscefully 
	ASSERT( loaded == true );

	// Set sound 
	setBuffer( m_buffer );

	return loaded;
}