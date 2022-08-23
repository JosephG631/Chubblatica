#include <SFML/Graphics.hpp>
#include <SFML/Window/Context.hpp>

#include "Game.h"
#include "GameStates.h"
#include "Helpers.h"
#include "Settings.h"

Game::Game()
	: m_audioManager			()
	, m_pWindow					( nullptr )
	, m_alienWave				( m_textureManager.getTexture( "Fly" ), m_textureManager.getTexture( "Grunt" ), m_textureManager.getTexture( "Boss" ), m_audioManager.getSoundBuffer( "ShootTwo" ), Settings::k_formationGapSize, Settings::k_gridSize, Settings::k_setAlienSize, Settings::k_flyInGap, Settings::k_alienDiveRate, Settings::k_startingWave, Settings::k_amountOfFormationFiles )
	, m_playerShip				( m_textureManager.getTexture( "Player" ), m_audioManager.getSoundBuffer( "ShootOne" ), m_textureManager.getTexture( "Explosion" ), Settings::k_playerSpeed, Settings::k_numLives, Settings::k_playerFireRate, Settings::k_playerDampMutiplyer, Settings::k_playerRespawnTime, Settings::k_playerFireDirection, Settings::k_playerShootingRotation )
	, m_objectManager			( m_textureManager.getTexture( "Bullet" ) )
	, m_background				( m_textureManager.getTexture( "Background" ), Settings::k_backgroundFrameCount,Settings::k_animationFrameRate )
	, m_currentGameState		( GameStates::MainMenu )
	, m_mainMenuText			( m_font )
	, m_playerData				( m_textureManager.getTexture( "UIShip" ), m_font,Settings::k_amountOfHighScores )
	, m_backgroundMusic			( m_audioManager.getSoundBuffer( "BackgroundMusic" ) )
	, m_collisionDetection		( m_audioManager.getSoundBuffer( "AlienDeath" ), m_audioManager.getSoundBuffer( "PlayerDeath" ) )
	, m_menuButtonSound			( m_audioManager.getSoundBuffer( "MenuSound" ) )
	, m_logoSprite				( m_textureManager.getTexture( "Logo" ) )
	, m_fadeText				( false )
	, m_rgbColour				( 0 )
	, m_textFadeRate			( TextSetting::k_textFadeRate )
	
{
	
	// Create the window to display the game
	m_pWindow = new sf::RenderWindow( sf::VideoMode( Settings::k_windowWidth, Settings::k_windowHeight ), "Chubblatica" );
	
	// Calculate the background ready for animation
	m_background.calculateAnimationFrame();

	// Set Position of background 
	m_background.setPosition(  Settings::k_backgroundPositionMenu);

	// Setting the max frames the game can run at
	m_pWindow->setFramerateLimit( Settings::k_frameRate ); 

	// Enable vertical sync 
	m_pWindow->setVerticalSyncEnabled( true );
	
	// Set Background music volume
	m_backgroundMusic.setVolume( 5 );
	// Start playing background music 
	m_backgroundMusic.play();

	// make music Loop
	m_backgroundMusic.setLoop( true );

	// Load font once ( I don't use a manager a I just use one)/
	bool loaded = m_font.loadFromFile("Assets/Font/emulogic.ttf");

	// Check to see if loaded correctly
	ASSERT( loaded == true );

	// Set up menu text
	m_mainMenuText.setString( TextSetting::k_mainMenuText );
	m_mainMenuText.setCharacterSize( TextSetting::k_mainMenuFontSize );
	m_mainMenuText.setPosition( TextSetting::k_mainMenuPos );

	m_logoSprite.setPosition( TextSetting::k_logoPos ); 
	
	m_mainMenuText.setFillColor(  TextSetting::k_mainMenuTextColour );

	
}

Game::~Game()
{
	// safely delete pointer 
	safeDelete( m_pWindow );
	
}

void Game::run()
{

	while ( m_pWindow->isOpen() )
	{
		sf::Event event{};
		
		// Handles all window events
		handleWindowsEvents( event );

		// Clear screen
		m_pWindow->clear();

		// Set deltaTime
		m_deltaTime = m_clock.restart();

		// Update all objetcs
		update();

		// Render game objects
		render();

		// Display rendered objects
		m_pWindow->display();
	}
}
void Game::update(  )
{
	// Convert deltaTime to secounds 
	float deltaTime = m_deltaTime.asSeconds();

	switch ( m_currentGameState )
	{
		case GameStates::MainMenu: 
		{
			// If key Pressed 
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Return ) )
			{
				// Play button sound 
				m_menuButtonSound.play();
				// Start game
				stateChanged( GameStates::GamePlay );
			}
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::C ) )
			{
				// If pressed reset highscore table
				m_playerData.clearScore();
				
			}
			// Update player data
			m_playerData.update( m_alienWave.getWaveCount(), m_playerShip.getLives() );
			
			fadeMenuText( deltaTime );

			// Animate background.
			m_background.update( deltaTime );
			
		}

		break;
		case GameStates::GamePlay: 
		{
			// Checking Inputs 
			m_inputManager.update( m_playerShip, deltaTime, m_objectManager);

			// Updating pooling
			m_objectManager.update( deltaTime );

			// Update every alien in wave 
			m_alienWave.update( deltaTime,m_playerShip.getPosition() ,m_objectManager);

			// Check for collisions between game objects
			m_collisionDetection.update( m_objectManager, m_alienWave, m_playerShip,m_playerData);

			// Update player
			m_playerShip.update( deltaTime);

			// Check to see if Player is alive 
			if ( m_playerShip.getLives() <= 0 && m_currentGameState == GameStates::GamePlay)
			{
				// if dead game over.
				stateChanged( GameStates::GameOver );
			}
			// Animate background.
			m_background.update( deltaTime );

			// Update player data
			m_playerData.update( m_alienWave.getWaveCount(),m_playerShip.getLives() );
		}
		break;
		case GameStates::GameOver:
		{
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) )
			{
				// Go back to main menu if key presed 
				stateChanged( GameStates::MainMenu);

				// Play button sound 
				m_menuButtonSound.play();
			}
			// Update player data
			m_playerData.update( m_alienWave.getWaveCount(), m_playerShip.getLives() );
		}
		break;
		default: 
		{

		}
		break;
	}
	
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ))
	{
		// Close winodw any time when escape is pressed. 
		m_pWindow->close();
	}
}

void Game::render()
{
	switch ( m_currentGameState )
	{
	case GameStates::MainMenu:
	{
		// Render Main menu UI
		m_pWindow->draw( m_background );
		m_pWindow->draw( m_mainMenuText );

		// Render for highscore
		m_pWindow->draw( m_playerData.getHighScoreText() );
		m_pWindow->draw( m_logoSprite );
		
	}

	break;
	case GameStates::GamePlay:
	{
		// Render all objectss
		m_pWindow->draw( m_background );
		// If ship is not in  the process of respawning 
		if ( m_playerShip.getRespawning() == false )
		{

			m_pWindow->draw( m_playerShip );
		}
		
		// Render all bullets 
		m_objectManager.renderBullets( m_pWindow );

		// Render Aliens 
		m_alienWave.render( m_pWindow );

		// Render socre & lifes etc
		m_playerData.render( m_pWindow ,m_currentGameState);

		// Render explosion effect
		m_playerShip.renderExplosion( m_pWindow );
	}
	break;
	case GameStates::GameOver:
	{
		// Render Game Over UI
		m_pWindow->draw( m_mainMenuText );
		m_playerData.render( m_pWindow , m_currentGameState );

	}
	break;
	default:
	{

	}
	break;
	}
	
	
}


void Game::fadeMenuText(float& deltaTime)
{
	// If Game text should fade 
	if ( m_fadeText == true )
	{
		// Change rgb colour over a fadeRate 
		m_rgbColour -= deltaTime * m_textFadeRate;
		
		// Once text has completely faded 
		if ( m_rgbColour <= 0 )
		{
			m_fadeText = false;
		}
	}
	// if rgbColour is less  8 bits meaning its full yellow 
	if ( m_rgbColour < 255 && m_fadeText == false )
	{
		// Increase colour 
		m_rgbColour += deltaTime * m_textFadeRate;
		// When max hit start fading 
		if ( m_rgbColour >= 255 )
		{
			m_fadeText = true;
		}
	}
	// Change the colour of text depening on the fade 
	m_mainMenuText.setFillColor( sf::Color( 255, static_cast<sf::Uint8>(m_rgbColour), 0, 255 ) );
}

void Game::onEnterState( GameStates newState )
{
	switch ( newState )
	{
	case GameStates::MainMenu:
	{
		// Change text back to main menu
		m_mainMenuText.setString( TextSetting::k_mainMenuText);
		
		// Reset Position 
		m_mainMenuText.setPosition( TextSetting::k_mainMenuPos ); 
		// Reset Colour 
		m_mainMenuText.setFillColor( sf::Color::White );
		m_playerData.getHighScoreText().setPosition( TextSetting::k_highScorePosMenu );
		// Set Background pos to suit menu
		m_background.setPosition( Settings::k_backgroundPositionMenu );
	}
	break;

	case GameStates::GamePlay:
	{
		
		// Reset score 
		m_playerData.setScore( 0 );
		// Reset Lives
		m_playerShip.setLives( Settings::k_numLives );
		// Reset score text
		m_playerData.getScoreText().setPosition( TextSetting::k_scoreGamePlayPos ); 
		m_playerData.getScoreText().setCharacterSize( TextSetting::k_uiGamePlayFontSize );
		// Set background pos for gameover
		m_background.setPosition( Settings::k_backgroundPositionGame );

		// Reset bullets 
		m_objectManager.setAllBullets( false );

		// Reset Wave Count 
		m_alienWave.setWaveCount( Settings::k_startingWave );

		//Make sure animation not playing
		m_playerShip.setExploding( false );
	}

	break;
	case GameStates::GameOver:
	{
		
		// Set Score Position to suit GameOver UI
		m_playerData.getScoreText().setPosition( TextSetting::k_scoreGameOverPos );

		// Set Score Font Size to suit GameOver UI
		m_playerData.getScoreText().setCharacterSize( TextSetting::k_scoreGameOverFontSize );
		m_playerData.getHighScoreText().setPosition( TextSetting::k_highScorePosGameOver );

		// Change Main menu Text. (I do this so I don't have loads of GameTexts)
		m_mainMenuText.setString( TextSetting::k_gameOverText );
		m_mainMenuText.setPosition( TextSetting::k_gameOverPos );
		m_mainMenuText.setFillColor( sf::Color::Red );

		// Work out if a highscore has been achieved
		m_playerData.calculateHighScore();
		// Reset formation text file 
		m_alienWave.setFormationCount( Settings::k_startingWave );

		// Reset Wave 
		m_alienWave.resetWave();
	}
	break;
	default:
	{
		// No state active 
	}
	break;
	}
}

void Game::stateChanged( GameStates newState )
{
	onEnterState( newState );
	m_currentGameState = newState;
}

void Game::handleWindowsEvents( sf::Event event )
{

	
	while ( m_pWindow->pollEvent( event ) )
	{
		if ( event.type == sf::Event::Closed )
			m_pWindow->close();

		// Check for key inputs so player can enter name 
		m_playerData.enterPlayerName( event, m_currentGameState );
	}
}

