#include <SFML/Graphics.hpp>


#include "Helpers.h"
#include "PlayerShip.h"
#include "ObjectManager.h"
#include "Settings.h"

PlayerShip::PlayerShip()
	:m_speed			( Settings::k_playerSpeed )
	,m_lives			( Settings::k_numLives )
	, m_fireRate		( Settings::k_playerFireRate )
	, m_explosion		()
	, m_explode			( false )
	, m_respawning		( false )
	, m_damping			( Settings::k_playerDampMutiplyer )
	, m_respawnTime		( Settings::k_playerRespawnTime )
	,m_fireDirection	( Settings::k_playerFireDirection )
	, m_shootRotation	( Settings::k_playerShootingRotation )
{

	// Set to starting position
	setPosition( Settings::k_shipStartPosition );
	// Load assets manually 
	loadTexture( "Assets/Textures/Ship" );
	m_shootSound.load( "Assets/Audio/ShootOne.wav" );
	m_explosion.loadTexture( "Assets/Textures/explosion.png" );

	// Gets half the x & y length of the sprites texture (have to do it here as we need to set the texture first).
	m_shipXBounds = static_cast<float>( getTextureDimensions().x * 0.5f );
	m_shipYBounds = static_cast<float>( getTextureDimensions().y * 0.5f );
}

PlayerShip::PlayerShip( const sf::Texture& texture, const sf::SoundBuffer& soundEffect, const sf::Texture& explosion,const float& speed, const int& lives,const float& fireRate ,const float& damping , const float& respawnTime, const sf::Vector2f& fireDirection , const float& shootRotation )
	: m_speed			( speed )
	, m_lives			( lives )
	, m_fireRate		( fireRate )
	, m_shootSound		( soundEffect )
	, m_explosion		( explosion,Settings::k_explosionFrameCount,Settings::k_animationFrameRate )
	, m_explode			( false )
	, m_respawning		( false )
	, m_damping			( damping )
	, m_respawnTime		( respawnTime )
	, m_fireDirection	( fireDirection )
	, m_shootRotation   ( shootRotation )
{
	// Set to starting position
	setPosition( Settings::k_shipStartPosition );


	// Set up ship texture 
	setTexture( texture );
	setOriginToCenter( texture );

	// Gets half the x & y length of the sprites texture 
	m_shipXBounds = static_cast<float>( getTextureDimensions().x * 0.5f );
	m_shipYBounds = static_cast<float>( getTextureDimensions().y * 0.5f );

	
}

 PlayerShip::~PlayerShip()
{
	 // Deconstructor 
}

 void PlayerShip::update( float& deltaTime )
{
	 // If player is currently exploding 
	 if ( m_explode == true )
	 {
		 // Explode once 
		m_explode = m_explosion.animateOnce( deltaTime );
	 }

	 if ( m_respawning == true )
	 {
		 // Get time since respawn was called
		 m_respawnTimer = m_respawnClock.getElapsedTime();

		 // If passsed repsawn time
		 if ( m_respawnTimer.asSeconds() > Settings::k_playerRespawnTime )
		 {
			 // Respawn player 
			 setPosition( Settings::k_shipStartPosition );
			 m_respawning = false;
		 }
	 }
}

void PlayerShip::movePlayer ( float& deltaTime )
{
		
		// Get current position and caluculate target position 
		m_targetPosition = getPosition() + Math::normalize( m_velocity) * m_speed  * deltaTime;

		

		// Checking ships  target position is within game area and taking the size of the ship into account 
		if ( m_targetPosition.x < Settings::k_arenaLeft + m_shipXBounds )
		{
			m_targetPosition.x = 0 + m_shipXBounds;
		}

		// If the ships target  goes too far to the right of the screen
		if ( m_targetPosition.x > Settings::k_arenaWidth - m_shipXBounds )
		{
			// Set  target position to the furthest right position 
			m_targetPosition.x = Settings::k_arenaWidth - m_shipXBounds;
		}

		if ( m_targetPosition.y < Settings::k_shipMovementBounds - m_shipYBounds )
		{
			// Set target position to thehighest position within player bounds. (keeps ship within in a certain area
			m_targetPosition.y = Settings::k_shipMovementBounds - m_shipYBounds;
		}

		if ( m_targetPosition.y >Settings::k_arenaHeight - m_shipYBounds )
		{
			// Set target position to the lowest position within the player bounds 
			m_targetPosition.y = Settings::k_arenaHeight - m_shipYBounds;

		}
		

		// Update the ships position to the correct target position (move player). 
		setPosition( m_targetPosition );

		// Apply damp
		m_velocity *= m_damping;
}

void PlayerShip::setVelocity( const sf::Vector2f& vector )
{
	m_velocity = vector;
	
}

void PlayerShip::shoot( ObjectManager& objManager )
{
	// Shoot a bullet 
	m_shootTimer = m_clock.getElapsedTime();


	// If the is greater than the firerate ship can fire 
	if ( m_shootTimer.asSeconds() > m_fireRate && m_respawning == false )
	{
		// Fire relivitve to player position and in the direction of the aliens
		objManager.shoot( sf::Vector2f( getPosition().x,  getPosition().y - m_shipYBounds),true,m_fireDirection,m_shootRotation );

		// Play player shoot sound
		m_shootSound.play();

		// Reset firerate clock
		m_clock.restart();
	}
	
}


void PlayerShip::respawn()
{
	// Explode ship at players death position 
	m_explosion.setPosition( getPosition() );
	m_explode = true;

	// Player now responding won't render/collide 
	m_respawning = true;

	// Start respawn timer 
	m_respawnClock.restart();

	
}
void PlayerShip::setLives( const int& lives )
{
	m_lives = lives;
}

const int& PlayerShip::getLives() const
{
	return m_lives;
}

const float& PlayerShip::getSpeed() const
{
	return m_speed;
}

const void PlayerShip::renderExplosion( sf::RenderWindow* window ) const 
{
	// If exploding render explosion 
	if ( m_explode )
	{
		window->draw( m_explosion );
	}
}

const bool& PlayerShip::getRespawning() const
{
	return m_respawning;
}

void PlayerShip::setExploding( bool explode )
{
	m_explode = explode;
}










