#include "AnimatedGameSprite.h"
#include "Settings.h"

AnimatedGameSprite::AnimatedGameSprite()
	: GameSprite				()
	, m_numberOfFrames			( 4 )
	, m_frameTime				( 0.0f )
	, m_animationFrameRate		( Settings::k_animationFrameRate )
	,m_currentFrame				( 0 )
{
}

AnimatedGameSprite::AnimatedGameSprite( const sf::Texture& texture, const int& numberOfFrames,const float& animationFPS )
	: GameSprite				( texture )
	, m_numberOfFrames			( numberOfFrames )
	, m_frameTime				( 0.0f )
	, m_animationFrameRate		( animationFPS )
	, m_currentFrame			( 0 )
{

}

AnimatedGameSprite::~AnimatedGameSprite()
{
	// Decontructor 
}



void AnimatedGameSprite::calculateAnimationFrame(  )
{
	
	sf::Vector2u dimensions = getTextureDimensions();

	// Divide spritesheet by the amount of animation frames
	int frameWidth = static_cast<int>( dimensions.x / m_numberOfFrames );
	// Only linear sprite sheets
	int frameHeight = static_cast<int>( dimensions.y );

	// Create texture rectangle for  the correct animation frame
	m_rect.left = m_currentFrame * frameWidth;
	m_rect.top = 0;
	m_rect.width = frameWidth;
	m_rect.height = frameHeight;

	
	setTextureRect( m_rect );

	// Set the orgrin for  the new frame 
	setOrigin( frameWidth * 0.5f, frameHeight * 0.5f );

}

void AnimatedGameSprite::update( float& deltaTime )
{
	// Animate sprite contantly
	animateSprite( deltaTime );
}

void AnimatedGameSprite::animateSprite( float& deltaTime )
{
	// Calculate frame time 
	m_frameTime += deltaTime * m_animationFrameRate;

	// Apply frame time to current frame
	m_currentFrame = static_cast<int>( m_frameTime );
	m_currentFrame %= m_numberOfFrames;

	// Update the texture rect to new current frame
	calculateAnimationFrame();
}

bool AnimatedGameSprite::animateOnce( float& deltaTime )
{
	
	

		// Animate sprite 
		animateSprite(  deltaTime );
		// Check if it has animated once 
		if ( m_currentFrame == m_numberOfFrames-1 )
		{
			// Reset animation for next function call 
			m_currentFrame = 0;
			m_frameTime = 0;
			return false;
		}
		else
		{
			// If animating still return true 
			return true;
		}
}


