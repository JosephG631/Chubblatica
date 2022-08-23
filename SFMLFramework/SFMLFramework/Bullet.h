#ifndef BULLET_H
#define BULLET_H

#include <SFML/System/Time.hpp>

#include "GameSprite.h"

//-----------------------------------------------
//class			: Bullet 
// Purpose		: act as a prjectile that can be fired by player & AI 
// Usage		:	
//					void move( float& deltaTime)
//					Bullet()
//					~Bullet()
//					const bool getActiveState() const
//					void setActiveState( const bool& state )
//					void update( float& deltaTime )
//					void setDirection( const sf::Vector2f& direction )
//					void setPlayerFired( const bool& playerFired )
//					const bool& getPlayerFired() const
//					
// See also	: Ship.h
//-----------------------------------------------
class Bullet :public  GameSprite
{
private:
	bool				m_active;			// Check if the Object is active 
	const float			m_spriteYBounds;	// Get the bounds of the object
	const float			m_spriteXBounds;    // Get the bounds of the object
	float				m_speed;			// Speed of a moving bullet.
	sf::Vector2f		m_targetPosition;	// The position where the bullet moves towards 
	sf::Vector2f		m_direction;		// Direction of the moving bullet. 
	bool				m_playerFired;		// Check to see if player has fired it
	//-----------------------------------------------
	// Function		: move
	// Purpose		: move the bullet within the arena bounds
	// Parameters	: float& deltaTime
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void move( float& deltaTime );
public:
	//-----------------------------------------------
	// Function		: Bullet
	// Purpose		: default constructor 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	Bullet ();
	//-----------------------------------------------
	// Function		: Bullet
	// Purpose		: default deconstructor 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: don't call
	// See also		: 
	//-----------------------------------------------
	~Bullet();
	//-----------------------------------------------
	// Function		: getActiveState()
	// Purpose		: Get the state of the bullet 
	// Parameters	: N/A
	// Returns		: bool state 
	// Notes		: N/A
	// See also		: setActiveState 
	//-----------------------------------------------
	const bool getActiveState() const ;
	//-----------------------------------------------
	// Function		: setActiveState()
	// Purpose		: set the active state of the bullet 
	// Parameters	: const bool& state 
	// Returns		: void
	// Notes		: N/A
	// See also		: getActiveState 
	//-----------------------------------------------
	void setActiveState( const bool& state );
	//-----------------------------------------------
	// Function		: update
	// Purpose		: update the bullet 
	// Parameters	: float& deltaTime
	// Returns		: void
	// Notes		: N/A
	// See also		:
	//-----------------------------------------------
	void update( float& deltaTime ); 
	//-----------------------------------------------
	// Function		: setDirection
	// Purpose		: set the direction of the moving bullet
	// Parameters	: const sf::Vector2f& direction)
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void setDirection( const sf::Vector2f& direction );
	//-----------------------------------------------
	// Function		: setPlayerFired
	// Purpose		: set the player fired bool
	// Parameters	: const bool& playerFired
	// Returns		: void
	// Notes		: N/A
	// See also		: getPlayerFired()
	//-----------------------------------------------
	void setPlayerFired( const bool& playerFired );
	//-----------------------------------------------
	// Function		: get PlayerFired
	// Purpose		: get  the player fired bool
	// Parameters	: N/A
	// Returns		: const bool& playerFired
	// Notes		: N/A
	// See also		: setPlayerFired()
	//-----------------------------------------------
	const bool& getPlayerFired() const;
	
};

#endif // !BULLET_H

