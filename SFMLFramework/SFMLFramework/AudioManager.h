#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <map>
#include <SFML/Audio/SoundBuffer.hpp>
#include <string>

//-----------------------------------------------
//class			: AudioManager
// Purpose		: Stores all the Audio in  the game 
// Usage		:	
//					void  load( const char* fileName, const std::string& mapKey ) 
//					AudioManager();
//					~AudioManager();
//					const  sf::SoundBuffer& getSoundBuffer( const std::string& fileName )
// See also	: 
//-----------------------------------------------
class AudioManager
{
private:
	 std::map<std::string, sf::SoundBuffer> m_audioMap; // Map that stores all sound bufferrs
	 sf::SoundBuffer						m_buffer;	// Temporay sound buffer used for loading 
	//-----------------------------------------------
	// Function		: load
	// Purpose		: loads the sound buffer into the map
	// Parameters	: const char* fileName, const std::string& mapKey
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	void  load( const char* fileName, const std::string& mapKey ) ;
public:
	//-----------------------------------------------
	// Function		: AudioManager
	// Purpose		: defualt constructor 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	AudioManager();
	//-----------------------------------------------
	// Function		: ~AudioManager
	// Purpose		: default decontructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	~AudioManager();
	//-----------------------------------------------
	// Function		: getSoundBuffer
	// Purpose		: returns the sound from the map using the key 
	// Parameters	: const std::string& fileName
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	const  sf::SoundBuffer& getSoundBuffer( const std::string& fileName );

};


#endif // !AUDIOMANAGER_H

