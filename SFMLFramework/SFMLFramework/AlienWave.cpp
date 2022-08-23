#include <fstream>
#include <vector>
#include <SFML/System/Clock.hpp>


#include "Alien.h"
#include "AlienStatus.h"
#include "AlienWave.h"
#include "Boss.h"
#include "Helpers.h"
#include "Grunt.h"
#include "Settings.h"

AlienWave::AlienWave()
	:m_gridGap						( Settings::k_formationGapSize )
	, m_gridSize					( Settings::k_gridSize )
	, m_setSize						( Settings::k_setAlienSize)
	, m_alienTimerCounter			( 0 )
	, m_bezierCurvePointsAmount		( 4 )
	, m_timerReset					( false )
	, m_formationSet				( false)
	,m_flyInGap						( Settings::k_flyInGap )
	, m_flyInsComplete				( false )
	, m_diveInterval				( Settings::k_alienDiveRate )
	, m_waveCount					( Settings::k_startingWave )
	, m_amountOfFormations			( Settings::k_amountOfFormationFiles )
	, m_formationCount				( Settings::k_startingWave )
{
	// Read Wave data
	readFormationData();
	
	// Create Alien array
	initializeAlienArray(m_formationCount);

	// Calculatue formation position
	setFormationPositions();

	// Set random seed for dives
	srand( (int)time( 0 ) );
}
AlienWave::AlienWave( const sf::Texture& alienTexture, const sf::Texture& gruntTexture, const sf::Texture& bossTexture, const sf::SoundBuffer& soundEffect, const int& formationGapSize, const sf::Vector2i& gridSize, const int& setSize, const float& flyInGap, const float& diveRate, const int& startingWave, const int& amountOfFormation )
	:m_gridGap						( formationGapSize )
	, m_gridSize					( gridSize )
	, m_setSize						( setSize )
	, m_alienTimerCounter			( 0 )
	, m_bezierCurvePointsAmount		( 4 )
	, m_timerReset					( false )
	, m_formationSet				( false )
	, m_flyInGap					( flyInGap )
	, m_alienTexture				( alienTexture )
	, m_gruntTexture				( gruntTexture)
	, m_bossTexture					( bossTexture )
	, m_flyInsComplete				( false )
	, m_diveInterval				( diveRate )
	,m_waveCount					( startingWave )
	,m_alienShootSound				( soundEffect )
	,m_amountOfFormations			( amountOfFormation )
	,m_formationCount				( startingWave )
{
	
	// Read all  wave data
	readFormationData();

	
	// Create Alien array
	initializeAlienArray( m_formationCount );

	// Calculatue formation positions
	setFormationPositions();

	// Set random seed for dives
	srand( static_cast<int>(time( 0 ) ));
}
AlienWave::~AlienWave()
{
	// Loop through and delete the alien pointer array
	for ( int row = 0; row < m_gridSize.x; row++ )
	{
		for ( int col = 0; col < m_gridSize.y; col++ )
		{
			safeDelete( m_pAliens[row][col] );

		}
	} 
}

void AlienWave::readFormationData()
{
	
	// Setup file reading 
	std::ifstream formationData;
	// Loop through alll the different txt files 
	for ( int currentWaves = 0; currentWaves < m_amountOfFormations; currentWaves++ )
	{
		// Open alll the  formaition txt files 
		formationData.open( "Assets/TextFile/formation"+ std::to_string(currentWaves)+".txt" );

		// Used to store a single line of text 
		std::string lineOfText;

		if ( formationData.is_open() )
		{
			// Opened the file for reading successfully
			while ( std::getline( formationData, lineOfText ) )
			{
				// Add text to the  correct string
				m_formationFileInformation[currentWaves] += lineOfText;
				m_formationFileInformation[currentWaves] += "\n";
			}
			// Close file
			formationData.close();
		}
	}

	
}
void AlienWave::initializeAlienArray( int& waveCount )
{ 
	
	// Setting the size of the wave by gride size
	m_pAliens.assign( m_gridSize.x, std::vector<Alien*>( m_gridSize.y ) );

	// Row/col of the text document 
	 int row = 0;
	 int col = 0;
	 // Loop through the whole string 
	for ( size_t letterNumber = 0; letterNumber < m_formationFileInformation[waveCount].size();letterNumber++ )
	{
		// Get each letter from the string 
		char c = m_formationFileInformation[waveCount][letterNumber];

		// Check each letter 
		switch ( c )
		{
		case 'x':
			// X means no alien in space. set array to null ptr
			m_pAliens[row][col] = nullptr;
			
			// Increase the col nummber if its not at the end
			if ( col != m_gridSize.y - 1 )
			{
				col++;
			}
			break;
		case 'f':
			// F (fly) create a fly here 
			m_pAliens[row][col] = new Alien( m_alienTexture,Settings::k_flyDestroyScore,m_alienShootSound );
			m_amountOfAliens++;
			// If the next char is a digit set the alien  to the correct index 
			if ( isdigit( m_formationFileInformation[waveCount][letterNumber + 1] ) )
			{
				indexSetter( m_formationFileInformation[waveCount][letterNumber + 1], row, col );
			}

			// Increase the col nummber if its not at the end
			if ( col != m_gridSize.y - 1 )
			{
				col++;
			}

			break;
		case 'g':
			// Create a grunt
			m_pAliens[row][col] = new Grunt( m_gruntTexture,Settings::k_gruntDestroyScore, m_alienShootSound );
			m_amountOfAliens++;
			// If the next char is a digit set the alien  to the correct index 
			if ( isdigit( m_formationFileInformation[waveCount][letterNumber + 1] ) )
			{
				indexSetter( m_formationFileInformation[waveCount][letterNumber + 1], row, col );
			}

			// Increase the col nummber if its not at the end
			if ( col != m_gridSize.y - 1 )
			{
				col++;
			}
			
			break;
		case 'b':
			// Create a boss
			m_pAliens[row][col] = new Boss( m_bossTexture ,Settings::k_bossDestroyScore, m_alienShootSound );
			m_amountOfAliens++;
			// If the next char is a digit set the alien  to the correct index 
			if ( isdigit( m_formationFileInformation[waveCount][letterNumber + 1] ) )
			{
				indexSetter( m_formationFileInformation[waveCount][letterNumber + 1], row, col );
			}

			// Increase the col nummber if its not at the end
			if ( col != m_gridSize.y - 1 )
			{
				col++;
			}
			break;
		case ' ':
			break;
		case '\n':
			// If its a new line reset col and add the row
			col = 0;
			if ( row != m_gridSize.x - 1 )
			{
				row++;
			}
			break;
		}
	}
	// Add all indexs to an array for random diving 
	m_allIndex = { m_setOneIndex,m_setTwoIndex,m_setThreeIndex,m_setFourIndex,m_setFiveIndex };
}
void AlienWave::indexSetter(char num, int row , int col)
{
	switch ( num )
	{

	case '1':
		// If one was read add to index one 
		m_setOneIndex.push_back( sf::Vector2i( row, col ) );
	
		break;
	case '2':
		// If two was read add to index two
		m_setTwoIndex.push_back( sf::Vector2i( row, col) );
		break;
	case '3':
		// Same as above 
		m_setThreeIndex.push_back( sf::Vector2i( row, col ) );
		break;
	case '4':
		m_setFourIndex.push_back( sf::Vector2i( row, col ) );
		break;
	case '5':
		m_setFiveIndex.push_back( sf::Vector2i( row, col) );
		break;
	default:
		break;
	}
}
void AlienWave::setFormationPositions()
{
	
	// Making a Temp position to set to the aliens formation position
	sf::Vector2f position = Settings::k_gridStartingPosition;

	// Setting the grid positions up by looping throught the grid size 
	for ( int row = 0; row < m_gridSize.x; row++ )
	{
		for ( int col = 0; col < m_gridSize.y; col++ )
		{
			// If there is no gap inside the formation set position
			if ( m_pAliens[row][col] != nullptr )
			{
				// Setting the position of each alien 
				m_pAliens[row][col]->setFormationPosition( position );

				// If the wave is not the first increase diffcutly 
				if ( m_waveCount != Settings::k_startingWave)
				{
					m_pAliens[row][col]->increaseDiffuctly( m_waveCount );
				}
			}
		
			// Adjusting the position for the next alien in the formation 
			position.x += m_gridGap;
		}

		// Reseting the X Position for the next row 
		position.x = Settings::k_gridStartingPosition.x;

		// New row has started go down by the dimenisons & gap amount.  
		position.y += m_gridGap;
	}
}
const void AlienWave::render( sf::RenderWindow* pWindow ) const 
{
	// Loop through the array of aliens 
	for ( int row = 0; row <m_gridSize.x; row++ )
	{
		for ( int col = 0; col <m_gridSize.y; col++ )
		{
			// Check to see if current array element is a gap or dead 
			if ( m_pAliens[row][col] != nullptr && m_pAliens[row][col]->getState() != AlienStatus::Dead )
			{
				// Draw the aliens 
			  pWindow->draw( *m_pAliens[row][col] );

			}
		}
	}
}
void AlienWave::update( float& deltaTime, sf::Vector2f playerPosition, ObjectManager& objectManager )
{
	// Update every alien thats not null
	for ( int row = 0; row < m_gridSize.x; row++ )
	{
		for ( int col = 0; col < m_gridSize.y; col++ )
		{
			if ( m_pAliens[row][col] != nullptr )
			{

				m_pAliens[row][col]->update( deltaTime, objectManager );
				
			}
		}
	}
	// Start the alien fly in patterns
	if ( m_flyInsComplete == false )
	{
		startWave( deltaTime );

	}
	// If all aliens have gone to formation/died 
	if ( m_flyInsComplete == true )
	{
		diveAliens( playerPosition );

	}
	// Check to see if player has killed all aliens 
	checkWaveComplete();
}
void AlienWave::startWave( float& deltaTime )
{
	// If the first index has not flown in
	if ( checkStatus( m_setOneIndex ,AlienStatus::Formation) == false )
	{
		// Fly in first set 
		activateTimer( m_setOneIndex, true, AlienStatus::FlyIn ,MovementPoints::k_setOneCurvePoints, MovementPoints::k_setOneCurvePointsTwo);
	}
	
	// Fly In Sets of aliens 
	flyInSet( m_setTwoIndex, m_setOneIndex, false, AlienStatus::FlyIn, MovementPoints::k_setTwoCurvePoints );
	flyInSet( m_setThreeIndex, m_setTwoIndex, false, AlienStatus::FlyIn, MovementPoints::k_setThreeCurvePoints );
	flyInSet( m_setFourIndex, m_setThreeIndex, false, AlienStatus::FlyIn, MovementPoints::k_setFourCurvePoints );
	flyInSet( m_setFiveIndex, m_setFourIndex, false, AlienStatus::FlyIn, MovementPoints::k_setFiveCurvePoints );

	// If all are flown in 
	if ( checkStatus( m_setFourIndex, AlienStatus::Formation ) == true && checkStatus( m_setFiveIndex, AlienStatus::Formation ) == true )
	{
		// Fly ins now complete to start dives 
		m_flyInsComplete = true;
	}
}
bool AlienWave::checkStatus( const std::vector <sf::Vector2i>& indexSet, AlienStatus state )
{
	// Reset formation Set
	m_formationSet = false;

	// Used to count the amount of true statementd
	int checkTrue = 0;

	// Checks to see if all the aliens have died or flown to formation 
	for ( int i = 0; i < m_setSize; i++ )
	{
		if ( m_pAliens[indexSet[i].x][indexSet[i].y]->getState() == state || m_pAliens[indexSet[i].x][indexSet[i].y]->getState() == AlienStatus::Dead )
		{
			// If they have its true
			checkTrue++;
		} 
		else
		{
			// if not 
			checkTrue--;
		}
		
	}
	// Check to see if all elements in this set of indexs have met the condition. ( The reason I use a counter instead of just bools is that I was getting false positives due to the call order of the function).
	if ( checkTrue == m_setSize )
	{
		m_formationSet = true;
	}
	else
	{
		m_formationSet = false;
	}
	return m_formationSet;
	
}
void AlienWave::resetTimer()
{
	// If Timer has not been reset
	if ( m_timerReset == false )
	{
		// Reset Timer fly in values
		m_alienTimerCounter = 0;
		m_timerReset = true;
		m_flyInTimer.restart();

	}
}
void AlienWave::resetAlienMovement(const  std::vector<sf::Vector2i>& indexSet )
{
	for ( int i = 0; i < m_setSize; i++ )
	{
		// Reset the movement index for the next set of movement instructions 
		m_pAliens[indexSet[i].x][indexSet[i].y]->setArrayIndex( 0 );

		// Reset the speed for next movement 
		m_pAliens[indexSet[i].x][indexSet[i].y]->setLerpSpeed( 0 );
		
	}
}
void AlienWave::diveAliens( const  sf::Vector2f& playerPosition)
{
	// Get Time elapsed since last dive 
	m_interval = m_flyInTimer.getElapsedTime();

	// Randomise a random index set 
	int indexOne = rand() % ( static_cast<int>( m_allIndex.size() ) );

	// Randomise the index side the index set 
	int indexTwo = rand() % (  static_cast<int> ( m_setSize - 1 ) );

	// If time has passed since last dive 
	if ( m_interval.asSeconds() > m_diveInterval )
	{
		// Check to see if selected alien is in the formation & can dive 
		if ( m_pAliens[m_allIndex[indexOne][indexTwo].x][m_allIndex[indexOne][indexTwo].y]->getState() == AlienStatus::Formation )
		{
			// If can dive reset movement looper as new points are being used 
			resetAlienMovement( m_allIndex[indexOne] );
			m_pAliens[m_allIndex[indexOne][indexTwo].x][m_allIndex[indexOne][indexTwo].y]->dive( playerPosition );

			// Set current state to dive ( call move in indvisual alien update)
			m_pAliens[m_allIndex[indexOne][indexTwo].x][m_allIndex[indexOne][indexTwo].y]->setState( AlienStatus::Dive );

			// Reset Value
			m_diveInterval = Settings::k_alienDiveRate;

			// Reset timer for next Dive 
			m_flyInTimer.restart();
		}
		if ( m_pAliens[m_allIndex[indexOne][indexTwo].x][m_allIndex[indexOne][indexTwo].y]->getState() == AlienStatus::Dead )
		{
			// If dead remove timer 
			m_diveInterval = 0.0f;
		}
	}
}
void AlienWave::flyInSet( const std::vector <sf::Vector2i>& indexSet, const  std::vector<sf::Vector2i>& lastSet, bool lanes, AlienStatus statusToCheck, const std::vector < std::vector<sf::Vector2f>>& movementPoints, const std::vector < std::vector<sf::Vector2f>>& movementPointsTwo  )
{
	// Check if last set has completed and current set is ready
	if ( checkStatus(lastSet, AlienStatus::Formation ) == true && checkStatus(indexSet, AlienStatus::Formation ) == false )
	{
		// Reset flyin timer 
		resetTimer();

		// Used to reset each index for the next wave/game
		resetAlienMovement( lastSet );
		// Fly In Aliens with timed gap
		activateTimer( indexSet, false, AlienStatus::FlyIn, movementPoints,movementPointsTwo);

	}
}
void AlienWave::checkWaveComplete()
{
	
	// Count for the amount dead
	int amountDead = 0;
	for ( int row = 0; row < m_gridSize.x; row++ )
	{
		for ( int col = 0; col < m_gridSize.y; col++ )
		{
			if ( m_pAliens[row][col] != nullptr )
			{
				if ( m_pAliens[row][col]->getState() == AlienStatus::Dead )
				{
					// If dead add to dead counter
					amountDead++;
				}
			}
		}
	}
	// If all aliens are dead game is over 
	if ( amountDead == m_amountOfAliens )
	{
		// If all text files have been used
		if ( m_formationCount == m_amountOfFormations -1 )
		{
			// Reset to the first file 
			m_formationCount = 0;
		}
		else
		{
			// Increase Wave number  for formation text files 
			m_formationCount++;
		}
		// Increase wave count for UI
		m_waveCount++;
		// If all are dead reset wave.
		resetWave();
	}
}
void AlienWave::activateTimer( std::vector <sf::Vector2i> indexSet , bool twoLanes, AlienStatus status, std::vector < std::vector<sf::Vector2f>> movementPoints, std::vector < std::vector<sf::Vector2f>> movementPointsTwo  )
{
	// Get Timer 
	m_interval = m_flyInTimer.getElapsedTime();

	// If there are two lanes of aliens in this set of flying in 
	if ( twoLanes )
	{

		if ( m_interval.asSeconds() > m_flyInGap && m_alienTimerCounter < m_setSize *0.5 && m_pAliens[indexSet[m_alienTimerCounter].x][indexSet[m_alienTimerCounter].y]->getState() != AlienStatus::Dead)
		{
			// Change status to fly in 
			m_pAliens[indexSet[m_alienTimerCounter].x][indexSet[m_alienTimerCounter].y]->setState( status );
			m_pAliens[indexSet[m_alienTimerCounter].x][indexSet[m_alienTimerCounter].y]->setMovementPoints( movementPoints );
			m_pAliens[indexSet[m_alienTimerCounter +4].x][indexSet[m_alienTimerCounter +4].y]->setState( status );
			m_pAliens[indexSet[m_alienTimerCounter + 4].x][indexSet[m_alienTimerCounter + 4].y]->setMovementPoints( movementPoints );
			// Increase alien count 
			m_alienTimerCounter++;
		
			// Reset Timer for next loop
			m_flyInTimer.restart();
		}
	}
	// One Lane
	else
	{
		if ( m_interval.asSeconds() >m_flyInGap && m_alienTimerCounter < m_setSize  )
		{
			if ( m_pAliens[indexSet[m_alienTimerCounter].x][indexSet[m_alienTimerCounter].y]->getState() != AlienStatus::Dead )
			{

				// Change status to fly in 
				m_pAliens[indexSet[m_alienTimerCounter].x][indexSet[m_alienTimerCounter].y]->setState( status );
				m_pAliens[indexSet[m_alienTimerCounter].x][indexSet[m_alienTimerCounter].y]->setMovementPoints( movementPoints );
			}
			// Increase alien count 
			m_alienTimerCounter++;

			// Reset Timer for next loop
			m_flyInTimer.restart();
		}
	}
	if ( m_alienTimerCounter == m_setSize )
	{
		// Timer has done and now needs reseting 
		m_timerReset = false;
	}
}
const sf::Vector2i& AlienWave::getGridSize() const
{
	return m_gridSize;
}
const std::vector<std::vector<Alien*>>& AlienWave::getAlienArray() const 
{
	return m_pAliens;
}

void AlienWave::resetWave()
{
	// Reset set flyIns
	m_flyInsComplete = false;


	for ( int row = 0; row < m_gridSize.x; row++ )
	{
		for ( int col = 0; col < m_gridSize.y; col++ )
		{
			// Delete aliens to remove memory leaks
			safeDelete( m_pAliens[row][col] );
			
		}
		m_pAliens[row].clear();
	
	}
	m_amountOfAliens = 0;
	// Clear indexs for next wave 
	m_setOneIndex.clear();
	m_setTwoIndex.clear();
	m_setThreeIndex.clear();
	m_setFourIndex.clear();
	m_setFiveIndex.clear();

	// repoluate the arrays with new information
	initializeAlienArray( m_formationCount );
	// Set new Pos
	setFormationPositions();
	// Reset fly in timer 
	m_timerReset = false;
	resetTimer();
}

const int& AlienWave::getWaveCount() const
{
	return m_waveCount;
}

void AlienWave::setWaveCount( const int& waveCount )
{
	m_waveCount = waveCount;
}

void AlienWave::setFormationCount( const int& waveCount )
{
	m_formationCount = 0;
}
