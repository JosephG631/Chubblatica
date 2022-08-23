#ifndef ALIENSTATUS_h
#define	ALIENSTATUS_h
//-----------------------------------------------
// enum class	: AlienStatus
// Purpose		: enums for the state of the alien
// states		:	
//				FlyIn,
//				Formation,
//				Dive,
//				Dead,
//				Idle 
//-----------------------------------------------
enum class AlienStatus
{
	FlyIn,			// When aliens fly into the game
	Formation,		// Alien is in its formation
	Dive,			// when alien is diving
	Dead,			//	Alien is no longer alive
	Idle			//  When alien is not in the game 

};
#endif // !ALIENSTATUS.H

