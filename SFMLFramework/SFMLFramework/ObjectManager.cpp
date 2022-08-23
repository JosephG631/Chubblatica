#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "Helpers.h"
#include "ObjectManager.h"
#include "Settings.h"

ObjectManager::ObjectManager()
{
	// Cretae bullets for object pool
	m_bullet = new Bullet[Settings::k_amountOfBullets];

	// load bullet texture
	m_bulletTexture.loadFromFile( "bullet.png" );

	// Loop through and set texture
	for ( int i = 0; i < Settings::k_amountOfBullets; i++ )
	{
		// Set bullet texture 
		m_bullet[i].setTexture( m_bulletTexture );
		m_bullet[i].setOriginToCenter( m_bulletTexture );
	}
}
ObjectManager::ObjectManager(const sf::Texture& bulletTexture)
	: m_bulletTexture	( bulletTexture )
{
	// Cretae bullets for object pool
	m_bullet = new Bullet[Settings::k_amountOfBullets];

	// Loop through and set texture
	for ( int i = 0; i < Settings::k_amountOfBullets; i++ )
	{
		// Set bullet texture 
		m_bullet[i].setTexture( m_bulletTexture );
		m_bullet[i].setOriginToCenter( m_bulletTexture );
	}
	
}

ObjectManager::~ObjectManager()
{
	// Delete array
	safeDelete( m_bullet );
}

void ObjectManager::shoot( const sf::Vector2f& firePos,const  bool& playerFired ,const sf::Vector2f& direction,  const float& shootRotation)
{
	
		// Loop through the bullets to check if they are active 
		for ( int i = 0; i < Settings::k_amountOfBullets; i++ )
		{
			if ( m_bullet[i].getActiveState() == false )
			{
				// If current bullet not active set active 
				m_bullet[i].setActiveState( true );

				// Set up bullet ready to be fired 
				m_bullet[i].setPosition( firePos );
				m_bullet[i].setDirection( direction );

				m_bullet[i].setPlayerFired( playerFired );
				// Depending who fired set up rotation 
				m_bullet[i].setRotation( shootRotation );

				// Get out of loop as bullet has been taken from pool. 
				break;
				
			}
		}
	
	
	
}

void ObjectManager::update(float& deltaTime)
{
	
  // Loop through bullets and update active ones. 
  for ( int i = 0; i < Settings::k_amountOfBullets; i++ )
  {
	  if(m_bullet[i].getActiveState() == true )
	  {
		 m_bullet[i].update( deltaTime );
	  }
  }
}

 Bullet* ObjectManager::getBullet( ) 
{
	return m_bullet;
}

 void ObjectManager::renderBullets( sf::RenderWindow* pWindow )
 {
	 for ( int i = 0; i < Settings::k_amountOfBullets;i++ )
	 {
		 // Render all active bullets 
		 if ( m_bullet[i].getActiveState() == true )
		 {
			 pWindow->draw( m_bullet[i] );

		 }
	 }
 }

 void ObjectManager::setAllBullets( bool active )
 {
	 for ( int i = 0; i < Settings::k_amountOfBullets;i++ )
	 {
		 // Sett every bullet state 
		 m_bullet[i].setActiveState( active);
	 }
 }





