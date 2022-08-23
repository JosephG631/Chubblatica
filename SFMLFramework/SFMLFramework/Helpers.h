#ifndef HELPERS_H
#define	HELPERS_H
#include <cassert>
#include <SFML/System/Vector2.hpp>
//-----------------------------------------------
//class			: Helpers
// Purpose		: Used for lots of useful global functions 
// Usage		:	
//					ASSERT(p)
//					template<typename T> void safeDelete( T*& p )
//					sf::Vector2f normalize( const sf::Vector2f& vector )
//					float bezierCurveLength( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3 )
//					float  distanceBetweenVectors( const sf::Vector2f& p0, const sf::Vector2f& p1 )
//					sf::Vector2f bezierCurve( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t )
//					sf::Vector2f bezierDerivative( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t )
//					sf::Vector2f lerp( const sf::Vector2f& a, const sf::Vector2f& b, float t )
//					const float clamp( float& t )
// See also	: Ship.h
//-----------------------------------------------

//-----------------------------------------------
// Macro		: ASSERT
// Purpose		: Check to see if the value is the correct value if not stop code.
// Parameters	:  a 
// Returns		:
// Notes		: Only runs in debug mode 
// See also		: 
//-----------------------------------------------
#ifdef _DEBUG
#define ASSERT(a) assert(a)
#else
#define ASSERT(a) 
#endif
//-----------------------------------------------
// Function		: safeDelete
// Purpose		: safely delete things when created on the heap to remove data leaks
// Parameters	: T*& p
// Returns		: void
// Notes		: N/A
// See also		: deconstructors 
//-----------------------------------------------
template<typename T>
void safeDelete( T*& p )
{
	if ( p )
	{
		delete[] p;
		p = nullptr;
	}
}

//-----------------------------------------------
//namespace		: Math
// Purpose		: hold useful math functions			
// See also	:
//-----------------------------------------------
namespace Math
{
	//-----------------------------------------------
	// Function		: normalize
	// Purpose		: normalize vectors 
	// Parameters	: ( const sf::Vector2f& vector )
	// Returns		: sf::Vector2f
	// Notes		: Mainly used to normalize direction for diaganol movement 
	// See also		: deconstructors 
	//-----------------------------------------------
	sf::Vector2f normalize( const sf::Vector2f& vector ); 
	//-----------------------------------------------
	// Function		: bezierCurveLength 
	// Purpose		: work out the length of the bezier curve used for movement 
	// Parameters	: const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3
	// Returns		: float length 
	// Notes		: Used for working out the speed when traveling across a curve.
	// See also		: alien.move
	//-----------------------------------------------
	float bezierCurveLength( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3 );
	//-----------------------------------------------
	// Function		: distanceBetweenVectors 
	// Purpose		: work out the distance between 2 points 
	// Parameters	: const sf::Vector2f& p0, const sf::Vector2f& p1
	// Returns		: float distance 
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	float  distanceBetweenVectors( const sf::Vector2f& p0, const sf::Vector2f& p1 );
	//-----------------------------------------------
	// Function		: sf::Vector2f bezierCurve
	// Purpose		: create a curve that a sprite can move along
	// Parameters	: const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t 
	// Returns		: sf::Vector2f point on the curve 
	// Notes		: 
	// See also		: float bezierCurveLength, alien.moveAlien
	//-----------------------------------------------
	sf::Vector2f bezierCurve( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t );
	//-----------------------------------------------
	// Function		: bezierDerivative  
	// Purpose		: work out the derivative of a bezier curve
	// Parameters	: const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t 
	// Returns		: sf::Vector2f bezierDerivative
	// Notes		: Mainly used for a look at points for rotataion while going round a curve
	// See also		: sf::Vector2f bezierCurve()
	//-----------------------------------------------
	sf::Vector2f bezierDerivative( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t );
	//-----------------------------------------------
	// Function		: lerp
	// Purpose		: move between two points 
	// Parameters	:  const sf::Vector2f& a, const sf::Vector2f& b, float t
	// Returns		: sf::Vector2f lerp
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	sf::Vector2f lerp( const sf::Vector2f& a, const sf::Vector2f& b, float t );
	//-----------------------------------------------
	// Function		: clamp
	// Purpose		: clamp the t value for math equations 
	// Parameters	:  float& t
	// Returns		: float t
	// Notes		: 
	// See also		: 
	//-----------------------------------------------
	const float clamp( float& t );
}
#include"Helpers.inl"
#endif // !HELPERS_H

