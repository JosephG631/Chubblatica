#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


#include "InputManager.h"
#include "ObjectManager.h"

InputManager::InputManager()
	:m_velocity ()
{
	
}

InputManager::~InputManager()
{
	// Decontructor 
}

void InputManager::update( PlayerShip& player,float& deltaTime , ObjectManager& objManager )
{
		// Check if any inputs pressed 
		checkGameInput( player, deltaTime, objManager );
}


void InputManager::checkGameInput(PlayerShip& player, float& deltaTime, ObjectManager& objManager )
{
	// Reset velocity 
	m_velocity.x = 0;
	m_velocity.y = 0;
	
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) ||  sf::Keyboard::isKeyPressed( sf::Keyboard::S  ))
	{
		// Set direction to go down
		m_velocity.y = player.getSpeed();
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up) || sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
	{
		// Set direction to Up
		m_velocity.y = -player.getSpeed();
		
	}

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
	{
		// Set direction to go left 
		m_velocity.x = -player.getSpeed();
	}
	
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed( sf::Keyboard::D ))
	{
		// Set direction to go right. 
		m_velocity.x = player.getSpeed();
	}
	if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
	{
		// Fire a projecttile 

		player.shoot( objManager );
	}
	if ( m_velocity != sf::Vector2f( 0, 0 ) )
	{

	   // Update player Velocity if its not 0
		player.setVelocity( m_velocity );
	}

	// Move player 
	player.movePlayer( deltaTime );
}


