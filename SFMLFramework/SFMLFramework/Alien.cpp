#define _USE_MATH_DEFINES

#include <cmath>
#include <math.h>
#include <SFML/System/Clock.hpp>

#include "Alien.h"
#include "AlienStatus.h"
#include "Helpers.h"
#include "Settings.h"

Alien::Alien()
	: m_xBounds						( getTextureDimensions().x * 0.5f )
	, m_yBounds						( getTextureDimensions().y * 0.5f )
	, m_lerpSpeed					( 0 )
	, m_defaultLerpSpeed			( 0 )
	, m_speed						( Settings::k_AlienSpeed )
	, m_currentState				( Settings::k_startingAlienState )
	, m_defaultFormationRotation	( Settings::k_alienFormationRotation )
	, m_arrayIndex					( 0 )
	, m_worldAngleCorrection		( Settings::k_alienWorldAngleCorrection )
	, m_destroyScore				( Settings::k_flyDestroyScore )
	, m_fireRate					( Settings::k_alienFireRate )
	, m_speedDiffuctlyMutipler		( Settings::k_alienSpeedDiffcutlyMutipler )
	, m_fireRateMutiplyer			( Settings::k_alienFireRateDiffcutlyMutipler )
	, m_fireDirection				( Settings::k_alienFireDirection )
	,m_shootRotation				( Settings::k_alienShootingRotation )
{
	// Load Alien texture 
	loadTexture( "Assets/Textures/fly.png" );

	// Set off screen starting positons 
	setPosition( Settings::k_aliensOffScreenPos );

	// Load alien shoot sound
	m_alienShootSound.load( "Assets/Audio/ShootTwo.wav" );
}
Alien::Alien( const sf::Texture& texture, const int& destroyScore, const sf::SoundBuffer& soundEffect )
	: GameSprite						( texture )
	, m_xBounds							( getTextureDimensions().x * 0.5f )
	, m_yBounds							( getTextureDimensions().y * 0.5f )
	, m_lerpSpeed						( 0 )
	, m_defaultLerpSpeed				( 0 )
	, m_speed							( Settings::k_AlienSpeed )
	, m_currentState					( Settings::k_startingAlienState )
	, m_defaultFormationRotation		( Settings::k_alienFormationRotation )
	, m_arrayIndex						( 0 )
	, m_worldAngleCorrection			( Settings::k_alienWorldAngleCorrection )
	, m_destroyScore					( destroyScore )
	, m_fireRate						( Settings::k_alienFireRate )
	, m_alienShootSound					( soundEffect )
	, m_speedDiffuctlyMutipler			( Settings::k_alienSpeedDiffcutlyMutipler )
	, m_fireRateMutiplyer				( Settings::k_alienFireRateDiffcutlyMutipler )
	, m_fireDirection					( Settings::k_alienFireDirection )
	, m_shootRotation					( Settings::k_alienShootingRotation )
	
{
	
	// Set to hide it off screen at start of game
	setPosition( Settings::k_aliensOffScreenPos );
}
Alien::~Alien()
{
	// Deconstructor
}

void Alien::update( float& deltaTime, ObjectManager& objectManager )
{

	// Update depending on current state of the game 
	switch ( m_currentState )
	{
	case AlienStatus::FlyIn: 
	{
		// Fly alien ins 
		moveAlien( deltaTime, m_movementPoints);
	}
	break;
	case AlienStatus::Dive:
	{
		// Dive aliens towards player 
		moveAlien( deltaTime, m_diveOnePoints );
		
		// Shoot towards player 
		shoot( objectManager );
	}
	break;
	default:
	{
		// Default 
	}
	break;
	}
}

void Alien::setFormationPosition( const sf::Vector2f& Vector )
{
	// Setting the formation position of the alien
	m_formationPosition = Vector;
	
}



void Alien::moveAlien( float& deltaTime, std::vector < std::vector<sf::Vector2f>> points )
{
	
		// Get the size of the first dimension in the 2D Array
		int loopCount = points.size();

		// Store a temporay angle
		float angle;

		// keep the array of points within range 
		if ( m_arrayIndex < loopCount  )
		{
			// If the second dimenision in the 2D array includes more than 2 vectors means its a curve 
			if ( points[m_arrayIndex].size() > 2 )
			{
				// Check to see if this is the last movement for this set, if so set last position to formation position 
				if ( m_arrayIndex == loopCount - 1 && points[m_arrayIndex][3] == sf::Vector2f( 0.0f, 0.0f ) )
				{
					points[m_arrayIndex][3] = m_formationPosition;
				}

				// Curve Alien
				moveAlongCurve( points[m_arrayIndex][0], points[m_arrayIndex][1], points[m_arrayIndex][2], points[m_arrayIndex][3], deltaTime );

			}
			//  If the second dimenision in the 2D array includes less than two vectors means its a lerp
			else
			{
			// Check to see if this is the last movement for this set, if so set last position to formation position 
			if ( m_arrayIndex == loopCount - 1 )
			{
				points[m_arrayIndex][1] = m_formationPosition;
			}
			// Lerp Alien
			moveAlongLerp( points[m_arrayIndex][0], points[m_arrayIndex][1], deltaTime );
			}
			// Work out the angle to look at the target in radians then convert to degrees 
			angle = atan2( m_lookAtPoint.y - getPosition().y, m_lookAtPoint.x - getPosition().x ) * 180.0f / (float)M_PI;

			// set the rotatation to the correct angle by adjusting to the correct world rotaiton. 
			setRotation( angle + m_worldAngleCorrection );

			// Update the position 
			setPosition( m_targetPosition );


		}
		//  Check if movement needs to be reset 
		checkResetMove( points, loopCount );

}


void Alien::dive( const sf::Vector2f& playerPosition )
{
	// Set up dive points relitive to formation & player Position 
	m_diveOnePoints = { std::vector<sf::Vector2f>{m_formationPosition,sf::Vector2f( m_formationPosition.x, m_formationPosition.y - 150.0f ) }
	,std::vector<sf::Vector2f>{sf::Vector2f( m_formationPosition.x, m_formationPosition.y - 150.0f ),sf::Vector2f( m_formationPosition.x + 280.0f, m_formationPosition.y - 200.0f ), sf::Vector2f( m_formationPosition.x + 280.0f, m_formationPosition.y + 40.0f ),sf::Vector2f( m_formationPosition.x - 50.0f, playerPosition.y )},
		std::vector<sf::Vector2f>{sf::Vector2f( m_formationPosition.x - 50.0f, playerPosition.y ),sf::Vector2f( m_formationPosition.x - 200.0f, playerPosition.y ),sf::Vector2f( m_formationPosition.x - 230.0f, 580.0f ) ,sf::Vector2f( m_formationPosition.x ,m_formationPosition.y )} };


}






void Alien::increaseDiffuctly( const int& waveCount )
{
	
	if ( m_speed < Settings::k_alienMaxSpeed )
	{
		// Increase speed depending on how high wave is 
		m_speed += (m_speedDiffuctlyMutipler* waveCount);

	}
	if ( m_fireRate > Settings::k_maxFireRate )
	{
		// Increase fireRate depending on how highwave is 
		m_fireRate -= (m_fireRateMutiplyer * waveCount);
	}

}





void Alien::moveAlongCurve( const sf::Vector2f& pointOne, const sf::Vector2f& pointTwo, const sf::Vector2f& pointThree, const sf::Vector2f& pointFour, const float& deltaTime )
{
	//  Working Out the speed to travel across the curve. This to ensure its consitent across all curves 
	m_lerpSpeed += ( m_speed * deltaTime ) / Math::bezierCurveLength( pointOne, pointTwo, pointThree, pointFour );

	// Calculate the curve for the alien using these points at the speed of curve speed
	m_targetPosition = Math::bezierCurve( pointOne, pointTwo, pointThree, pointFour, m_lerpSpeed );

	// Get the point where the Alien is meant to look at. if its a curve it will be the derivative of the curve
	m_lookAtPoint = Math::bezierDerivative( pointOne, pointTwo, pointThree, pointFour, m_lerpSpeed );

}

void Alien::moveAlongLerp( const sf::Vector2f& pointOne, const sf::Vector2f& pointTwo, const float& deltaTime )
{
	// work out speed
	m_lerpSpeed += ( m_speed * deltaTime ) / Math::distanceBetweenVectors( pointOne, pointTwo );

	// set look at point 
	m_lookAtPoint = pointTwo;

	// Work out lerp
	m_targetPosition = Math::lerp( pointOne, pointTwo, m_lerpSpeed );
}

void Alien::shoot( ObjectManager& objectManager )
{
	// get Time since last shot
	m_shootTimer = m_clock.getElapsedTime();


	// If the is shoot timer  greater than the firerate alien can fire 
	if ( m_shootTimer.asSeconds() > m_fireRate )
	{
		// Shoot when diving
		objectManager.shoot( getPosition(), false, m_fireDirection ,m_shootRotation );

		// Play shoot sound
		m_alienShootSound.play();
		// Reset Timer as bullet been fired 
		m_clock.restart();

	}
}

void Alien::lockInFormation()
{
	
	// Set default rotation 
	setRotation( m_defaultFormationRotation );
	
	// Update State
	m_currentState = AlienStatus::Formation;
}

void Alien::checkResetMove( std::vector<std::vector<sf::Vector2f>> points, int& loopCount )
{
	// Keep point array within Range
	if ( m_arrayIndex < loopCount )
	{
		// If curve
		if ( points[m_arrayIndex].size() > 2 )
		{
			// If the alien has completed move
			if ( points[m_arrayIndex][3] == getPosition() )
			{
				// Update index for the next set of points
				m_arrayIndex++;

				// reset  points 
				m_lerpSpeed = m_defaultLerpSpeed;
			}
		}
		else
		{
			if ( points[m_arrayIndex][1] == getPosition()  )
			{
				// Update index for the next set of points
				m_arrayIndex++;

				// reset  points 
				m_lerpSpeed = m_defaultLerpSpeed;
			}
		}
		
	}
	// If the its last point is formation and its the last  movement out of the set 
	if ( m_arrayIndex == loopCount  )
	{
		
		if ( getPosition() == m_formationPosition )
		{
			// Lock formation 
			lockInFormation();
		}
		
	}

}
// Getters & setter 
const AlienStatus& Alien::getState() const
{
	return m_currentState;
}

void Alien::setState( const  AlienStatus& state )
{
	m_currentState = state;
}

void Alien::setArrayIndex( int arrayIndex )
{
	m_arrayIndex = arrayIndex;
}

void Alien::setMovementPoints( std::vector<std::vector<sf::Vector2f>>& movementPoints )
{
	m_movementPoints = movementPoints;
}

void Alien::setDivePoints( std::vector<std::vector<sf::Vector2f>>& divePoints )
{
	m_diveOnePoints = divePoints;
}

const sf::Vector2f Alien::getFormationPosition() const
{
	return m_formationPosition;
}

void Alien::setLerpSpeed( float speed )
{
	m_lerpSpeed = speed;
}

const int& Alien::getDestroyScore() const
{
	return m_destroyScore;
}




