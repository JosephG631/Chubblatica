#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

#include "AnimatedGameSprite.h"
#include "GameSprite.h"
#include "GameSound.h"
#include "ObjectManager.h"


//-----------------------------------------------
//class			: PlayerShip
// Purpose		: To act as controllable character for the ship
// Usage		:	
//					PlayerShip()
//					PlayerShip( const sf::Texture& texture, const sf::SoundBuffer& soundEffect, const sf::Texture& explosion, const float& speed, const int& lives, const float& fireRate, const float& damping, const float& respawnTime )
//					void update( float& deltaTime )
//					void movePlayer( float& deltaTime )
//					void setVelocity( const sf::Vector2f& vector )
//					void shoot( ObjectManager& objManager )
//					void respawn()
//					void setLives( const int& lives )
//					const int& getLives() const
//					const float& getSpeed() const;
//					void renderExplosion( sf::RenderWindow* window )
//					const bool& getRespawning() const
//					void setExploding( bool explode )				
// See also	: 
//-----------------------------------------------
class PlayerShip : public GameSprite
{
private:
	float				m_speed;			// Speed for the player character 
	sf::Vector2f		m_velocity;			// The velocity of the players movement
	sf::Vector2f		m_targetPosition;   // The target position when movement been calculated 
	int					m_lives;			// The amount of lives the player has
	float				m_shipXBounds;		// The x bounds of the ship
    float				m_shipYBounds;		// Y bounds of ship
	sf::Clock			m_clock;			// clock to used as a timer to apply fire rate. 
	sf::Time			m_shootTimer;       // store the time between shots 
	sf::Time			m_respawnTimer;		// Timer for the lenght it takes to respawn
	sf::Clock			m_respawnClock;     // Clock used for respawns 
	const float			m_fireRate;         // fire rate of the player
	GameSound			m_shootSound;		// Shoot sound effect
	AnimatedGameSprite  m_explosion;		// Animated explosion apon death
	bool				m_explode;			// If the ship is exploding
	bool				m_respawning;		// If the ship is respawning
	const float			m_damping;			// The amount to damp movement
	const float         m_respawnTime;		// The amount of time it takes to respawn
	const sf::Vector2f	m_fireDirection;    // Direction the player fires in
	const float			m_shootRotation;	// The rotation of 
public:
	//-----------------------------------------------
	// Function		: PlayerShip
	// Purpose		: default class constructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	PlayerShip();
	//-----------------------------------------------
	// Function		: PlayerShip
	// Purpose		:  class constructor with settings as paramaters,
	// Parameters	: const sf::Texture& texture,const sf::SoundBuffer& soundEffect, const sf::Texture& explosion, const float& speed, const int& lives, const float& fireRate, const float& damping, const float& respawnTime ,const sf::Vector2f& fireDirection, const float& shootRotation
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	PlayerShip( const sf::Texture& texture,const sf::SoundBuffer& soundEffect, const sf::Texture& explosion, const float& speed, const int& lives, const float& fireRate, const float& damping, const float& respawnTime, const sf::Vector2f& fireDirection, const float& shootRotation );
	//-----------------------------------------------
	// Function		: ~PlayerShip
	// Purpose		: class deconstructor 
	// Parameters	:  n/a
	// Returns		: void
	// Notes		: Don't call
	// See also		: 
	//-----------------------------------------------
	~PlayerShip();
	//-----------------------------------------------
	// Function		: update
	// Purpose		: update the entire  playership
	// Parameters	: float& deltaTime
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void update( float& deltaTime );
	//-----------------------------------------------
	// Function		: movePlayer 
	// Purpose		: move the player based on the keyboard inputs 
	// Parameters	:  float& deltaTime 
	// Returns		: void
	// Notes		: 
	// See also		: InputManager.h
	//-----------------------------------------------
	void movePlayer( float& deltaTime );
	//-----------------------------------------------
	// Function		: setVelocity
	// Purpose		: set the direction the player moves in
	// Parameters	: const sf::Vector2f& vector
	// Returns		: void
	// Notes		: 
	// See also		: InputManager.h
	//-----------------------------------------------
	void setVelocity(const sf::Vector2f& vector );
	//-----------------------------------------------
	// Function		: shoot
	// Purpose		: Shoot a projectie 
	// Parameters	: ObjectManager& objManager 
	// Returns		: void
	// Notes		: 
	// See also		: InputManager.h
	//-----------------------------------------------
	void shoot( ObjectManager& objManager );
	//-----------------------------------------------
	// Function		: respawn
	// Purpose		: respawn player at start pos 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void respawn( );
	//-----------------------------------------------
	// Function		: setLives
	// Purpose		: set the amount of lives the player house 
	// Parameters	: const int& lives  
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void setLives( const int& lives );
	//-----------------------------------------------
	// Function		: getLives
	// Purpose		: Shoot a projectie 
	// Parameters	: N/A
	// Returns		: int& m_lives
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	const int& getLives() const;
	//-----------------------------------------------
	// Function		: getSpeed
	// Purpose		: get speed of player
	// Parameters	: N/A
	// Returns		: const& m_speed
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	const float& getSpeed() const;
	//-----------------------------------------------
	// Function		: renderExplosion 
	// Purpose		: render explosion animation 
	// Parameters	: sf::RenderWindow* window
	// Returns		: void 
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	 const void renderExplosion( sf::RenderWindow* window ) const ;
	 //-----------------------------------------------
	// Function		: getRespawning
	// Purpose		: return if player is respawning 
	// Parameters	: N/A
	// Returns		: void 
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	const bool& getRespawning() const;
	//-----------------------------------------------
   // Function		: setExploding
   // Purpose		: if the player is currently exploding 
   // Parameters	: bool explode 
   // Returns		: void 
   // Notes			: N/A
   // See also		: 
   //-----------------------------------------------
	void setExploding( bool explode );
};


#endif // !PLAYERSHIP_H
