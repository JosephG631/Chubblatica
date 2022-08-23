#ifndef PLAYERDATA_H
#define PLAYERDATA_H
#include <SFML/Graphics/RenderWindow.hpp>


#include"GameStates.h"
#include "GameText.h"
#include "GameSprite.h"
#include "Settings.h"
//-----------------------------------------------
//class			: PlayerData
// Purpose		: Stores & organises data relivant to the player 
// Usage		:	
//					void readScoreFile()
//					void writeScoreFile()
//					void setUpUIText()
//					PlayerData()
//					PlayerData( const sf::Texture& shipUITexture, const sf::Font& textFont, const int& amountOfHighScores )
//					~PlayerData()
//					void render( sf::RenderWindow* window, GameStates& gameState )
//					void update( const int& waveCount, const int& lives )
//					GameText& getScoreText()
//					void enterPlayerName( sf::Event event, const GameStates& gameState )
//					void calculateHighScore()
//					void clearScore()
//					void setScore( int score )
//					const int& getScore() const
//					GameText& getHighScoreText()
// See also	: 
//-----------------------------------------------
class PlayerData
{
private:
	int			m_score;											// Player score 
	GameText	m_scoreText;										// Text that displays the score
	GameSprite	m_shipUI;											// UI Image of the players life
	GameText	m_livesText;										// Text displays player lives
	int			m_highScores[Settings::k_amountOfHighScores];		// Stores the highScores from the file
	GameText	m_highScoreText;									// Text that displays the highscore table
	const int	m_amountOfScores;									// Stores the amount of scores in the highscore table
	std::string m_playerNames[Settings::k_amountOfHighScores];		// Stores the names of the players who have highscores
	int			m_nameIndex;										// Stores the index of the new highscore player name
	std::string m_newPlayerName;									// Temporarly stores the player name while the user is entering it.
	GameText	m_newPlayerNameText;								// Text that displays the new player 
	bool		m_newHighScore;										// Check if a new high score has been achieved
	//-----------------------------------------------
	// Function		: readScoreFile
	// Purpose		: Read the highscore file & store data
	// Parameters	: N/A
	// Returns		: void
	// Notes		: Mainly just used to keep text updated.
	// See also		: N/A
	//-----------------------------------------------
	void readScoreFile();
	//-----------------------------------------------
	// Function		: writeScoreFile
	// Purpose		: writes the highscore data to a file & stores it.
	// Parameters	: N/A
	// Returns		: void
	// Notes		: 
	// See also		: N/A
	//-----------------------------------------------
	void writeScoreFile();
	//-----------------------------------------------
	// Function		: setUpUIText
	// Purpose		: set the positions & font sizes of GameText Classes
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	void setUpUIText();
public:
	//-----------------------------------------------
	// Function		: PlayerData
	// Purpose		: Default constructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	PlayerData();
	//-----------------------------------------------
	// Function		: PlayerData
	// Purpose		: Constructor for preloaded assets 
	// Parameters	:  const sf::Texture& shipUITexture,const sf::Font& textFont,const int& amountOfHighScore
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	PlayerData( const sf::Texture& shipUITexture,const sf::Font& textFont,const int& amountOfHighScores );
	//-----------------------------------------------
	// Function		: ~PlayerData
	// Purpose		: default deconstructor 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: don't call
	// See also		: N/A
	//-----------------------------------------------
	~PlayerData();
	//-----------------------------------------------
	// Function		: render 
	// Purpose		: Use to render player data texted  
	// Parameters	: sf::RenderWindow* window,GameStates& gameState
	// Returns		: void
	// Notes		: passes through window as needed for draw 
	// See also		: N/A
	//-----------------------------------------------
	void render( sf::RenderWindow* window,GameStates& gameState );
	//-----------------------------------------------
	// Function		: update
	// Purpose		: Updates the entire playerdata class 
	// Parameters	: const int& waveCount, const int& lives
	// Returns		: void
	// Notes		: Mainly just used to keep text updated.
	// See also		: N/A
	//-----------------------------------------------
	void update( const int& waveCount, const int& lives );
	//-----------------------------------------------
	// Function		: getScoreText
	// Purpose		: return the score text
	// Parameters	: N/A
	// Returns		: GameText m_scoreText
	// Notes		: not const because it used as a reference to change data 
	// See also		: N/A
	//-----------------------------------------------
	 GameText& getScoreText();
	 //-----------------------------------------------
	 // Function	: enterPlayerName
	 // Purpose		: Used to aceept text enetered by user for name
	 // Parameters	:  sf::Event event, const GameStates& gameState
	 // Returns		: void 
	 // Notes		: Public due to need being called in game event loop
	 // See also	: N/A
	 //-----------------------------------------------
	void enterPlayerName( sf::Event event, const GameStates& gameState );
	//-----------------------------------------------
	// Function		: calculateHighScore
	// Purpose		: work out if a new highScore has been made
	// Parameters	: N/A
	// Returns		: void 
	// Notes		: public due to being called on state change 
	// See also		: N/A
	//-----------------------------------------------
	void calculateHighScore();
	//-----------------------------------------------
	 // Function	: clearScore
	 // Purpose		: Used to reset the entire highscore data
	 // Parameters	:  N/A
	 // Returns		: void 
	 // Notes		: Public due to need being called in game 
	 // See also	: N/A
	 //-----------------------------------------------
	void clearScore();
	//-----------------------------------------------
	 // Function	: setScore
	 // Purpose		: Used to set the score of the player
	 // Parameters	:  int score 
	 // Returns		: void 
	 // Notes		: N/A
	 // See also	: N/A
	 //-----------------------------------------------
	void setScore( int score );
	//-----------------------------------------------
	 // Function	: getScore
	 // Purpose		: Used to get the score of the player
	 // Parameters	:  N/A
	 // Returns		: const int& m_score
	 // Notes		: N/A
	 // See also	: N/A
	 //-----------------------------------------------
	const int& getScore() const;
	//-----------------------------------------------
	 // Function	: getHighScoreText
	 // Purpose		: returns the highscoretext
	 // Parameters	:  N/A
	 // Returns		: const int& m_score
	 // Notes		: N/A
	 // See also	: N/A
	 //-----------------------------------------------
	GameText& getHighScoreText();
};
#endif // !PLAYERDATA_H

