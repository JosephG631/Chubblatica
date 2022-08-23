#include "AudioManager.h"
#include "Helpers.h"

AudioManager::AudioManager()
{
	// Load all assets to the map
	load( "Assets/Audio/ShootOne.wav", "ShootOne" );
	load( "Assets/Audio/ShootTwo.wav", "ShootTwo" );
	load( "Assets/Audio/ArcadeJam.wav", "BackgroundMusic" );
	load( "Assets/Audio/aliendeath.wav",  "AlienDeath" );
	load( "Assets/Audio/playerDeath.wav", "PlayerDeath" );
	load( "Assets/Audio/MenuSound.wav", "MenuSound" );
}

AudioManager::~AudioManager()
{
	// Deconstructor
}
const  sf::SoundBuffer& AudioManager::getSoundBuffer( const std::string& fileName )
{
	return m_audioMap[fileName];
}
 void AudioManager::load( const char* fileName ,  const std::string& mapKey )
{
	// Load Audio buffer 
	bool loaded = m_buffer.loadFromFile( fileName );
	// Check if loaded correctly 
	ASSERT( loaded  );

	
	// Return Audio 
	m_audioMap[mapKey] = m_buffer;
}
