#ifndef GRUNT_H
#define GRUNT_H
#include "Alien.h"
//-----------------------------------------------
//class			: Grunt
// Purpose		: used as a different alien
// Usage		:	
//				Grunt()
//				Grunt( const sf::Texture& texture, const int& destroyScore, const sf::SoundBuffer& soundEffect )
//				virtual void dive( sf::Vector2f& playerPosition ) override
//					
// See also	: 
//-----------------------------------------------
class Grunt : public Alien
{

private:
	std::vector < std::vector<sf::Vector2f>> m_diveOnePoints; // The path of points the grunt uses to dive 
public:
	//-----------------------------------------------
	// Function		: Grunt
	// Purpose		: default class constructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	Grunt();
	//-----------------------------------------------
	// Function		: Grunt
	// Purpose		: load in a texture from manger 
	// Parameters	: const sf::Texture& texture, const int& destroyScore, const sf::SoundBuffer& soundEffect
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	Grunt( const sf::Texture& texture, const int& destroyScore, const sf::SoundBuffer& soundEffect );
	//-----------------------------------------------
	// Function		: dive
	// Purpose		: overide parents dive path
	// Parameters	:  const sf::Vector2f& playerPosition
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	virtual void dive( const sf::Vector2f&  playerPosition ) override;

};


#endif // GRUNT_H

