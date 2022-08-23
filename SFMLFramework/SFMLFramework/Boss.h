#ifndef BOSS_H
#define BOSS_H

#include "Alien.h"

//-----------------------------------------------
//class			: Boss
// Purpose		: A harder alien that in the future would have different functions 
// Usage		:	
//					Boss();
//					Boss( const sf::Texture& texture, const int& destroyScore, const sf::SoundBuffer& soundEffect );
//					~Boss();
//					
// See also	: 
//-----------------------------------------------
class Boss : public Alien
{
private:
public:
	//-----------------------------------------------
	// Function		: Boss()
	// Purpose		: default Constructor 
	// Parameters	: N/A
	// Returns		: void 
	// Notes		: N/A
	// See also		:
	//-----------------------------------------------
	Boss();
	//-----------------------------------------------
	// Function		: Boss(const sf::Texture& texture, const int& destroyScore , const sf::SoundBuffer& soundEffect)
	// Purpose		: Used to pass in dfferent settings 
	// Parameters	: const sf::Texture& texture, const int& destroyScore , const sf::SoundBuffer& soundEffect
	// Returns		: void 
	// Notes		: N/A
	// See also		:
	//-----------------------------------------------
	Boss( const sf::Texture& texture, const int& destroyScore , const sf::SoundBuffer& soundEffect );
	//-----------------------------------------------
	// Function		: ~Boss()
	// Purpose		: default deconstructor 
	// Parameters	: N/A
	// Returns		: void 
	// Notes		: N/A
	// See also		:
	//-----------------------------------------------
	~Boss();

};

#endif // !BOSS_H

