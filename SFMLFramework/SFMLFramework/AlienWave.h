#ifndef ALIENWAVE_H
#define ALIENWAVE_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Alien.h"

//-----------------------------------------------
//class			: AlienWave
// Purpose		: To manage a wave of aliens 
// Usage		:	
//					void update()
//					void initializeAlienArray( int& waveCount )
//					void setFormationPositions()
//					void activateTimer( std::vector <sf::Vector2i> indexSet, bool twoLanes, AlienStatus status, std::vector < std::vector<sf::Vector2f>> movementPoints, std::vector < std::vector<sf::Vector2f>> movementPointsTwo = {} )
//					bool checkStatus( const std::vector <sf::Vector2i>& indexSet, AlienStatus state )
//					void resetTimer()
//					void startWave( float& deltaTime )
//					void readFormationData()
//					void indexSetter( char num, int row, int col )
//					void resetAlienMovement( const std::vector <sf::Vector2i>& indexSet )
//					void diveAliens( const  sf::Vector2f& playerPosition )
//					void flyInSet( const std::vector <sf::Vector2i>& indexSet, const  std::vector<sf::Vector2i>& lastSet, bool lanes, AlienStatus statusToCheck, const std::vector < std::vector<sf::Vector2f>>& movementPoints, const std::vector < std::vector<sf::Vector2f>>& movementPointsTwo = {} )
//					void checkWaveComplete()
//					AlienWave()
//					AlienWave( const sf::Texture& alienTexture, const sf::Texture& gruntTexture, const sf::Texture& bossTexture, const sf::SoundBuffer& soundEffect, const int& formationGapSize, const sf::Vector2i& gridSize, const int& setSize, const float& flyInGap, const float& diveRate, const int& startingWave, const int& amountOfFormation )
//					~AlienWave()
//					const void render( sf::RenderWindow* pWindow ) const
//					void update( float& deltaTime, sf::Vector2f playerPosition, ObjectManager& objectManager )
//					void resetWave()
//					const sf::Vector2i& getGridSize() const
//					const std::vector<std::vector<Alien*>>& getAlienArray() const
//					const int& getWaveCount()const
//					void setWaveCount( const int& waveCount )
// 
// See also	: Alien.h,Grunt.h,Boss.h
//-----------------------------------------------
class AlienWave
{
private:
	std::vector<std::vector<Alien*>>			m_pAliens;						// 2D Vector pointer array   of aliens in the wave
	const int									m_gridGap;						// The Gap between aliens in the formation
    const sf::Vector2i							m_gridSize;						// The total size of the alien formation.
	const int									m_setSize;						// The group size of  the fly in  the group				
	const int									m_bezierCurvePointsAmount;		// Amount of points needed for a bezier curve				
	sf::Clock									m_flyInTimer;					// Clock used to stager time ins
	sf::Time									m_interval;						// Used to store the time of fly ins
	int											m_alienTimerCounter;			// Count the amouny of aliens activatied by the timer 
	bool										m_formationSet;					// Has the the index of the formation be set
	bool										m_timerReset;					// Timer rest
	float										m_flyInGap;						// The time between each alien flying in
	std::string									m_formationFileInformation[7];	// String of the alien formation information from files 	
	float										m_diveInterval;					// The rate the aliens dive in secounds 
	std::vector <sf::Vector2i>					m_setOneIndex;					// Arrays of Indexs for each set of flying Aliens 
	std::vector <sf::Vector2i>					m_setTwoIndex;						
	std::vector <sf::Vector2i>					m_setThreeIndex;
	std::vector <sf::Vector2i>					m_setFourIndex;
	std::vector <sf::Vector2i>					m_setFiveIndex;
	std::vector < std::vector<sf::Vector2i>>	m_allIndex;						// Stores all the indexs 
	sf::Texture									m_alienTexture;					// Stores the fly texture for the basic alien
	sf::Texture									m_gruntTexture;					// Stores the grunt texture
	sf::Texture									m_bossTexture;					// Stores the boss texture for the boss alien
	bool										m_flyInsComplete;				// Bool to state if the aliens have finshed flying
	int											m_waveCount;					// The total amount of wave currently played
	sf::SoundBuffer								m_alienShootSound;				// The sound the aliens make while shooting
	int											m_formationCount;				// Used to track the file for each wave.
	const int									m_amountOfFormations;           // There are serval txt with different formations this is the total 
	int											m_amountOfAliens;				// The amount of aliens in wave
	//-----------------------------------------------
	// Function		: initializeAlienArray
	// Purpose		: set up the main array that stores the aliens 
	// Parameters	:  int& waveCount
	// Returns		: void
	// Notes		: uses the information from the text file
	// See also		: readFormationData
	//-----------------------------------------------
	void initializeAlienArray( int& waveCount );
	//-----------------------------------------------
	// Function		: setFormationPositions
	// Purpose		: set up the aliens  position in the formation 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: initializeAlienArray
	//-----------------------------------------------
	void setFormationPositions();
	//-----------------------------------------------
	// Function		: activateTimer
	// Purpose		: a timer that separates aliens in intervals when they fly int
	// Parameters	: std::vector <sf::Vector2i> indexSet, bool twoLanes, AlienStatus status, std::vector < std::vector<sf::Vector2f>> movementPoints, std::vector < std::vector<sf::Vector2f>> movementPointsTwo ={} 
	// Returns		: void
	// Notes		: has a default paramater for if two paths are requried 
	// See also		: 
	//-----------------------------------------------
	void activateTimer( std::vector <sf::Vector2i> indexSet, bool twoLanes, AlienStatus status, std::vector < std::vector<sf::Vector2f>> movementPoints, std::vector < std::vector<sf::Vector2f>> movementPointsTwo ={} );
	//-----------------------------------------------
	// Function		: checkStatus 
	// Purpose		: Loops through a set of aleins to check to see if they are all the matching state 
	// Parameters	: const std::vector <sf::Vector2i>& indexSet, AlienStatus state
	// Returns		: bool m_formationSet
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	bool checkStatus( const std::vector <sf::Vector2i>& indexSet, AlienStatus state );
	//-----------------------------------------------
	// Function		: resetTimer 
	// Purpose		: reset the timer settings
	// Parameters	: N/A
    // Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void resetTimer();
	//-----------------------------------------------
	// Function		: startWave 
	// Purpose		: start separate fly ins  for the begining of each wave
	// Parameters	: float& deltaTime
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void startWave( float& deltaTime );
	//-----------------------------------------------
	// Function		: readFormationData
	// Purpose		: reads all files that holds formation data
	// Parameters	: float& deltaTime
	// Returns		: void
	// Notes		:  N/A
	// See also		: 
	//-----------------------------------------------
	void readFormationData();
	//-----------------------------------------------
	// Function		: indexSetter
	// Purpose		: used to set the groups of aliens up to their correct fly in  groups
	// Parameters	: char num, int row, int col
	// Returns		: void
	// Notes		: uses a code inside the txt to set the index 
	// See also		: 
	//-----------------------------------------------
	void indexSetter(char num, int row, int col );
	//-----------------------------------------------
	// Function		: resetAlienMovement 
	// Purpose		: reset all the aliens at the corrret time.
	// Parameters	: std::vector <sf::Vector2i>& indexSet
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void resetAlienMovement( const std::vector <sf::Vector2i>& indexSet );
	//-----------------------------------------------
	// Function		: diveAliens
	// Purpose		: make the aliens dive at random 
	// Parameters	: const  sf::Vector2f& playerPosition 
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void diveAliens( const  sf::Vector2f& playerPosition );
	//-----------------------------------------------
	// Function		: flyInSet
	// Purpose		: make the aliens fly in , in their set 
	// Parameters	: onst std::vector <sf::Vector2i>& indexSet, const  std::vector<sf::Vector2i>&lastSet, bool lanes, AlienStatus statusToCheck, const std::vector < std::vector<sf::Vector2f>>& movementPoints, const std::vector < std::vector<sf::Vector2f>>& movementPointsTwo = {} 
	// Returns		: void
	// Notes		: N/A
	// See also		: activateTimer
	//-----------------------------------------------
	void flyInSet( const std::vector <sf::Vector2i>& indexSet, const  std::vector<sf::Vector2i>&lastSet, bool lanes, AlienStatus statusToCheck, const std::vector < std::vector<sf::Vector2f>>& movementPoints, const std::vector < std::vector<sf::Vector2f>>& movementPointsTwo = {} );
	//-----------------------------------------------
	// Function		: checkWaveComplete
	// Purpose		:  check to see if all aliens are dead in the wave 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void checkWaveComplete();
public:
	//-----------------------------------------------
	// Function		: AlienWave
	// Purpose		: default constructor 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	AlienWave();
	//-----------------------------------------------
	// Function		: AlienWave
	// Purpose		: used for custom wave settings 
	// Parameters	: const sf::Texture& alienTexture, const sf::Texture& gruntTexture, const sf::Texture& bossTexture, const sf::SoundBuffer& soundEffect ,const int& formationGapSize,const sf::Vector2i& gridSize, const int& setSize, const float& flyInGap, const float& diveRate, const int& startingWave, const int& amountOfFormation
	// Returns		: void
	// Notes		: if you don't use this constructor game sprites will have to load in the textures by themselves
	// See also		: 
	//-----------------------------------------------
	AlienWave( const sf::Texture& alienTexture, const sf::Texture& gruntTexture, const sf::Texture& bossTexture, const sf::SoundBuffer& soundEffect ,const int& formationGapSize,const sf::Vector2i& gridSize, const int& setSize, const float& flyInGap, const float& diveRate, const int& startingWave, const int& amountOfFormation);
	//-----------------------------------------------
	// Function		: AlienWave
	// Purpose		: default deconstructor 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: don't call
	// See also		: 
	//-----------------------------------------------
	~AlienWave();
	//-----------------------------------------------
	// Function		: Render
	// Purpose		: render the aliens 
	// Parameters	: sf::RenderWindow* pWindow
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	const void render( sf::RenderWindow* pWindow ) const ;
	//-----------------------------------------------
	// Function		: update
	// Purpose		: update the entire alien wave class 
	// Parameters	: float& deltaTime, sf::Vector2f playerPosition, ObjectManager& objectManager
	// Returns		: void
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void update( float& deltaTime, sf::Vector2f playerPosition, ObjectManager& objectManager );
	//-----------------------------------------------
	// Function		: resetWave()
	// Purpose		: reset values of the wave and get new formation information
	// Parameters	: N/A
	// Returns		: void 
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void resetWave();
	//-----------------------------------------------
	// Function		: getGridSize
	// Purpose		: return the size of the grid of aliens
	// Parameters	: N/A
	// Returns		: sf::Vector2i& m_gridSize
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	const sf::Vector2i& getGridSize() const;
	//-----------------------------------------------
	// Function		: getAlienArray
	// Purpose		: return all the aliens
	// Parameters	: N/A
	// Returns		: std::vector<std::vector<Alien*>>& m_pAliens
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	const std::vector<std::vector<Alien*>>& getAlienArray() const;
	//-----------------------------------------------
	// Function		: getWaveCount
	// Purpose		: return the current wave
	// Parameters	: N/A
	// Returns		: const int& m_waveCount
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	const int& getWaveCount()const;
	//-----------------------------------------------
	// Function		: setWaveCount
	// Purpose		: reset the wave 
	// Parameters	: N/A
	// Returns		: const int& m_waveCount
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void setWaveCount(  const int& waveCount );
	//-----------------------------------------------
	// Function		: setFormationCount
	// Purpose		: reset the wave 
	// Parameters	: N/A
	// Returns		: const int& m_waveCount
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	void setFormationCount( const int& waveCount );
};



#endif // !ALIENWAVE_H
