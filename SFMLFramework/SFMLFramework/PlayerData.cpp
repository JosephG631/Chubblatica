#include <algorithm>
#include <fstream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "PlayerData.h"
#include "Settings.h"

PlayerData::PlayerData()
 : m_score				(0)
 , m_scoreText			("Assets/Font/emulogic.ttf")
 , m_livesText			("Assets/Font/emulogic.ttf")
 , m_highScoreText		( "Assets/Font/emulogic.ttf" )
 , m_highScores			()
 , m_amountOfScores		( Settings::k_amountOfHighScores )
 , m_nameIndex			()
, m_newPlayerNameText	( "Assets/Font/emulogic.ttf" )
, m_newHighScore		( false )

{
	// Manually load Texture 
	m_shipUI.loadTexture( "Assets / Textures /UIShip" );

	// Set up player data text classes 
	setUpUIText();

	// Read Stored HighScores 
	readScoreFile();
}

PlayerData::PlayerData( const sf::Texture& shipUITexture, const sf::Font& textFont ,const int& amountOfHighScores )
	:m_score				( 0 )
	, m_scoreText			( textFont )
	, m_shipUI				( shipUITexture )
	, m_livesText			( textFont )
	, m_highScores			()
	, m_highScoreText		( textFont )
	, m_amountOfScores		( amountOfHighScores )
	, m_nameIndex			()
	, m_newPlayerNameText	( textFont )
	, m_newHighScore		( false )
{
	// Set up player data text classes 
	setUpUIText();

	// Read Stored HighScores 
	readScoreFile();
}

PlayerData::~PlayerData()
{
}

const int& PlayerData::getScore() const
{
	return m_score;
}

 GameText& PlayerData::getHighScoreText()
{
	return m_highScoreText;
}

void PlayerData::setScore( int score )
{
	m_score = score; 
}

void PlayerData::render( sf::RenderWindow* window ,GameStates& gameState)
{
	// Render Player data 
	window->draw( m_scoreText );
	window->draw( m_shipUI );
	window->draw( m_livesText );
	
	if ( gameState == GameStates::GameOver  )
	{
		// Render player data only for GameOver 
		window->draw( m_highScoreText );

		if ( m_newHighScore )
		{
			// If a new highscore render possible new name 
			window->draw( m_newPlayerNameText );

		}
	}
}

void PlayerData::update( const int& waveCount, const int& lives)
{
	// Set score text with lastest information
	m_scoreText.setString( "Score:" + std::to_string(m_score ) + "\n Wave :" +std::to_string( waveCount+1 ));

	// Set lives text to have updated amount
	m_livesText.setString( "X " + std::to_string( lives ) );

	// Set HighScore Table 
	m_highScoreText.setString( "Pos	 Name  Score \n1. " + m_playerNames[9]+ " " + std::to_string(m_highScores[9]) + "\n2. " + m_playerNames[8] + " " + std::to_string(m_highScores[8]) + "\n3. " + m_playerNames[7] + " " + std::to_string(m_highScores[7]) + "\n4. " + m_playerNames[6] + " " + std::to_string(m_highScores[6]) + "\n5. " + m_playerNames[5] + " " + std::to_string(m_highScores[5])+ "\n6. " + m_playerNames[4] + " " + std::to_string( m_highScores[4] ) + "\n7. " + m_playerNames[3] + " " + std::to_string( m_highScores[3] ) + "\n8. " + m_playerNames[2] + " " + std::to_string( m_highScores[2] )+ "\n9. " + m_playerNames[1] + " " + std::to_string( m_highScores[1] ) + "\n10. " + m_playerNames[0] + " " + std::to_string( m_highScores[0] ) );

	// Set new player text
	m_newPlayerNameText.setString( "Enter Player Name & press enter to save : \n " + m_newPlayerName );
}

 GameText& PlayerData::getScoreText() 
{
	 return m_scoreText;
}

 void PlayerData::readScoreFile()
 {
	 
	 std::ifstream myFile;

	 // Open up highscore file
	 myFile.open( "Assets/TextFile/HighScore.txt" );

	 // If opened the file for reading successfully
	 if ( myFile.is_open() )
	 {
		 
		 // Loop through scores & names 
		 for ( int i = 0; i < m_amountOfScores;i++ )
		 {
			 // Save player name
			 myFile >> m_playerNames[i];
			// Save Score
			 myFile >> m_highScores[i];
		 }
		 
		 myFile.close();
	 }
	 else
	 {
		 // Couldn't open that file!
	 }
	 
	 // Sort  scores in accending  size order 
	 std::sort( std::begin( m_highScores ), std::end( m_highScores )  );
	
	
 }

 void PlayerData::writeScoreFile()
 {
	 
	 std::ofstream myFile;

	 // Open high score file 
	 myFile.open( "Assets/TextFile/HighScore.txt" );

	 // If opened the file for reading successfully
	 if ( myFile.is_open() )
	 {
		 // Loop Through new scores created 
		 for ( int i = 0; i < m_amountOfScores; i++ )
		 {
			 // Store new Player name
			 myFile << m_playerNames[i];
			 // Make the score store on a different line so it lines up when read
			 myFile << "\n";
			 // Store highscores under corrsponding name 
			 myFile << m_highScores[i];
			
		 }
		 myFile.close();
	 }

	 
 }

 void PlayerData::setUpUIText()
 {
	 // Setting the correct font size to the correct UI Text
	 m_scoreText.setCharacterSize( TextSetting::k_uiGamePlayFontSize );
	 m_livesText.setCharacterSize( TextSetting::k_uiGamePlayFontSize );
	 m_newPlayerNameText.setCharacterSize( TextSetting::k_newPlayerTextSize );
	 m_highScoreText.setCharacterSize( TextSetting::k_highScoreTextSize );

	 // Setting Text to its default Starting Position
	 m_scoreText.setPosition( TextSetting::k_scoreGamePlayPos );
	 m_shipUI.setPosition( TextSetting::k_shipUIPos );
	 m_livesText.setPosition( TextSetting::k_livesTextPos );
	 m_newPlayerNameText.setPosition( TextSetting::k_newPlayerTextPos );
	 m_highScoreText.setPosition( TextSetting::k_highScorePosMenu );

	 m_highScoreText.setFillColor( sf::Color::Green );
 }

 void PlayerData::calculateHighScore()
 {
	 for ( int i = 0; i < m_amountOfScores; i++ )
	 {
		 // If the score is more than the current indexed highscore or the same
		 if ( m_score > m_highScores[i] || m_score == m_highScores[i] )
		 {
			 //  Less than the score in the index above 
			 if ( m_score < m_highScores[i + 1]  )
			 {
				 // If its the not the score at the buttom of the table 
				 if ( i != 0 )
				 {
					 // Move down all the scores below the new one.
					 for ( int b = 0; b < i; b++ )
					 {
						 m_highScores[b] = m_highScores[b + 1];
						 m_playerNames[b] = m_playerNames[b + 1];
					 }
					 // Remove name of score replacing 
					 m_playerNames[i] = "";
					 
				 }
				 // Set score in the correct position in thr table 
				 m_highScores[i] = m_score;
				 // Set the string index 
				 m_nameIndex = i;
				 // New highScore has been made
				 m_newHighScore = true;

				 // Reset string for next name entry 
				 m_newPlayerName = "";
				 break;
			 }
		 }
		
	 }
 }

 void PlayerData::enterPlayerName( sf::Event event, const GameStates& gameState )
 {
	 if ( gameState == GameStates::GameOver )
	 {
		 // If an event of text being entered has been registered 
			 if ( event.type == sf::Event::TextEntered )
			 {
				 // If the charcter entered  ASCII Unicode is below 128 (on the ascii table) & time to set a new highscore
				 if ( event.text.unicode < 128  && m_newHighScore == true)
				 {
					 // If a backspace has been pressed(windows unicode of 8 only)
					 if ( event.text.unicode == 8 )
					 {
						 // Remove the last char of the entered name by using a substring.
						 m_newPlayerName = m_newPlayerName.substr( 0, m_newPlayerName.length() - 1 );
					 }
					 else
					 {
						 // If text is less than name character limt 
						 if ( m_newPlayerName.size() < TextSetting::k_playerNameCharacterLimt )
						 {
							 // Convert entered key unicode to a char and apply to name string 
							 m_newPlayerName += static_cast<char>( event.text.unicode );
							
						 }
						 
					 }
					 // If the return/enter key has been pressed(windows unicode of 13 only) 
					 if ( event.text.unicode == 13 )
					 {
						 // Set final player name 
						 m_playerNames[m_nameIndex] = m_newPlayerName;

						 // New highscore has been set so no new score
						 m_newHighScore = false;

						 // Save new Name and score to file 
						 writeScoreFile();
					 }
					
				 } 
			 }
		 
	 }
 }

 void PlayerData::clearScore()
 {
	 // Loop through each name/score
	 for ( int i = 0; i < m_amountOfScores; i++ )
	 {
		 // Rest values 
		 m_highScores[i] = 0;
		 m_playerNames[i] = "N/A";
	 }
	 // Reset file 
	 writeScoreFile();
 }
