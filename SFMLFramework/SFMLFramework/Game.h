#ifndef GAME_H
#define GAME_H
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML/System/Clock.hpp>

#include  "AlienWave.h"
#include  "AnimatedGameSprite.h"
#include  "AudioManager.h"
#include  "CollisionDetection.h"
#include  "GameStates.h"
#include  "GameText.h"
#include  "InputManager.h"
#include  "PlayerShip.h"
#include  "ObjectManager.h"
#include  "PlayerData.h"
#include  "TextureManager.h"
			
//-----------------------------------------------
//class			: Game
// Purpose		: To act as the main game play loop
// Usage		:	
//					void handleWindowsEvents( sf::Event event )
//					void update()
//					void render()
//					//void fadeMenuText( float& deltaTime )
//					void onEnterState( GameStates newState )
//					void stateChanged( GameStates newState )
//					Game()
//					~Game()
//					void run()
// See also	: 
//-----------------------------------------------
class Game
{
private:
	AudioManager			m_audioManager;			// Stores the audio so it only needs to be loaded once 
	sf::Context				context;				// Used to make open gl calls as context is required
	sf::RenderWindow*		m_pWindow;				// the game play window
	TextureManager			m_textureManager;		// Manages the whole games textures 
	PlayerShip				m_playerShip;			// playerable character 
	InputManager			m_inputManager;			// manages the users input for the whole game.
	sf::Clock				m_clock;				// clock to track game time.
	sf::Time				m_deltaTime;			// store games deltaTime 
	ObjectManager			m_objectManager;		// Used to manage object pools
	AlienWave				m_alienWave;			// contains the wave of aliens 
	CollisionDetection		m_collisionDetection;	// Used to detect collision between different game objects.
	AnimatedGameSprite      m_background;			// Background of the space.
	GameStates				m_currentGameState;		// The current state of the game. 
	GameText				m_mainMenuText;         // Text used to display mani mneu information 
	PlayerData				m_playerData;			// Used to store the player data and display it
	GameSound				m_backgroundMusic;		// Backgorund music
	GameSound				m_menuButtonSound;		// Sound when menu interacted with
	sf::Font				m_font;					// font used throughout the game
	GameSprite				m_logoSprite;			// Game Logo
	float					m_rgbColour;			// Game Text colour 
	bool					m_fadeText;				// bool for when text has faded 
	float					m_textFadeRate;			// The rate the text changes 
	
	//-----------------------------------------------
	// Function		: handleWindowEvents
	// Purpose		: to control the play window
	// Parameters	:  
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void handleWindowsEvents( sf::Event event );
	//-----------------------------------------------
	// Function		: update
	// Purpose		: Keep the whole updated by calling indvisual class updates
	// Parameters	:  
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void update();
	//-----------------------------------------------
	// Function		: render
	// Purpose		: Render all the game objects
	// Parameters	:  
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void render();
	//-----------------------------------------------
	// Function		: fadeMenuText
	// Purpose		: fade menu text on repeat
	// Parameters	: float& deltaTime
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void fadeMenuText( float& deltaTime );
	//-----------------------------------------------
	// Function		: onEnterState
	// Purpose		: when you enter a new state certain code will run for certain states 
	// Parameters	: GameStates newState
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void onEnterState( GameStates newState );
	//-----------------------------------------------
	// Function		: stateChanged
	// Purpose		: when you requrie to change the state call function
	// Parameters	: GameStates newState
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void stateChanged( GameStates newState );
public:
	//-----------------------------------------------
	// Function		: Game
	// Purpose		: default constructor
	// Parameters	:  
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	Game();
	//-----------------------------------------------
	// Function		: ~Game
	// Purpose		: deconstructor 
	// Parameters	:  
	// Returns		: void
	// Notes		: Don't call 
	// See also		: 
	//-----------------------------------------------
	~Game();
	//-----------------------------------------------
	// Function		: Run
	// Purpose		: run the entire game, call functions that need to happen every cyclc
	// Parameters	:  N/A
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void run();
};


#endif // !GAME_H

