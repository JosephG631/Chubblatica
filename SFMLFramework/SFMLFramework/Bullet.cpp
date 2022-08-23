#include <SFML/System/Time.hpp>

#include "Bullet.h"
#include  "Helpers.h"
#include "Settings.h"

Bullet::Bullet()
	: m_active			( false )
	,m_speed			( Settings::k_bulletSpeed )
	,m_spriteXBounds	( static_cast<float>( getTextureDimensions().x * 0.5f ) )
	,m_spriteYBounds	( static_cast<float>( getTextureDimensions().y * 0.5f ) )
	,m_playerFired		( false )
{

}


Bullet::~Bullet()
{
	// Deconstructor 
}


void Bullet::update( float& deltaTime )
{
	// If active in pool
	if ( m_active )
	{
		move( deltaTime );
	}
}

void Bullet::move( float& deltaTime )
{
	// Get current position and caluculate target position 
	m_targetPosition = getPosition() + Math::normalize( m_direction ) * m_speed * deltaTime;

	// Checking bullet  target position is within game area and taking the size of the bullet into account 
	if ( m_targetPosition.x < Settings::k_arenaLeft + m_spriteXBounds )
	{
		// Set to not active as its out of bounds
		setActiveState( false );
	}

	// If the bullet target  goes too far to the right of the screen
	if ( m_targetPosition.x > Settings::k_arenaWidth - m_spriteXBounds )
	{
		// Set to not active as its out of bounds
		setActiveState( false );
	}

	if ( m_targetPosition.y < Settings::k_arenaTop + m_spriteYBounds )
	{
		// Set to not active as its out of bounds
		setActiveState( false );
	}

	if ( m_targetPosition.y > Settings::k_arenaHeight - m_spriteYBounds )
	{
		// Set to not active as its out of bounds
		setActiveState( false );

	}

	// Update the bullet posistion to the correct target position.
	setPosition( m_targetPosition );
}

void Bullet::setDirection( const sf::Vector2f& direction )
{
	m_direction = direction;
}

void Bullet::setPlayerFired( const bool& playerFired )
{
	m_playerFired = playerFired;
}

const bool& Bullet::getPlayerFired() const
{
	return m_playerFired;
}


const bool Bullet::getActiveState() const
{
	return m_active;
}

void Bullet::setActiveState( const bool& state )
{
	m_active = state;
}
