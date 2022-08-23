#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <SFML/Window/Keyboard.hpp>


#include "PlayerShip.h"
#include "ObjectManager.h"
//-----------------------------------------------
//class			: InputManager
// Purpose		: Control all the user inputs 
// Usage		:	
//					void update()
//					void checkGameInput( PlayerShip& player, float& deltaTime, ObjectManager& objManager )
//					InputManager()
//					~InputManager()
//					void update( PlayerShip& player, float& deltaTime, ObjectManager& objManager )
// See also	: Ship.h
//-----------------------------------------------
class InputManager
{
private:
	sf::Vector2f m_velocity; // Used to work out veloctiy of player 
	
	//-----------------------------------------------
	// Function		: checkGameInput
	// Purpose		: check to see if an input has happend when game is playing 
	// Parameters	:  PlayerShip& player, float& deltaTime, ObjectManager& objManage
	// Returns		: void
	// Notes		: N/A
	// See also		: Update
	//-----------------------------------------------
	void checkGameInput( PlayerShip& player, float& deltaTime, ObjectManager& objManager );
	
public:									  

	//----------------------------------------------
	// Function		: InputManager
	// Purpose		: default class constructor
	// Parameters	:  
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	InputManager();
	//-----------------------------------------------
	// Function		: InputManager 
	// Purpose		: class deconstructor 
	// Parameters	:  
	// Returns		: void
	// Notes		: Don't call
	// See also		: 
	//-----------------------------------------------
	~InputManager();
	//-----------------------------------------------
	// Function		: update
	// Purpose		: check for inputs from user 
	// Parameters	: PlayerShip& player, float& deltaTime, ObjectManager& objManager 
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void update( PlayerShip& player, float& deltaTime, ObjectManager& objManager );
};


#endif // !INPUTMANAGER_H

