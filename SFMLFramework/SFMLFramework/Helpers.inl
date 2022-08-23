#include <cmath>

#include "Helpers.h"

namespace  Math
{
	inline sf::Vector2f normalize( const sf::Vector2f& vector )
	{
		// Work out magnitude of vector (normalize value) 
		float magnitude = sqrt( ( vector.x * vector.x ) + ( vector.y * vector.y ) );

		// If needs to be normalized 
		if ( magnitude != 0 )
		{

			// Work out normalized x & y 
			// Return new normalized value 
			return sf::Vector2f( vector.x / magnitude, vector.y / magnitude );
		}
		else
		{
			// Vector did not need changing 
			return vector;
		}
	}



	inline sf::Vector2f bezierCurve( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t )
	{
		// Clamp Value
		t = clamp( t );
		float a = 1.00f - t;
		
		// Cubic bezier curve formula. Gets the point along the curve when you apply t. Each four points are used to create the shape of the curve. 
		return( a*a*a) * p0 + 3 * t * (a*a) * p1 + 3 * ( 1 - t ) * ( t * t ) * p2 + (t*t*t) * p3;
	}

	inline sf::Vector2f bezierDerivative( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, float t )
	{

		// Clamp Value
		t = clamp( t );

		// Value to pow
		float a = 1.00f - t;

		// Work out derivative and return it
		return ( 3 * ( a* a )) * ( p1 - p0 ) + 6.00f * ( 1.00f - t ) * t * ( p2 - p1 ) + 3 * ( t * t ) * ( p3 - p2 );
	}

	inline float bezierCurveLength( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3 )
	{
		// Work out the length between point 3 & 0
		float chordLength = distanceBetweenVectors( p3, p0 );

		// Work out the distance between the control points of the curve 
		float  controlNet = distanceBetweenVectors( p0, p1 ) + distanceBetweenVectors( p2, p1 ) + distanceBetweenVectors( p3, p2 );

		// Estimated length of the curve. You cannot work out the exact length without it being very exspenive. 
		float arcLength = ( controlNet + chordLength ) * 0.5F;

		return arcLength;
	}

	inline float distanceBetweenVectors( const sf::Vector2f& p0, const sf::Vector2f& p1 )
	{
		// pythagoras 
		float a = p1.x - p0.x;
		float b = p0.y - p1.y;

		// return squre root of c
		return sqrtf( ( a * a ) + ( b * b ) );
	}
	inline sf::Vector2f lerp( const sf::Vector2f& a, const sf::Vector2f& b, float t )
	{
		
		t = clamp( t );
		// Lerp
		return a + t *( b - a );
	}
	inline const float clamp( float& t )
	{
		if ( t > 1.0f )
		{
			// Clamp t so it can't go above one
			t = 1.0f;
		}
		return t;
	}
}
