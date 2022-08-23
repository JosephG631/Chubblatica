#ifndef ANIMATEDGAMESPRITE_H
#define ANIMATEDGAMESPRITE_H

#include "GameSprite.h"
//-----------------------------------------------
//class			: AnimatedGameSprite
// Purpose		: A gamesprite that can be animated 
// Usage		:	
//					AnimatedGameSprite();
//					AnimatedGameSprite( const sf::Texture& texture, const int& numberOfFrames, const float& animationFPS );
//					~AnimatedGameSprite();
//					void calculateAnimationFrame( );
// 					virtual void update( float& deltaTime );
// 					void animateSprite( float& deltaTime );
// 					bool animateOnce( float& deltaTime );
// See also	: 
//-----------------------------------------------
class AnimatedGameSprite : public GameSprite
{
private:
	sf::IntRect     m_rect;						// A section of the texture
	int				m_currentFrame;				// The current animation frame
	const int		m_numberOfFrames;			// The amount of animation frames 
	const float		m_animationFrameRate;		// The rate the sprite animates 
	float			m_frameTime;				// Used to apply framerate & deltaTime
public:
	//-----------------------------------------------
	// Function		: AnimatedGameSprite
	// Purpose		: default constructor 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	AnimatedGameSprite();
	//-----------------------------------------------
	// Function		: AnimatedGameSprite(const sf::Texture& texture, const int& numberOfFrames, const float& animationFPS )
	// Purpose		: Constructor with texture manager & settings passed through
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	AnimatedGameSprite( const sf::Texture& texture, const int& numberOfFrames, const float& animationFPS );
	//-----------------------------------------------
	// Function		: ~AnimatedGameSprite
	// Purpose		: Deconstructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	~AnimatedGameSprite();
	//-----------------------------------------------
	// Function		: calculateAnimationFrame
	// Purpose		: work out the correct current frame and cut it from the texture 
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void calculateAnimationFrame( );
	//-----------------------------------------------
	// Function		: update 
	// Purpose		: update animated game sprite  
	// Parameters	: float& deltaTime
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	 void update( float& deltaTime );
	//-----------------------------------------------
	// Function		: animateSprite
	// Purpose		: continuously animate game sprite 
	// Parameters	: float& deltaTime
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	void animateSprite( float& deltaTime );
	//-----------------------------------------------
	// Function		: animateOnce
	// Purpose		: do one animation cycle 
	// Parameters	: float& deltaTime
	// Returns		: true/false if done one animation
	// Notes		: N/A
	// See also		: aninmateGameSprite
	//-----------------------------------------------
	bool animateOnce( float& deltaTime );
	
};

#endif
