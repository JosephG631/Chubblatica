#ifndef ALIEN_H
#define ALIEN_H
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/System/Clock.hpp>

#include "AlienStatus.h"
#include "GameSprite.h"
#include "GameSound.h"
#include "ObjectManager.h"
//-----------------------------------------------
//class			: Alien
// Purpose		: Class to control  the default indvisual alien
// Usage		:	
//				void lockInFormation()
//				void checkResetMove( std::vector < std::vector<sf::Vector2f>> points, int& loopCount )
//				void moveAlongCurve( const sf::Vector2f& pointOne, const sf::Vector2f& pointTwo, const sf::Vector2f& pointThree, const sf::Vector2f& pointFour, const float& deltaTime )
//				void moveAlongLerp( const sf::Vector2f& pointOne, const sf::Vector2f& pointTwo, const float& deltaTime )
//				void shoot( ObjectManager& objectManager );
//				void moveAlien( float& deltaTime, std::vector < std::vector<sf::Vector2f>> points )
//				Alien()
//				Alien( const sf::Texture& texture, const int& destroyScore, const sf::SoundBuffer& soundEffect )
//				virtual ~Alien()
//				void update( float& deltaTime, ObjectManager& objectManager )
//				void setFormationPosition( const sf::Vector2f& Vector )
//				const AlienStatus& getState() const
//				void setState( const  AlienStatus& state )
//				virtual void dive( sf::Vector2f& playerPosition )
//				void setArrayIndex( int m_arrayIndex )
//				void setMovementPoints( std::vector < std::vector<sf::Vector2f>>& movementPoints )
//				void setDivePoints( std::vector < std::vector<sf::Vector2f>>& divePoints )
//				const sf::Vector2f getFormationPosition() const
//				void setLerpSpeed( float speed )
//				const int& getDestroyScore() const;
// See also	: AlienWave.h,Grunt.h,Boss.h
//-----------------------------------------------
class Alien : public  GameSprite
{
private:
	const float										m_xBounds;											// The sprite x bounds
	const float										m_yBounds;											// The sprite y bounds
	float											m_lerpSpeed;										// Speed alien travels across a lerp
	sf::Vector2f									m_formationPosition;								// The posistion in the formation for that alien
	sf::Vector2f									m_targetPosition;									// Calculated target position after movement is applied 
	float											m_speed;											// Speed of the alien 
	const float										m_defaultLerpSpeed;									// Stores the value used to reset the lerp speed
	AlienStatus										m_currentState;										// Used to track what state the alien is in
	const float										m_defaultFormationRotation;							// Stores the correct rotation for the alien while its in formation
	const float										m_worldAngleCorrection;								// Used to correct rotation 
	int												m_arrayIndex;										// Stores the array index of potential movement points. 
	sf::Vector2f									m_lookAtPoint;										// Position of where the alien looks towards
	const int										m_destroyScore;										// Score Gain by killing alien
	std::vector < std::vector<sf::Vector2f>>		m_diveOnePoints;									// Points of diving.
	std::vector < std::vector<sf::Vector2f>>		m_movementPoints;									// Used to set the path of fly ins
	sf::Clock										m_clock;											// Clock to used as a timer to apply fire rate. 
	sf::Time										m_shootTimer;										// Store the time between shots 
	float											m_fireRate;											// Fire rate of the alien
	GameSound										m_alienShootSound;									// Sound when alien shoots 
	const float										m_speedDiffuctlyMutipler;							// A multiplier that increase the speed while the game is beening played
	const float										m_fireRateMutiplyer;								// A mutiplier to make the aliens fire quicker 
	const sf::Vector2f								m_fireDirection;									// Direction the alien fires 
	const float										m_shootRotation;									// The angle the alien shoots at
	
	//-----------------------------------------------
	// Function		: lockInFormation
	// Purpose		: when alien has flown in lock to formation
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: moveAlien
	//-----------------------------------------------
	void lockInFormation();
	//-----------------------------------------------
	// Function		: checkResetMove
	// Purpose		: check to see if an alien has completed its current curve/lerp
	// Parameters	:  std::vector < std::vector<sf::Vector2f>> points , int& loopCount
	// Returns		: void
	// Notes		: N/A
	// See also		: moveAlien
	//-----------------------------------------------
	void checkResetMove( std::vector < std::vector<sf::Vector2f>> points, int& loopCount );
	//-----------------------------------------------
	// Function		: moveAlongCurve
	// Purpose		: when a alien needs to move along  a curve calculate
	// Parameters	:  const sf::Vector2f& pointOne, const sf::Vector2f& pointTwo, const sf::Vector2f& pointThree, const sf::Vector2f& pointFour , const float& deltaTime
	// Returns		: void
	// Notes		: N/A
	// See also		: moveAlien
	//-----------------------------------------------
	void moveAlongCurve( const sf::Vector2f& pointOne, const sf::Vector2f& pointTwo, const sf::Vector2f& pointThree, const sf::Vector2f& pointFour , const float& deltaTime );
	//-----------------------------------------------
	// Function		: moveAlongLerp
	// Purpose		: move alien along a lerp 
	// Parameters	: const sf::Vector2f& pointOne, const sf::Vector2f& pointTwo, const float& deltaTime 
	// Returns		: void
	// Notes		: 
	// See also		: moveAlien
	//-----------------------------------------------
	void moveAlongLerp( const sf::Vector2f& pointOne, const sf::Vector2f& pointTwo, const float& deltaTime );
	//-----------------------------------------------
	// Function		: shoot
	// Purpose		: get the alien to shoot 
	// Parameters	: ObjectManager& objectManager
	// Returns		: void
	// Notes		: N/A
	// See also		: ObjectManager.h
	//-----------------------------------------------
	void shoot( ObjectManager& objectManager );
	//-----------------------------------------------
	// Function		: moveAlien
	// Purpose		: Move the alien within their set patern
	// Parameters	: float& deltaTime, std::vector < std::vector<sf::Vector2f>> points
	// Returns		: void
	// Notes		: N/A
	// See also		: moveAlongCurve,moveAlongfLerp
	//-----------------------------------------------
	void moveAlien( float& deltaTime, std::vector < std::vector<sf::Vector2f>> points );
public:
	//-----------------------------------------------
	// Function		: Alien
	// Purpose		: default constructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	Alien();
	//-----------------------------------------------
	// Function		: Alien
	// Purpose		: used when texture manager is in use 
	// Parameters	: const sf::Texture& texture, const int& destroyScore, const sf::SoundBuffer& soundEffect
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	Alien( const sf::Texture& texture, const int& destroyScore, const sf::SoundBuffer& soundEffect );
	//-----------------------------------------------
	// Function		: ~alien
	// Purpose		: default deconstructor
	// Parameters	:  N/A
	// Returns		: void
	// Notes		: Don't call
	// See also		: 
	//-----------------------------------------------
	virtual ~Alien();
	//-----------------------------------------------
	// Function		: Update
	// Purpose		: Update a single alien
	// Parameters	: float& deltaTime, ObjectManager& objectManager
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void update( float& deltaTime,   ObjectManager& objectManager ); 
	//-----------------------------------------------
	// Function		:  setFormationPosition
	// Purpose		: set the position for the formation
	// Parameters	:  const sf::Vector2f& Vector
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void setFormationPosition( const sf::Vector2f& Vector );
	//-----------------------------------------------
	// Function		: GetState
	// Purpose		: Return the current status of the alien
	// Parameters	: N/A
	// Returns		: m_currentStatus 
	// Notes		: 
	// See also		: setState
	//-----------------------------------------------
	const AlienStatus& getState() const ;
	//-----------------------------------------------
	// Function		: setState
	// Purpose		: set the current status of the alien
	// Parameters	: AlienStatus state
	// Returns		: void
	// Notes		: 
	// See also		: getState
	//-----------------------------------------------
	void setState( const  AlienStatus& state );
	//-----------------------------------------------
	// Function		: dive 
	// Purpose		: to set the paths of diving aliens 
	// Parameters	: const sf::Vector2f& playerPosition
	// Returns		: void
	// Notes		: overrides from the child as they different paths 
	// See also		: 
	//-----------------------------------------------
	virtual void dive( const sf::Vector2f& playerPosition );
	//-----------------------------------------------
	// Function		: setArrayIndex
	// Purpose		: reset the movement array index 
	// Parameters	: int m_arrayIndex 
	// Returns		: void
	// Notes		: N/A
	// See also		: moveAlien
	//-----------------------------------------------
	void setArrayIndex( int m_arrayIndex );
	//-----------------------------------------------
	// Function		: setMovementPoints 
	// Purpose		: set the movement points for flyins 
	// Parameters	: std::vector < std::vector<sf::Vector2f>>& movementPoints
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void setMovementPoints( std::vector < std::vector<sf::Vector2f>>& movementPoints );
	//-----------------------------------------------
	// Function		: setDivePoints
	// Purpose		: set the path for dives 
	// Parameters	: std::vector < std::vector<sf::Vector2f>>& divePoints
	// Returns		: void
	// Notes		: N/A
	// See also		:
	//-----------------------------------------------
	void setDivePoints( std::vector < std::vector<sf::Vector2f>>& divePoints );
	//-----------------------------------------------
	// Function		: getFormationPosition
	// Purpose		: returns the formation position of alien 
	// Parameters	: n/a
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	const sf::Vector2f getFormationPosition() const;
	//-----------------------------------------------
	// Function		: setLerpSpeed
	// Purpose		: reset lerping speed for a new movement 
	// Parameters	: float speed
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void setLerpSpeed( float speed );
	//-----------------------------------------------
	// Function		: getDestroyScore 
	// Purpose		: return the score you get for destroying 
	// Parameters	: N/A
	// Returns		: m_destroyScore 
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	const int& getDestroyScore() const;
	//-----------------------------------------------
	// Function		: increaseDiffuclty
	// Purpose		: increase the dfficulty of the game by the waveCount
	// Parameters	: const int& waveCount
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void increaseDiffuctly( const int& waveCount );
};
#endif // !Alien

