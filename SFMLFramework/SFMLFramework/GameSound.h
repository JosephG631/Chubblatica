#ifndef GAMESOUND_H
#define GAMESOUND_H

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

//-----------------------------------------------
//class			: GameSound
// Purpose		: A Game object of a sound effect  
// Usage		:	
//				GameSound();	
//				GameSound( const sf::SoundBuffer& soundFile );
//				~GameSound(  );	
//				bool load( const char* fileName );	
// See also	: 	
//-----------------------------------------------
class GameSound : public sf::Sound
{
private:
	sf::SoundBuffer m_buffer; // Audio file for GameObject 

public:
	//-----------------------------------------------
	// Function		: GameSound
	// Purpose		: default constructor 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	GameSound();
	//-----------------------------------------------
	// Function		: GameSound( const sf::SoundBuffer& soundFile )
	// Purpose		: contructor to pass  a sound file in
	// Parameters	: const sf::SoundBuffer& soundFile
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	GameSound( const sf::SoundBuffer& soundFile );
	//-----------------------------------------------
	// Function		: ~GameSound
	// Purpose		: decontructor 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: Don't call 
	// See also		: 
	//-----------------------------------------------
	~GameSound(  );
	//-----------------------------------------------
	// Function		: load
	// Purpose		: load in a file via its path 
	// Parameters	: const char* fileName
	// Returns		: void
	// Notes		: Don't call 
	// See also		: 
	//----------------------------------------------
	bool load( const char* fileName );
};

#endif