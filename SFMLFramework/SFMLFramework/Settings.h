#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Graphics.hpp>

#include "AlienStatus.h"
//-----------------------------------------------
//namespace		: Settings
// Purpose		: To store all the default values for game game objects
// See also	: 
//-----------------------------------------------
namespace Settings
{
	//----------------------------------------------------------------------------------------------
	// General Settings
	//----------------------------------------------------------------------------------------------
	const unsigned int			k_windowWidth = 800;									// Window screen Width
	const unsigned int			k_windowHeight = 800;									// Window screen Height
	const float					k_arenaTop = 0.0f;										// Top of the arena
	const float					k_arenaLeft = 0.0f;										// Left side of the arena 
	const float					k_arenaWidth = 600.0f;									// Playerable arena as a float
	const float					k_arenaHeight = static_cast<float>( k_windowHeight );   // Playerable arena as a float
	const int					k_amountOfBullets = 300;								// The amount of bullets that can object pooled.
	const float					k_bulletSpeed = 500.0f;									// Speed of bullet
	const int					k_frameRate = 60;										// Game frame rate
	const sf::Vector2f          k_backgroundPositionMenu( 400.0f, 400.0f );				// Position of the background in the mm
	const sf::Vector2f          k_backgroundPositionGame( 200.0f, 400.0f );				// Position of bg on game screen
	const float					k_animationFrameRate = 15.0f;							// Frame rat which animation runs
	const int					k_backgroundFrameCount = 4;								// The amount of frames in the background
	const int					k_explosionFrameCount = 8;								// Frames for explison animation
	const int					k_startingWave = 0;										// Game starting wave 
	const int					k_amountOfHighScores = 10;								// Amount of highscores saved
	const int					k_amountOfFormationFiles = 7;							// The amount of different formation files.
	const int					k_backgroundVolume (5);									// BG vol
	//----------------------------------------------------------------------------------------------
	// Player Settings
	//----------------------------------------------------------------------------------------------
	const float					k_playerShootingRotation = 0.0f;						// Player Shooting Rotation
	const sf::Vector2f			k_playerFireDirection( 0.0f, -1.0f );					// Direction the player fires 
	const float					k_playerDampMutiplyer = 0.07f;							// The amount the player slides after an input
	const float					k_playerRespawnTime = 1.5f;								// Time it takes for player to respawn
	const int					k_numLives = 3;											// Number of ships left 
	const float					k_playerFireRate = 0.55f;								// firerate in secounds for standard shooting;
	const sf::Vector2f			k_shipStartPosition( 150.0f, 800.0f );					// Starting pos of the ship
	const float					k_shipMovementBounds = 600;								// Bounds of where the ship can go 
	const float					k_playerSpeed = 500.0f;									// Default player speed 
	//----------------------------------------------------------------------------------------------
	// Alien Settings
	//----------------------------------------------------------------------------------------------
	const sf::Vector2f			k_gridStartingPosition( 120.0f, 180.0f );               // The point where the formation of aliens is drawn from
	const sf::Vector2i			k_gridSize( 5, 10 );									// The default size of the alien formation
	const float					k_AlienSpeed = 650.0f;									// The speed of which aliens move at 
	const int					k_formationGapSize = 45;								// The gap between each alien in the formation
	const float					k_alienFormationRotation = 0.0f;						// Default rotation while the alien is in formation
	const AlienStatus			k_startingAlienState = AlienStatus::Idle;				// Starting states of aliens
	const sf::Vector2f			k_aliensOffScreenPos( -20.00f, -10.00f );				// Posistion to hide alein off screen 
	const float					k_flyInGap = 0.3f;										// The gap between each alien flying in at the start of the game.
	const float					k_alienDiveRate = 4.20f;								// The rate the alien dives 
	const int					k_flyDestroyScore = 100;								// The Score gained for destroying a fly
	const int					k_gruntDestroyScore = 300;								// The score gained for destroying grunt
	const int					k_bossDestroyScore = 350;								// Score gained for destroying boss
	const float					k_alienFireRate = 0.7f;									// Alien rate of fire
	const int					k_setAlienSize = 8;										// The size of alien sets 
	const float					k_alienWorldAngleCorrection = 90;						// Angle correction for alien sprite
	const float					k_alienSpeedDiffcutlyMutipler = 12.5f;					// Mutipler that increase speed depening on wave count
	const float					k_alienFireRateDiffcutlyMutipler = 0.02f;				// The change of fireRate depending on wave count
	const float					k_alienMaxSpeed = 1000.0f;								// Max Alien speed
	const float					k_maxFireRate = 0.55f;									// Max alien fire rate (lower is more)
	const sf::Vector2f			k_alienFireDirection( 0.0f, 1.0f );						// Direction the alien fires 
	const float					k_alienShootingRotation = 180.0f;						// Alien shooting rotation
	//----------------------------------------------------------------------------------------------
}
namespace MovementPoints
{
	//----------------------------------------------------------------------------------------------
	// Movement Points - Store the fly in paths of the aliens 
	//----------------------------------------------------------------------------------------------
	const std::vector < std::vector<sf::Vector2f>> k_setOneCurvePoints{ std::vector<sf::Vector2f> {sf::Vector2f( 350.0f, 0.0f ),sf::Vector2f( 800.0f, 462.0f ),sf::Vector2f( 335.0f, 810.0f ),sf::Vector2f( 0.0f, 0.0f )} };
	const std::vector < std::vector<sf::Vector2f>> k_setOneCurvePointsTwo{ std::vector<sf::Vector2f> {sf::Vector2f( 450.0f, 0.0f ), sf::Vector2f( 0.0f, 462.0f ),sf::Vector2f( 200.0f, 810.0f ),sf::Vector2f( 0.0f, 0.0f )} };
	const std::vector < std::vector<sf::Vector2f>> k_setTwoCurvePoints{ std::vector<sf::Vector2f> { sf::Vector2f( 0.0f, 600.0f ), sf::Vector2f( 600.0f,600.0f ), sf::Vector2f( 400.0f,400.0f ),sf::Vector2f( 300.0f,400.0f )}, std::vector<sf::Vector2f>{ sf::Vector2f( 300.0f, 400.0f ),sf::Vector2f( 0.0f,410.0f ), sf::Vector2f( 100.0f, 600.0f ), sf::Vector2f( 400.0f, 550.0f )},std::vector<sf::Vector2f>{ sf::Vector2f( 400.0f, 550.0f ),sf::Vector2f( 0.0f, 0.0f )} };
	const std::vector < std::vector<sf::Vector2f>> k_setThreeCurvePoints{ std::vector<sf::Vector2f> { sf::Vector2f( Settings::k_arenaWidth, 600.0f ),sf::Vector2f( 0, 600.0f ),sf::Vector2f( 0, 400.0f ),sf::Vector2f( 300.0f, 400.0f )},std::vector<sf::Vector2f>{  sf::Vector2f( 300.0f, 400.0f ),sf::Vector2f( 600.0f, 410.0f ),sf::Vector2f( 500.0f, 600.0f ), sf::Vector2f( 200.0f, 550.0f )},std::vector<sf::Vector2f>{sf::Vector2f( 350.0f, 550.0f ),sf::Vector2f( 0.0f, 0.0f )} };
	const std::vector < std::vector<sf::Vector2f>> k_setFourCurvePoints{ std::vector<sf::Vector2f> {sf::Vector2f( 50.0f ,0.0f ),sf::Vector2f( 50.0f ,600.0f ), sf::Vector2f( 350.0f,800.0f ),sf::Vector2f( 0.0f,0.0f )} };
	const std::vector < std::vector<sf::Vector2f>> k_setFiveCurvePoints{ std::vector<sf::Vector2f>{sf::Vector2f( 550.0f,0.0f ),sf::Vector2f( 550.0f,600.0f ), sf::Vector2f( 250.0f , 800.0f ),sf::Vector2f( 0.0f ,0.0f )} };
}

namespace TextSetting
{
	//----------------------------------------------------------------------------------------------
	// Text Settings - Position , Character Size & Strings of game text 
	//----------------------------------------------------------------------------------------------
	const sf::Vector2f	k_mainMenuPos						( 95.0f, 350.0f );
	const int			k_mainMenuFontSize					( 20 );
	const sf::Vector2f	k_gameOverPos						( 300.0f, 280.0f );
	const sf::Vector2f	k_scoreGameOverPos					( 300.0f, 320.0f );
	const int			k_scoreGameOverFontSize				( 20 );
	const std::string	k_gameOverText						( "Game Over\n\n\n\n\n\n\n\n\n\n\n\n\n\n Press space" );
	const sf::Vector2f	k_scoreGamePlayPos					( 605.0f, 200.0f );
	const int			k_uiGamePlayFontSize				( 18 );
	const std::string	k_mainMenuText						( " Press enter to insert coin\n\n\n\n\n\n\n\n\n\n\n\n Press c to clean highscore table.\n(This cannot be undone)\n \nPress escape at any point to exit" );
	const sf::Vector2f	k_shipUIPos							( 640.0f, 300.0f );
	const sf::Vector2f	k_livesTextPos						( 668.0f, 295.0f );
	const sf::Vector2f	k_newPlayerTextPos					( 230.0f, 370.0f );
	const int			k_newPlayerTextSize					( 12 );
	const int			k_highScoreTextSize					( 15 );
	const int			k_playerNameCharacterLimt			( 10 );
	const sf::Vector2f	k_logoPos							( 395.0f, 50.0f );
	const sf::Vector2f	k_highScorePosMenu					( 250.0f, 395.0f );
	const sf::Vector2f	k_highScorePosGameOver				( 250.0f, 420.0f );
	const sf::Color		k_mainMenuTextColour				( 255, 255, 0, 255 );
	const float			k_textFadeRate						( 100.0f );
}


#endif // !Setting
