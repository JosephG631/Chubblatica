#ifndef OBJECTMANAGER_H
#define	OBJECTMANAGER_H


#include <SFML/Graphics/RenderWindow.hpp>

#include "Bullet.h"

//-----------------------------------------------
//class			: ObjectManager
// Purpose		: To Manage difference object pools 
// Usage		:	
//					ObjectManager()
//					ObjectManager( const  sf::Texture& bulletTexture )
//					~ObjectManager()
//					void shoot( const sf::Vector2f& firePos, const bool& playerFred, const sf::Vector2f& direction )
//					void update( float& deltaTime )
//					Bullet* getBullet()
//					void renderBullets( sf::RenderWindow* pWindow )
//					void setAllBullets( bool active )
// See also	: 
//-----------------------------------------------
class ObjectManager
{
private:
	Bullet*				 m_bullet;			// To act as an array of bullets 
	sf::Texture			 m_bulletTexture;	// Store bullets texture 
	
public:
	//-----------------------------------------------
	// Function		: ObjectManager
	// Purpose		: default class constructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	ObjectManager();
	//-----------------------------------------------
	// Function		: ObjectManager
	// Purpose		:  used when passing a texture using manager 
	// Parameters	: const  sf::Texture& bulletTexture
	// Returns		: void
	// Notes		: N/A
	// See also		: N/A
	//-----------------------------------------------
	ObjectManager( const  sf::Texture& bulletTexture );
	//-----------------------------------------------
	// Function		: ~ObjectManager
	// Purpose		: default class deconstructor
	// Parameters	: N/A
	// Returns		: void
	// Notes		: Don't call
	// See also		: N/A
	//-----------------------------------------------
	~ObjectManager();
	//-----------------------------------------------
	// Function		: shoot
	// Purpose		: used to access pool and set bullet for shooting 
	// Parameters	: const sf::Vector2f& firePos,const bool& playerFred,const sf::Vector2f& direction,  const float& shootRotation
	// Returns		: void
	// Notes		: N/A
	// See also		: bullet.update
	//-----------------------------------------------
	void shoot( const sf::Vector2f& firePos,const bool& playerFred,const sf::Vector2f& direction, const float& shootRotation );
	//-----------------------------------------------
	// Function		: update
	// Purpose		: used to update the pools
	// Parameters	: float& deltaTime
	// Returns		: void
	// Notes		: N/A
	// See also		: bullet.update
	//-----------------------------------------------
	void update( float& deltaTime );
	//-----------------------------------------------
	// Function		:getBullet
	// Purpose		: return the array of bullets
	// Parameters	:n/a
	// Returns		: m_bullet
	// Notes		: N/A
	// See also		: game.render
	//-----------------------------------------------
	 Bullet* getBullet() ;
	 //-----------------------------------------------
	// Function		: renderBullets
	// Purpose		: to render all the bullets 
	// Parameters	: pWindow
	// Returns		: m_bullet
	// Notes		: N/A
	// See also		: game.render
	//-----------------------------------------------
	 void renderBullets( sf::RenderWindow* pWindow );
	 //-----------------------------------------------
	// Function		: setAllBullets
	// Purpose		: set all  bullets states 
	// Parameters	: bool active
	// Returns		: void
	// Notes		: N/A
	// See also		: 
	//-----------------------------------------------
	 void setAllBullets( bool active );
};



#endif // !OBJECTMANAGER_H

