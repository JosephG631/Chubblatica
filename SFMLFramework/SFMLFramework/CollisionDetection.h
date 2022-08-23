#ifndef COLLISIONDECTION_H
#define	COLLISIONDECTION_H

#include "AlienWave.h"

#include "GameSprite.h"
#include  "PlayerData.h"
#include "PlayerShip.h"
#include "ObjectManager.h"

//-----------------------------------------------
//class			: CollisionDectection
// Purpose		: To check collisions between gameobject
// Usage		:	
//					CollisionDetection();
//					CollisionDetection( const sf::SoundBuffer& alienEffect, const sf::SoundBuffer& playerEffect )
//					~CollisionDetection()
//					void update( ObjectManager& pool, AlienWave& wave, PlayerShip& player, PlayerData& playerData )
//					bool checkCollision( const GameSprite& gameObjectOne, const GameSprite& gameObjectTwo
// See also	: 
//-----------------------------------------------
class CollisionDetection
{
private:
	bool m_collided;					// Used to check if a collision has occurred
	GameSound	m_deathAlienSound;		// Alien sound when killed
	GameSound  m_deathPlayerSound;		// Player sound when killed 

public:
	//-----------------------------------------------
	// Function		: CollisionDetection
	// Purpose		: default constructor 
	// Parameters	:  N/A
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	CollisionDetection();
	//-----------------------------------------------
	// Function		: CollisionDetection(const sf::SoundBuffer& alienEffect , const sf::SoundBuffer& playerEffect)
	// Purpose		: Used to pass sound effects in 
	// Parameters	: const sf::SoundBuffer& alienEffect , const sf::SoundBuffer& playerEffect
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	CollisionDetection( const sf::SoundBuffer& alienEffect , const sf::SoundBuffer& playerEffect );
	//-----------------------------------------------
	// Function		: ~CollisionDetection
	// Purpose		: default decontructor 
	// Parameters	:  N/A
	// Returns		: void
	// Notes		: Don't call
	// See also		: 
	//-----------------------------------------------
	~CollisionDetection();
	//-----------------------------------------------
	// Function		: Update
	// Purpose		: To update the entire class and check for collsions
	// Parameters	: ObjectManager& pool, AlienWave& wave,PlayerShip& player, PlayerData& playerData
	// Returns		: void
	// Notes		: 
	// See also		: checkCollision()
	//-----------------------------------------------
	void update( ObjectManager& pool, AlienWave& wave,PlayerShip& player, PlayerData& playerData );
	//-----------------------------------------------
	// Function		: checkCollision
	// Purpose		: returns a bool if a collision happens between 2 objects 
	// Parameters	: const GameSprite& gameObjectOne,  const GameSprite& gameObjectTwo 
	// Returns		: void
	// Notes		: 
	// See also		: checkCollision()
	//-----------------------------------------------
	bool checkCollision(  const GameSprite& gameObjectOne,  const GameSprite& gameObjectTwo );
};


#endif // !COLLISIONDECTION_H

